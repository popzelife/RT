/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:58:15 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 17:19:39 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ellipsoid	*new_ellipsoid(t_vec3 center, t_vec3 vertex, double k,
			double radius)
{
	t_ellipsoid	*e;

	if (!(e = malloc(sizeof(t_ellipsoid))))
		return (0);
	v3_normalize(&vertex);
	e->vertex = vertex;
	e->center = center;
	e->k = k;
	e->radius = radius;
	e->radius2 = radius * radius;
	return (e);
}

BOOL		normal_ellipsoid(const t_ellipsoid *e, const t_ray ray,
			t_hit *param, t_discriminant d)
{
	t_vec3		cmid;
	t_vec3		r;
	t_vec3		tmp;

	param->t = d.sol;
	param->pos = ray_point_at(ray, param->t);
	cmid = v3_add_vec_(e->center, v3_scale_vec_(e->vertex, e->k / 2));
	r = v3_sub_vec_(param->pos, cmid);
	tmp = v3_scale_vec_(e->vertex, ((1 - (d.b * d.b)) / (d.a * d.a)));
	param->normal = v3_sub_vec_(r, v3_scale_vec_(tmp, v3_dot_double_(r,
	e->vertex)));
	v3_normalize(&param->normal);
	return (TRUE);
}

BOOL		hit_ellispoid(void *obj, const t_ray ray, const double t[2],
			t_hit *param)
{
	t_discriminant	d;
	t_ellipsoid		*e;

	e = (t_ellipsoid*)obj;
	d.oc = v3_sub_vec_(ray.orig, e->center);
	d.a1 = 2 * e->k * (v3_dot_double_(ray.dir, e->vertex));
	d.a2 = e->radius2 + 2 * e->k * v3_dot_double_(d.oc, e->vertex) - e->k;
	d.a = 4 * e->radius2 * v3_dot_double_(ray.dir, ray.dir) - (d.a1 * d.a1);
	d.b = 2 * (4 * e->radius2 * v3_dot_double_(ray.dir, d.oc) - (d.a1 * d.a2));
	d.c = 4 * e->radius2 * v3_dot_double_(d.oc, d.oc) - (d.a2 * d.a2);
	d.discriminant = (d.b * d.b) - (4.0 * d.a * d.c);
	if (d.discriminant >= 0)
	{
		d.sol = (-d.b - sqrt(d.discriminant)) / (2.0 * d.a);
		if (d.sol < t[1] && d.sol > t[0])
			return (normal_ellipsoid(e, ray, param, d));
		d.sol = (-d.b + sqrt(d.discriminant)) / (2.0 * d.a);
		if (d.sol < t[1] && d.sol > t[0])
			return (normal_ellipsoid(e, ray, param, d));
	}
	return (FALSE);
}
