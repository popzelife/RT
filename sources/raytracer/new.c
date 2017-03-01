/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:38:18 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/01 20:05:14 by qfremeau         ###   ########.fr       */
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

void			multisampling(t_tharg *arg, t_render *r)
{
	register int	x;
	register int	y;

	y = *(arg->j);
	while (y < *(arg->j) + RT_SUBXY && y < arg->rt->r_view->h * MSAMP)
	{
		x = *(arg->i);
		while (x < *(arg->i) + RT_SUBXY && x < arg->rt->r_view->w * MSAMP)
		{
			if (x % MSAMP != 0 && y % MSAMP != 0)
			{
				r->tmp = v3_multisampling_x2(arg->tab[x][y], arg->tab[x - 1][y],
				arg->tab[x][y - 1], arg->tab[x - 1][y - 1]);
				r->tmp = v3_(sqrt(r->tmp.x / *(arg->s)), sqrt(r->tmp.y / *(arg->s)),
				sqrt(r->tmp.z / *(arg->s)));
				esdl_put_pixel(arg->rt->s_view, x / 2, y / 2,
				esdl_color_to_int(vec3_to_sdlcolor(r->tmp)));
			}
			if (x == *(arg->i) || x == *(arg->i) + RT_SUBXY - 2 ||
				y == *(arg->j) || y == *(arg->j) + RT_SUBXY - 2)
				esdl_put_pixel(arg->rt->s_process, x / 2, y / 2, 0xff0055ff);
			++x;
		}
		++y;
	}
}

void			render_lowres(t_tharg *arg, t_render *r)
{
	r->y = *(arg->j);
	while (r->y < *(arg->j) + RT_SUBXY && r->y < arg->rt->r_view->h * MSAMP)
	{
		r->x = *(arg->i);
		while (r->x < *(arg->i) + RT_SUBXY && r->x < arg->rt->r_view->w * MSAMP &&
			r->y % 2 == 0)
		{
			if ((r->x == *(arg->i) && r->y == *(arg->j)) ||
				(r->x == *(arg->i) && r->y == *(arg->j) + RT_SUBXY / 2))
			{
				r->u = (double)r->x / arg->rt->r_view->w / MSAMP;
				r->v = (double)r->y / arg->rt->r_view->h / MSAMP;
				r->tmp = rt_color(ray_from_cam(arg->scene->cam, r->u, r->v),
				arg->scene, 0, 1);
				r->tmp = v3_(sqrt(r->tmp.x), sqrt(r->tmp.y), sqrt(r->tmp.z));
			}
			if (*(arg->s) == 0 && r->x % 2 == 0)
				esdl_put_pixel(arg->rt->s_view, r->x / 2, r->y / 2,
				esdl_color_to_int(vec3_to_sdlcolor(r->tmp)));
			++r->x;
		}
		++r->y;
	}
}

void			render_highres(t_tharg *arg, t_render *r)
{
	r->y = *(arg->j);
	while (r->y < *(arg->j) + RT_SUBXY && r->y < arg->rt->r_view->h * MSAMP)
	{
		r->x = *(arg->i);
		while (r->x < *(arg->i) + RT_SUBXY && r->x < arg->rt->r_view->w * MSAMP)
		{
			if (*(arg->s) <= ALIASING)
			{
				r->u = (double)r->x + f_rand() / arg->rt->r_view->w / MSAMP;
				r->v = (double)r->y + f_rand() / arg->rt->r_view->h / MSAMP;
				r->tmp = rt_color(ray_from_cam(arg->scene->cam, r->u, r->v),
				arg->scene, 0, MAX_DEPTH);
				if (*(arg->s) == 1)
					arg->tab[r->x][r->y] = r->tmp;
				else
					arg->tab[r->x][r->y] = v3_add_vec_(r->tmp, arg->tab[r->x][r->y]);
			}
			else
				return (end_thread(arg));
			++r->x;
		}
		++r->y;
	}
}
