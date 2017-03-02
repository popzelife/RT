/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:33:42 by nkhouide          #+#    #+#             */
/*   Updated: 2017/03/02 20:21:21 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	const_cone(const t_vec3 dir, const t_vec3 vertex,
				const t_vec3 oc, double sol)
{
	double		ret;

	ret = v3_dot_double_(dir, v3_scale_vec_(vertex, sol)) +
	v3_dot_double_(oc, vertex);
	return (ret);
}

static void		discriminant_cone(t_cone *c, const t_ray ray, t_discriminant *d)
{
	d->a = v3_dot_double_(ray.dir, ray.dir) - (1 + c->tang * c->tang) *
	v3_dot_double_(ray.dir, c->vertex) * v3_dot_double_(ray.dir, c->vertex);
	d->b = 2 * (v3_dot_double_(ray.dir, d->oc) - (1 + c->tang * c->tang) *
	v3_dot_double_(ray.dir, c->vertex) * v3_dot_double_(d->oc, c->vertex));
	d->c = v3_dot_double_(d->oc, d->oc) - (1 + c->tang * c->tang) *
	v3_dot_double_(d->oc, c->vertex) * v3_dot_double_(d->oc, c->vertex);
	d->discriminant = (d->b * d->b) - (4 * d->a * d->c);
}

t_cone			*new_cone(t_vec3 vertex, t_vec3 cp, const double tang,
				const double height)
{
	t_cone		*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (0);
	v3_normalize(&vertex);
	cone->vertex = vertex;
	cone->cp = cp;
	cone->tang = tang;
	cone->height = -height;
	return (cone);
}

BOOL			normal_cone(const t_cone *cone, const t_ray ray,
				const t_discriminant d, t_hit *param)
{
	param->t = d.sol;
	param->pos = ray_point_at(ray, param->t);
	param->normal = v3_sub_vec_(v3_sub_vec_(param->pos, cone->cp),
	v3_scale_vec_(cone->vertex, (1 + (cone->tang * cone->tang)) * d.m));
	v3_normalize(&param->normal);
	return (TRUE);
}

BOOL			hit_cone(void *obj, const t_ray ray, const double t[2],
				t_hit *param)
{
	t_cone			*cone;
	t_discriminant	d;

	cone = (t_cone*)obj;
	d.oc = v3_sub_vec_(ray.orig, cone->cp);
	discriminant_cone(cone, ray, &d);
	if (d.discriminant >= 0)
	{
		d.sol = (-(d.b) - sqrt(d.discriminant)) / (2.0 * d.a);
		if (d.sol < t[1] && d.sol > t[0])
		{
			d.m = const_cone(ray.dir, cone->vertex, d.oc, d.sol);
			return (normal_cone(cone, ray, d, param));
		}
		d.sol = (-(d.b) + sqrt(d.discriminant)) / (2.0 * d.a);
		if (d.sol < t[1] && d.sol > t[0])
		{
			d.m = const_cone(ray.dir, cone->vertex, d.oc, d.sol);
			return (normal_cone(cone, ray, d, param));
		}
	}
	return (FALSE);
}
