/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:54:12 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/27 14:54:07 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray		new_ray(t_vec3 orig, t_vec3 dir)
{
	t_ray		r;

	r.orig = orig;
	r.dir = dir;
	return (r);
}

t_vec3		ray_point_at(const t_ray ray, const double point)
{
	return (v3_add_vec_(ray.orig, v3_scale_vec_(ray.dir, point)));
}

t_ray		ray_from_cam(t_cam *cam, double s, double t)
{
	t_vec3			radius;
	t_vec3			offset;
	t_vec3			dir;
	t_vec3			orig;

	radius = v3_scale_vec_(random_in_unit_disk(), cam->lens_radius);
	offset = v3_add_vec_(v3_scale_vec_(cam->u, radius.x), v3_scale_vec_(cam->v,
	radius.y));
	orig = v3_add_vec_(cam->origin, offset);
	dir = v3_sub_vec_(v3_sub_vec_(v3_add_vec_(v3_add_vec_(cam->low_left_corner,
	v3_scale_vec_(cam->horizontal, s)), v3_scale_vec_(cam->vertical, t)),
	cam->origin), offset);
	return (new_ray(orig, dir));
}
