/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:43:54 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/04 20:44:15 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*new_sphere(t_vec3 *center, const double radius)
{
	t_sphere		*s;

	s = malloc(sizeof(t_sphere));
	s->center = center;
	s->radius = radius;
	s->radius2 = radius * radius;
	return (s);
}

BOOL		bound_box_sphere(void *obj, t_bound_box *box, const double t0, \
	const double t1)
{
	t_sphere	*sphere;
	t_vec3		*vmin;
	t_vec3		*vmax;

	(void)t0;
	(void)t1;
	sphere = (t_sphere*)obj;
	vmin = v3_sub_vec(*(sphere->center), \
		v3(sphere->radius, sphere->radius, sphere->radius));
	vmax = v3_add_vec(*(sphere->center), \
		v3(sphere->radius, sphere->radius, sphere->radius));
	box = new_bound_box(vmin, vmax);
	return (TRUE);
}

BOOL		hit_sphere(void *obj, const t_ray *ray, const double t_min, \
	const double t_max, t_hit *param)
{
	t_sphere	*sphere;
	t_vec3		*oc;
	t_vec3		*v;
	t_vec3		*set;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		temp;

	sphere = (t_sphere*)obj;
	oc = v3_sub_vec(*(ray->orig), *(sphere->center));
	a = v3_dot_double(*(ray->dir), *(ray->dir));
	b = v3_dot_double(*oc, *(ray->dir));
	c = v3_dot_double(*oc, *oc) - sphere->radius2;

	discriminant = b * b - a * c;
	v3_free(oc);
	if (discriminant > 0)
	{

		temp = (-b - sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			param->t = temp;
			set = ray_point_at(ray, param->t);
			v3_set(param->pos, set->x, set->y, set->z);
			v3_free(set);
			v = v3_sub_vec(*(param->pos), *(sphere->center));
			set = v3_div_vec(*v, sphere->radius);
			v3_set(param->normal, set->x, set->y, set->z);
			v3_free(set);
			v3_free(v);
			return (TRUE);
		}

		temp = (-b + sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			param->t = temp;
			set = ray_point_at(ray, param->t);
			v3_set(param->pos, set->x, set->y, set->z);
			v3_free(set);
			v = v3_sub_vec(*(param->pos), *(sphere->center));
			set = v3_div_vec(*v, sphere->radius);
			v3_set(param->normal, set->x, set->y, set->z);
			v3_free(set);
			v3_free(v);
			return (TRUE);
		}
	}
	return (FALSE);
}
