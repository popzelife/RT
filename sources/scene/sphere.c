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

#include "rt.h"

t_sphere	*new_sphere(t_vec3 center, const double radius)
{
	t_sphere		*s;

	s = malloc(sizeof(t_sphere));
	s->center = center;
	s->radius = radius;
	s->radius2 = radius * radius;
	return (s);
}

BOOL		normal_sphere(t_sphere *sphere, const t_ray ray, const float sol,
			t_hit *param)
{
	param->t = sol;
	param->pos = ray_point_at(ray, param->t);
	param->normal = v3_div_vec_(v3_sub_vec_(param->pos, 
	sphere->center), sphere->radius);
	v3_normalize_(param->normal);
	return (TRUE);
}

BOOL		hit_sphere(void *obj, const t_ray ray, const double t[2],
			t_hit *param)
{
	t_sphere	*sphere;
	t_vec3		oc;
	double		a;
	double		b;
	double		discriminant;
	double		sol;

	sphere = (t_sphere*)obj;
	oc = v3_sub_vec_(ray.orig, sphere->center);
	a = v3_dot_double_(ray.dir, ray.dir);
	b = v3_dot_double_(oc, ray.dir);
	discriminant = b * b - a * (v3_dot_double_(oc, oc) - sphere->radius2);
	if (discriminant > 0)
	{
		sol = (-b - sqrt(discriminant)) / a;
		if (sol < t[1] && sol > t[0])
			return (normal_sphere(sphere, ray, sol, param));
		sol = (-b + sqrt(discriminant)) / a;
		if (sol < t[1] && sol > t[0])
			return (normal_sphere(sphere, ray, sol, param));
	}
	return (FALSE);
}


BOOL		bound_box_sphere(void *obj, t_bound_box *box, const double t0, \
	const double t1)
{
	t_sphere	*sphere;
	t_vec3		vmin;
	t_vec3		vmax;

	(void)t0;
	(void)t1;
	sphere = (t_sphere*)obj;
	vmin = v3_sub_vec_(sphere->center, v3_(sphere->radius, sphere->radius,
	sphere->radius));
	vmax = v3_add_vec_(sphere->center, v3_(sphere->radius, sphere->radius,
	sphere->radius));
	*box = new_bound_box(vmin, vmax);
	return (TRUE);
}
