/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:33:08 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 17:26:01 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_parabloid	*new_paraboloid(t_vec3 vertex, t_vec3 center, double k)
{
	t_parabloid *p;

	if (!(p = malloc(sizeof(t_parabloid))))
		return (0);
	v3_normalize(&vertex);
	p->vertex = vertex;
	p->center = center;
	p->k = k;
	return (p);
}

BOOL		normal_paraboloid(const t_parabloid *p, const t_ray ray,
			t_hit *param, double sol)
{
	double	m;
	t_vec3	tmp;

	param->t = sol;
	param->pos = ray_point_at(ray, param->t);
	m = v3_dot_double_(v3_sub_vec_(param->pos, p->center), p->vertex);
	tmp = v3_scale_vec_(p->vertex, p->k + m);
	param->normal = v3_sub_vec_(param->pos, v3_sub_vec_(p->center, tmp));
	v3_normalize(&param->normal);
	return (TRUE);
}

BOOL		hit_parabloid(void *obj, const t_ray ray, const double t[2],
			t_hit *param)
{
	t_parabloid		*p;
	t_discriminant	d;

	p = (t_parabloid*)obj;
	d.oc = v3_sub_vec_(ray.orig, p->center);
	d.a = v3_dot_double_(ray.dir, ray.dir) - (v3_dot_double_(ray.dir, p->vertex)
	* v3_dot_double_(ray.dir, p->vertex));
	d.b = 2 * (v3_dot_double_(ray.dir, d.oc) - ((v3_dot_double_(ray.dir,
	p->vertex)) * ((v3_dot_double_(d.oc, p->vertex) + 2 * p->k))));
	d.c = v3_dot_double_(d.oc, d.oc) - ((v3_dot_double_(d.oc, p->vertex) *
	(v3_dot_double_(d.oc, p->vertex) + (4 * p->k))));
	d.discriminant = (d.b * d.b) - (4 * d.a * d.c);
	if (d.discriminant >= 0)
	{
		d.sol = ((-d.b - sqrt(d.discriminant)) / (2.0 * d.a));
		if (d.sol < t[1] && d.sol > t[0])
			return (normal_paraboloid(p, ray, param, d.sol));
		d.sol = ((-d.b + sqrt(d.discriminant)) / (2.0 * d.a));
		if (d.sol < t[1] && d.sol > t[0])
			return (normal_paraboloid(p, ray, param, d.sol));
	}
	return (FALSE);
}
