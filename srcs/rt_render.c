/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:38:18 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/20 15:08:38 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
  All vectors should get a unit length #v3_normalize()
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
	param.material = new_material(v3_(0., 0., 0.), 0.);
	param.material->scatter = (void*)&scatter_none;
	param.material->emitted = v3_(0., 0., 0.);
	param.material->type_mat = MAT_NONE;
	attenuation = v3_(0., 0., 0.);
	scattered = new_ray(v3_(0., 0., 0.), v3_(0., 0., 0.));
	t[0] = .001;
	t[1] = FLT_MAX;
	if (hit_list(scene, ray, t, &param))
	{
		if ((depth < max_depth))// && (param.material->scatter(ray, param,
		//	&attenuation, &scattered)))
		{
			/*
			** Pick material as for now scatter func_ptr* doesn't work
			*/
			if (param.material->type_mat == MAT_METAL)
			{
				//scatter_metal(ray, param, attenuation, scattered);
				t_vec3		reflected;
				reflected = reflect(v3_unit_vec_(ray.dir), param.normal);
				scattered = new_ray(param.pos, v3_add_vec_(reflected,
				v3_scale_vec_(random_in_unit_sphere(), param.material->t)));
				attenuation = param.material->albedo;
				if (v3_dot_double_(scattered.dir, param.normal) <= 0)
				{
					return (param.material->emitted);
				}
			}
			else if (param.material->type_mat == MAT_LAMBERT)
			{
				//scatter_lambertian(ray, param, attenuation, scattered);
				t_vec3		target;
				target = v3_add_vec_(v3_add_vec_(param.pos, param.normal),
				random_in_unit_sphere());
				scattered = new_ray(param.pos, v3_sub_vec_(target, param.pos));
				attenuation = param.material->albedo;
			}
			else if (param.material->type_mat == MAT_DIFF_LIGHT)
			{
				//scatter_diff_light(ray, param, attenuation, scattered);
				return (param.material->emitted);
			}
			else
			{
				return (param.material->emitted);
			}
			return (v3_add_vec_(param.material->emitted, v3_multiply_vec_
			(attenuation, rt_color(scattered, scene, depth + 1, max_depth))));
		}
		else
			return (param.material->emitted);
	}
	else
		return (scene->this_skb->hit(scene->this_skb, ray));
	return (v3_(0., 0., 0.));
}

void			thread_render(t_tharg *arg)
{
	register int	x;
	register int	y;
	register double	u;
	register double	v;
	t_vec3			temp;

	y = *(arg->j);
	while (y < *(arg->j) + RT_SUBXY && y < arg->rt->r_view->h * MULTISAMP)
	{
		x = *(arg->i);
		while (x < *(arg->i) + RT_SUBXY && x < arg->rt->r_view->w * MULTISAMP)
		{
			if (*(arg->s) <= ALIASING)
			{
				u = (double)((double)x + (*(arg->s) == NO_ALIASING ? 0 : \
				f_random())) / (double)arg->rt->r_view->w / MULTISAMP;
				v = (double)((double)y + (*(arg->s) == NO_ALIASING ? 0 : \
				f_random())) / (double)arg->rt->r_view->h / MULTISAMP;
				temp = rt_color(ray_from_cam(arg->scene->cam, u, v), arg->scene,
				0, (*(arg->s) == -NO_ALIASING ? 1 : MAX_DEPTH));
				arg->tab[x][y] = v3_add_vec_(temp, arg->tab[x][y]);
			}
			else
			{
				printf("thread stop %40s\r", "");
				arg->rt->suspend = TRUE;
				return ;
			}
			++x;
		}
		++y;
	}

	/*
	** Multisampling and put pixel
	*/

	y = *(arg->j);
	while (y < *(arg->j) + RT_SUBXY && y < arg->rt->r_view->h * MULTISAMP)
	{
		x = *(arg->i);
		while (x < *(arg->i) + RT_SUBXY && x < arg->rt->r_view->w * MULTISAMP)
		{
			if (x % MULTISAMP != 0 && y % MULTISAMP != 0)
			{
				temp = v3_multisampling_x2(arg->tab[x][y], arg->tab[x - 1][y],
				arg->tab[x][y - 1], arg->tab[x - 1][y - 1]);
				temp = v3_(sqrt(temp.x / *(arg->s)), sqrt(temp.y / *(arg->s)),
				sqrt(temp.z / *(arg->s)));
				esdl_put_pixel(arg->rt->s_view, x / 2, y / 2, esdl_color_to_int
				(vec3_to_sdlcolor(temp)));
			}
			if (x == *(arg->i) || x == *(arg->i) + RT_SUBXY * 2 ||
				y == *(arg->j) || y == *(arg->j) + RT_SUBXY * 2)
				esdl_put_pixel(arg->rt->s_process, x / 2, y / 2, 0xff0055ff);
			++x;
		}
		++y;
	}

	/*
	** Set new pos x y;
	*/

	*(arg->i) += RT_SUBXY * arg->rt->m_thread;
	if (*(arg->i) > arg->rt->r_view->w  * MULTISAMP)
	{
		*(arg->i) -= arg->rt->r_view->w * MULTISAMP;
		*(arg->i) -= (*(arg->i) % RT_SUBXY);
		//*(arg->i) -= RT_SUBXY;
		*(arg->j) += RT_SUBXY;
	}
	if (*(arg->j) > arg->rt->r_view->h  * MULTISAMP)
	{
		++(*(arg->s));
		*(arg->j) -= arg->rt->r_view->h * MULTISAMP;
		*(arg->j) -= (*(arg->j) % RT_SUBXY);
		*(arg->j) -= RT_SUBXY;
	}
}
