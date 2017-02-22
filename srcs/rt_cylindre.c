/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylindre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhouide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:40:18 by nkhouide          #+#    #+#             */
/*   Updated: 2017/02/22 14:18:18 by nkhouide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cylindre	*new_cylindre(t_vec3 vertex, t_vec3	cp, const double radius)
{
	t_cylindre	*c;

	if (!(c = malloc(sizeof(t_cylindre))))
		return (0);
	c->vertex = vertex;
	c->cp = cp;
	c->radius = radius;
	return (c);
}

BOOL	normal_cylindre(t_cylindre *cylindre, const t_ray ray, const float sol,
		t_hit *param)
{
	param->t = sol;
	param->pos = ray_point_at(ray, param->t);
	param->normal = v3_scale_vec_(v3_sub_vec_(v3_sub_vec_(param->pos, cylindre->vertex),
	cylindre->cp), cylindre->m);
	return (TRUE);
}
BOOL	hit_cylindre(void *obj, const t_ray ray, const double t[2],
		t_hit *param)
{
	t_cylindre	*cylindre;
	t_vec3		oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sol;
//	double		sol2;
//	double		m;
//	double		maxm = 1.4;

	cylindre = (t_cylindre*)obj;
	oc = v3_sub_vec_(ray.orig, cylindre->cp);
	a = v3_dot_double_(ray.dir, ray.dir) - v3_dot_double_(ray.dir, cylindre->vertex)
			* v3_dot_double_(ray.dir, cylindre->vertex);
	b = 2 * (v3_dot_double_(ray.dir, oc)
			- v3_dot_double_(ray.dir, cylindre->vertex)
			* v3_dot_double_(oc, cylindre->vertex));
	c = v3_dot_double_(oc, oc) - v3_dot_double_(oc, cylindre->vertex)
			* v3_dot_double_(oc, cylindre->vertex)
			- cylindre->radius * cylindre->radius;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant >= 0)
	{
		sol = (-b - sqrt(discriminant)) / (2.0 * a);
		if (sol < t[1] && sol > t[0])
		{
			cylindre->m = (v3_dot_double_(ray.dir, v3_scale_vec_(cylindre->vertex, sol))
					+ v3_dot_double_(oc, cylindre->vertex));
		//	if (cylindre->m >= 0 && cylindre->m <= maxm)
				return (normal_cylindre(cylindre, ray, sol, param));
		}
		sol = (-b + sqrt(discriminant)) / (2.0 * a);
		if (sol < t[1] && sol > t[0])
		{
			cylindre->m = (v3_dot_double_(ray.dir, v3_scale_vec_(cylindre->vertex, sol))
					+ v3_dot_double_(oc, cylindre->vertex));
		//	if (cylindre->m >= 0 && cylindre->m <= maxm)
				return (normal_cylindre(cylindre, ray, sol, param));
		}
	}
	return (FALSE);
}
