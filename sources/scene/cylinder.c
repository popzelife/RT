/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:15:56 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 20:20:28 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		discriminant_cylinder(t_cylinder *c, const t_ray ray,
				t_discriminant *d)
{
	d->a = v3_dot_double_(ray.dir, ray.dir) - v3_dot_double_(ray.dir,
	c->vertex) * v3_dot_double_(ray.dir, c->vertex);
	d->b = 2 * (v3_dot_double_(ray.dir, d->oc) - v3_dot_double_(ray.dir,
	c->vertex) * v3_dot_double_(d->oc, c->vertex));
	d->c = v3_dot_double_(d->oc, d->oc) - v3_dot_double_(d->oc, c->vertex) *
	v3_dot_double_(d->oc, c->vertex) - c->radius2;
	d->discriminant = (d->b * d->b) - (4 * d->a * d->c);
}

t_cylinder		*new_cylinder(t_vec3 vertex, t_vec3 cp, const double radius,
				const double height)
{
	t_cylinder	*c;

	if (!(c = malloc(sizeof(t_cylinder))))
		return (0);
	v3_normalize(&vertex);
	c->vertex = vertex;
	c->cp = cp;
	c->radius = radius;
	c->radius2 = radius * radius;
	c->height = height;
	return (c);
}

BOOL			normal_cylinder(const t_cylinder *cylinder, const t_ray ray,
				const t_discriminant d, t_hit *param)
{
	param->t = d.sol;
	param->pos = ray_point_at(ray, param->t);
	param->normal = v3_sub_vec_(v3_sub_vec_(param->pos, cylinder->cp),
	v3_scale_vec_(cylinder->vertex, d.m));
	v3_normalize(&param->normal);
	return (TRUE);
}

BOOL			hit_cylinder(void *obj, const t_ray ray, const double t[2],
				t_hit *param)
{
	t_cylinder		*c;
	t_discriminant	d;

	c = (t_cylinder*)obj;
	d.oc = v3_sub_vec_(ray.orig, c->cp);
	discriminant_cylinder(c, ray, &d);
	if (d.discriminant >= 0)
	{
		d.sol = (-(d.b) - sqrt(d.discriminant)) / (2.0 * d.a);
		if (d.sol < t[1] && d.sol > t[0])
		{
			d.m = v3_dot_double_(ray.dir, v3_scale_vec_(c->vertex, d.sol))
			+ v3_dot_double_(d.oc, c->vertex);
			return (normal_cylinder(c, ray, d, param));
		}
		d.sol = (-(d.b) + sqrt(d.discriminant)) / (2.0 * d.a);
		if (d.sol < t[1] && d.sol > t[0])
		{
			d.m = v3_dot_double_(ray.dir, v3_scale_vec_(c->vertex, d.sol))
			+ v3_dot_double_(d.oc, c->vertex);
			return (normal_cylinder(c, ray, d, param));
		}
	}
	return (FALSE);
}
