/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:38:18 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/01 19:49:43 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** All vectors should get a unit length #v3_normalize()
*/

t_vec3		v3_multisampling_x2(t_vec3 c1, t_vec3 c2, t_vec3 c3, t_vec3 c4)
{
	return (v3_((c1.x + c2.x + c3.x + c4.x) / 4,
	(c1.y + c2.y + c3.y + c4.y) / 4, (c1.z + c2.z + c3.z + c4.z) / 4));
}


SDL_Color		vec3_to_sdlcolor(t_vec3 v)
{
	SDL_Color	c;

	c.r = (v.x * 255.0) > 255 ? 255 : v.x * 254.99;
	c.g = (v.y * 255.0) > 255 ? 255 : v.y * 254.99;
	c.b = (v.z * 255.0) > 255 ? 255 : v.z * 254.99;
	c.a = 255.0;
	return (c);
}

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
		ray, closest_so_far, param)) //&& scene->obj[i].active
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

	param.pos = v3_(0., 0., 0.);
	param.normal = v3_(0., 0., 0.);
	t[0] = .001;
	t[1] = FLT_MAX;
	if (hit_list(scene, ray, t, &param))
	{
		if ((depth < max_depth))// && (param.material->scatter(ray, param,
		//	&attenuation, &scattered)))
		{
			if (param.material->type_mat == MAT_METAL)
				scatter_metal(ray, param, &attenuation, &scattered);
			else if (param.material->type_mat == MAT_LAMBERT)
				scatter_lambertian(ray, param, &attenuation, &scattered);
			else //LIGHT!
				return (param.material->emitted);
			return (v3_add_vec_(param.material->emitted, v3_multiply_vec_
			(attenuation, rt_color(scattered, scene, depth + 1, max_depth))));
		}
		else
			return (param.material->emitted);
	}
	else
		return (scene->this_skb->hit(scene->this_skb, ray));
}

void	set_thread_pos(t_tharg *arg)
{
	*(arg->i) += RT_SUBXY * arg->rt->m_thread;
	if (*(arg->i) > arg->rt->r_view->w  * MSAMP)
	{
		*(arg->i) -= arg->rt->r_view->w * MSAMP;
		*(arg->i) -= (*(arg->i) % RT_SUBXY);
		*(arg->j) += RT_SUBXY;
	}
	if (*(arg->j) > arg->rt->r_view->h  * MSAMP)
	{
		++(*(arg->s));
		*(arg->j) -= arg->rt->r_view->h * MSAMP;
		*(arg->j) -= (*(arg->j) % RT_SUBXY);
		*(arg->j) -= RT_SUBXY;
	}
}

void			multisampling(t_tharg *arg)
{
	register int	x;
	register int	y;
	t_vec3			temp;
	
	y = *(arg->j);
	while (y < *(arg->j) + RT_SUBXY && y < arg->rt->r_view->h * MSAMP)
	{
		x = *(arg->i);
		while (x < *(arg->i) + RT_SUBXY && x < arg->rt->r_view->w * MSAMP)
		{
			if (x % MSAMP != 0 && y % MSAMP != 0)
			{
				temp = v3_multisampling_x2(arg->tab[x][y], arg->tab[x - 1][y],
				arg->tab[x][y - 1], arg->tab[x - 1][y - 1]);
				temp = v3_(sqrt(temp.x / *(arg->s)), sqrt(temp.y / *(arg->s)),
				sqrt(temp.z / *(arg->s)));
				esdl_put_pixel(arg->rt->s_view, x / 2, y / 2, esdl_color_to_int
				(vec3_to_sdlcolor(temp)));
			}
			if (x == *(arg->i) || x == *(arg->i) + RT_SUBXY - 2 ||
				y == *(arg->j) || y == *(arg->j) + RT_SUBXY - 2)
				esdl_put_pixel(arg->rt->s_process, x / 2, y / 2, 0xff0055ff);
			++x;
		}
		++y;
	}
}

void			render_lowres(t_tharg *arg)
{
	register int	x;
	register int	y;
	register double	u;
	register double	v;
	t_vec3			temp;

	y = *(arg->j);
	while (y < *(arg->j) + RT_SUBXY && y < arg->rt->r_view->h * MSAMP)
	{
		x = *(arg->i);
		while (x < *(arg->i) + RT_SUBXY && x < arg->rt->r_view->w * MSAMP &&
			y % 2 == 0)
		{
			if ((x == *(arg->i) && y == *(arg->j)) ||
				(x == *(arg->i) && y == *(arg->j) + RT_SUBXY / 2))
			{
				u = (double)(double)x / (double)arg->rt->r_view->w / MSAMP;
				v = (double)(double)y / (double)arg->rt->r_view->h / MSAMP;
				temp = rt_color(ray_from_cam(arg->scene->cam, u, v), arg->scene,
				0, 1);
				temp = v3_(sqrt(temp.x), sqrt(temp.y), sqrt(temp.z));
			}
			if (*(arg->s) == 0 && x % 2 == 0)
				esdl_put_pixel(arg->rt->s_view, x / 2, y / 2, esdl_color_to_int(
				vec3_to_sdlcolor(temp)));
			++x;
		}
		++y;
	}
}

void			render_highres(t_tharg *arg)
{
	register int	x;
	register int	y;
	register double	u;
	register double	v;
	t_vec3			temp;

	y = *(arg->j);
	while (y < *(arg->j) + RT_SUBXY && y < arg->rt->r_view->h * MSAMP)
	{
		x = *(arg->i);
		while (x < *(arg->i) + RT_SUBXY && x < arg->rt->r_view->w * MSAMP)
		{
			if (*(arg->s) <= ALIASING)
			{
				u = (double)((double)x + f_rand()) / (double)
				arg->rt->r_view->w / MSAMP;
				v = (double)((double)y + f_rand()) / (double)
				arg->rt->r_view->h / MSAMP;
				temp = rt_color(ray_from_cam(arg->scene->cam, u, v), arg->scene,
				0, MAX_DEPTH);
				if (*(arg->s) == 1)
					arg->tab[x][y] = temp;
				else
					arg->tab[x][y] = v3_add_vec_(temp, arg->tab[x][y]);
			}
			else
			{
				arg->rt->suspend = TRUE;
				return ;
			}
			++x;
		}
		++y;
	}
}

void			thread_render(t_tharg *arg)
{
	if (*(arg->s) == 0)
		render_lowres(arg);
	else
	{
		render_highres(arg);
		multisampling(arg);
	}
	set_thread_pos(arg);
	pthread_exit(NULL);
}

void			thread_render_low(t_tharg *arg)
{
	if (*(arg->s) == 0)
		render_lowres(arg);
	set_thread_pos(arg);
	pthread_exit(NULL);
}
