/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:43:54 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 14:52:21 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere	*new_sphere(const t_vec3 center, const double radius)
{
	t_sphere		*s;

	s = (t_sphere*)malloc(sizeof(t_sphere));
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
	v3_normalize(&param->normal);
	return (TRUE);
}

BOOL		hit_sphere(void *obj, const t_ray ray, const double t[2],
			t_hit *param)
{
	t_sphere		*sphere;
	t_discriminant	d;

	sphere = (t_sphere*)obj;
	d.oc = v3_sub_vec_(ray.orig, sphere->center);
	d.a = v3_dot_double_(ray.dir, ray.dir);
	d.b = v3_dot_double_(d.oc, ray.dir);
	d.c = v3_dot_double_(d.oc, d.oc) - sphere->radius2;
	d.discriminant = d.b * d.b - d.a * d.c;
	if (d.discriminant > 0)
	{
		d.sol = (-(d.b) - sqrt(d.discriminant)) / d.a;
		if (d.sol < t[1] && d.sol > t[0])
			return (normal_sphere(sphere, ray, d.sol, param));
		d.sol = (-(d.b) + sqrt(d.discriminant)) / d.a;
		if (d.sol < t[1] && d.sol > t[0])
			return (normal_sphere(sphere, ray, d.sol, param));
	}
	return (FALSE);
}
