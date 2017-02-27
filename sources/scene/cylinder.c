/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:15:56 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/27 11:31:46 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cylinder	*new_cylinder(t_vec3 vertex, t_vec3	cp, const double radius)
{
	t_cylinder	*c;

	if (!(c = malloc(sizeof(t_cylinder))))
		return (0);
	v3_normalize_(vertex);
	c->vertex = vertex;
	c->cp = cp;
	c->radius = radius;
	c->radius2 = radius * radius;
	return (c);
}

BOOL	normal_cylinder(t_cylinder *cylinder, const t_ray ray, const float sol,
		t_hit *param)
{
	param->t = sol;
	param->pos = ray_point_at(ray, param->t);
	param->normal = v3_sub_vec_(param->pos, 
			v3_sub_vec_(cylinder->cp , v3_scale_vec_(cylinder->vertex, cylinder->m)));
	v3_normalize_(param->normal);
	return (TRUE);
}
BOOL	hit_cylinder(void *obj, const t_ray ray, const double t[2],
		t_hit *param)
{
	t_cylinder	*cylinder;
	t_vec3		oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sol;
	double		maxm = 5.;

	cylinder = (t_cylinder*)obj;
	oc = v3_sub_vec_(ray.orig, cylinder->cp);
	a = v3_dot_double_(ray.dir, ray.dir) - v3_dot_double_(ray.dir, cylinder->vertex)
			* v3_dot_double_(ray.dir, cylinder->vertex);
	b = 2 * (v3_dot_double_(ray.dir, oc)
			- v3_dot_double_(ray.dir, cylinder->vertex)
			* v3_dot_double_(oc, cylinder->vertex));
	c = v3_dot_double_(oc, oc) - v3_dot_double_(oc, cylinder->vertex)
			* v3_dot_double_(oc, cylinder->vertex)
			- cylinder->radius2;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant >= 0)
	{
		sol = (-b - sqrt(discriminant)) / (2.0 * a);
		if (sol < t[1] && sol > t[0])
		{
			cylinder->m = (v3_dot_double_(ray.dir, v3_scale_vec_(cylinder->vertex, sol))
					+ v3_dot_double_(oc, cylinder->vertex));
			if (cylinder->m >= 0 && cylinder->m <= maxm)
				return (normal_cylinder(cylinder, ray, sol, param));
		}
		sol = (-b + sqrt(discriminant)) / (2.0 * a);
		if (sol < t[1] && sol > t[0])
		{
			cylinder->m = (v3_dot_double_(ray.dir, v3_scale_vec_(cylinder->vertex, sol))
					+ v3_dot_double_(oc, cylinder->vertex));
			if (cylinder->m >= 0 && cylinder->m <= maxm)
				return (normal_cylinder(cylinder, ray, sol, param));
		}
	}
	return (FALSE);
}
