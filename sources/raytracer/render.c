/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:38:18 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 22:41:51 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** All vectors should get a unit length #v3_normalize()
*/

BOOL			hit_list(t_scene *scene, const t_ray ray, const double t[2],
				t_hit *param)
{
	BOOL			hit_anything;
	double			closest_so_far[2];
	register int	i;

	i = 0;
	hit_anything = FALSE;
	closest_so_far[0] = t[0];
	closest_so_far[1] = t[1];
	while (i < scene->sizeof_obj)
	{
		if (scene->obj[i].hit(scene->obj[i].p_obj,
		ray, closest_so_far, param))
		{
			hit_anything = TRUE;
			closest_so_far[1] = param->t;
			param->material = scene->obj[i].p_mat;
			param->i_lst = i;
		}
		++i;
	}
	return (hit_anything);
}

t_vec3			rt_color(t_ray ray, t_scene *scene, int depth, int max_depth)
{
	t_hit		param;
	t_ray		scattered;
	t_vec3		attenuation;
	double		t[2];

	init_rt_color(&param.pos, &param.normal, &t[0], &t[1]);
	if (hit_list(scene, ray, t, &param))
	{
		if ((depth < max_depth))
		{
			if (param.material->type_mat == MAT_METAL)
				scatter_metal(ray, param, &attenuation, &scattered);
			else if (param.material->type_mat == MAT_LAMBERT)
				scatter_lambertian(ray, param, &attenuation, &scattered);
			else
				return (param.material->emitted);
			return (v3_add_vec_(param.material->emitted,
						v3_multiply_vec_(attenuation,
							rt_color(scattered, scene, depth + 1, max_depth))));
		}
		else
			return (param.material->emitted);
	}
	else
		return (scene->this_skb->hit(scene->this_skb, ray));
}

void			multisampling(t_tharg *a)
{
	t_render		r;

	r.y = *(a->j);
	while (r.y < *(a->j) + RT_SUBXY && r.y < a->rt->r_view->h * MSAMP)
	{
		r.x = *(a->i);
		while (r.x < *(a->i) + RT_SUBXY && r.x < a->rt->r_view->w * MSAMP)
		{
			if (r.x % MSAMP != 0 && r.y % MSAMP != 0)
			{
				r.tmp = v3_multismp(a->tab[r.x][r.y], a->tab[r.x - 1][r.y],
				a->tab[r.x][r.y - 1], a->tab[r.x - 1][r.y - 1]);
				r.tmp = v3_(sqrt(r.tmp.x / *(a->s)), sqrt(r.tmp.y / *
				(a->s)), sqrt(r.tmp.z / *(a->s)));
				esdl_put_pixel(a->rt->sr_view, r.x / 2, r.y / 2,
				esdl_color_to_int(vec3_to_sdlcolor(r.tmp)));
			}
			if (r.x == *(a->i) || r.x == *(a->i) + RT_SUBXY - 2 ||
				r.y == *(a->j) || r.y == *(a->j) + RT_SUBXY - 2)
				esdl_put_pixel(a->rt->s_process, r.x / 2, r.y / 2, CGRID);
			++(r.x);
		}
		++(r.y);
	}
}

void			render_lowres(t_tharg *a)
{
	t_render		r;

	r.y = *(a->j);
	while (r.y < *(a->j) + RT_SUBXY && r.y < a->rt->r_view->h * MSAMP)
	{
		r.x = *(a->i);
		while (r.x < *(a->i) + RT_SUBXY && r.x < a->rt->r_view->w * MSAMP
				&& r.y % 2 == 0)
		{
			if ((r.x == *(a->i) && r.y == *(a->j)) ||
				(r.x == *(a->i) && r.y == *(a->j) + RT_SUBXY / 2))
			{
				r.u = (double)((double)r.x / (double)a->rt->r_view->w / MSAMP);
				r.v = (double)((double)r.y / (double)a->rt->r_view->h / MSAMP);
				r.tmp = rt_color(ray_from_cam(a->scene->cam, r.u, r.v),
				a->scene, 0, 1);
				r.tmp = v3_(sqrt(r.tmp.x), sqrt(r.tmp.y), sqrt(r.tmp.z));
			}
			if (*(a->s) == 0 && r.x % 2 == 0)
				esdl_put_pixel(a->rt->sr_view, r.x / 2, r.y / 2,
				esdl_color_to_int(vec3_to_sdlcolor(r.tmp)));
			++(r.x);
		}
		++(r.y);
	}
}

void			render_highres(t_tharg *a)
{
	t_render		r;

	r.y = *(a->j);
	while (r.y < *(a->j) + RT_SUBXY && r.y < a->rt->r_view->h * MSAMP)
	{
		r.x = *(a->i);
		while (r.x < *(a->i) + RT_SUBXY && r.x < a->rt->r_view->w * MSAMP)
		{
			if (*(a->s) <= ALIASING)
			{
				r.u = (r.x + f_rand()) / a->rt->r_view->w / MSAMP;
				r.v = (r.y + f_rand()) / a->rt->r_view->h / MSAMP;
				r.tmp = rt_color(ray_from_cam(a->scene->cam, r.u, r.v),
				a->scene, 0, MAX_DEPTH);
				if (*(a->s) == 1)
					a->tab[r.x][r.y] = r.tmp;
				else
					a->tab[r.x][r.y] = v3_add_vec_(r.tmp, a->tab[r.x][r.y]);
			}
			else
				return (end_thread(a));
			++(r.x);
		}
		++(r.y);
	}
}
