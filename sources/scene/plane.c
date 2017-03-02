/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:43:46 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 17:11:08 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane		*new_plane(t_vec3 normale, t_vec3 on_plane)
{
	t_plane		*p;

	if (!(p = malloc(sizeof(t_plane))))
		return (NULL);
	p->normale = normale;
	p->on_plane = on_plane;
	return (p);
}

BOOL		normal_plane(t_plane *plane, const t_ray ray, const float sol,
		t_hit *param)
{
	param->t = sol;
	param->pos = ray_point_at(ray, param->t);
	if (v3_dot_double_(ray.dir, plane->normale) < 0)
		param->normal = plane->normale;
	else
		param->normal = v3_scale_vec_(plane->normale, -1);
	v3_normalize(&param->normal);
	return (TRUE);
}

BOOL		hit_plane(void *obj, const t_ray ray, const double t[2],
			t_hit *param)
{
	t_plane			*plane;
	t_discriminant	d;

	plane = (t_plane*)obj;
	d.oc = v3_sub_vec_(ray.orig, plane->on_plane);
	if (v3_dot_double_(ray.dir, plane->normale))
	{
		d.sol = -1 * (v3_dot_double_(d.oc, plane->normale) /
		v3_dot_double_(ray.dir, plane->normale));
		if (d.sol > 0. && (d.sol < t[1] && d.sol > t[0]))
			return (normal_plane(plane, ray, d.sol, param));
	}
	return (FALSE);
}
