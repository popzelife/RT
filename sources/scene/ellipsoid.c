/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:58:15 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/13 15:03:08 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ellipsoid	*new_ellipsoid(t_vec3 center, t_vec3 vertex, double k, double radius)
{
	t_ellipsoid	*e;

	if(!(e = malloc(sizeof(t_ellipsoid))))
		return (0);
	v3_normalize(&vertex);
	e->vertex = vertex;
	e->center = center;
	e->k = k;
	e->radius = radius;
	e->radius2 = radius * radius;
	return (e);
}

BOOL	normal_ellipsoid(const t_ellipsoid *e, const t_ray ray, t_hit *param, double sol, double a, double b)
{
	t_vec3	cmid;
	t_vec3	R;
	t_vec3	tmp;

	param->t = sol;
	param->pos = ray_point_at(ray, param->t);
	cmid = v3_add_vec_(e->center, v3_scale_vec_(e->vertex, e->k / 2));
	R = v3_sub_vec_(param->pos, cmid);
	tmp = v3_scale_vec_(e->vertex, ((1 - (b * b)) / (a * a)));
	param->normal = v3_sub_vec_(R, v3_scale_vec_(tmp, v3_dot_double_(R, e->vertex)));
	v3_normalize(&param->normal);
	return (TRUE);
}

BOOL	hit_ellispoid(void *obj, const t_ray ray, const double t[2], t_hit *param)
{
	t_ellipsoid *e;
	t_vec3		oc;
	double		a;
	double		b;
	double		c;
	double		A1;
	double		A2;
	double		sol;
	double		discriminant;

	e = (t_ellipsoid*)obj;
	oc = v3_sub_vec_(ray.orig, e->center);
	A1 = 2 * e->k * (v3_dot_double_(ray.dir, e->vertex));
	A2 = e->radius2 + 2 * e->k * v3_dot_double_(oc, e->vertex) - e->k;
	a = 4 * e->radius2 * v3_dot_double_(ray.dir, ray.dir) - (A1 * A1);
	b = 2 * (4 * e->radius2 * v3_dot_double_(ray.dir, oc) - (A1 * A2));
	c = 4 * e->radius2 * v3_dot_double_(oc, oc) - (A2 * A2);
	discriminant = (b * b) - (4.0 * a * c);
	if (discriminant >= 0)
	{
		sol = (-b - sqrt(discriminant) / (2.0 * a));
		if (sol < t[1] && sol > t[0])
			return (normal_ellipsoid(e, ray, param, sol, a, b));
		sol = (-b + sqrt(discriminant) / (2.0 * a));
		if (sol < t[1] && sol > t[0])
			return (normal_ellipsoid(e, ray, param, sol, a, b));
	}
	return (FALSE);
}
