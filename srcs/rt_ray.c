/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popzelife <popzelife@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:54:12 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/17 11:41:05 by popzelife        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
