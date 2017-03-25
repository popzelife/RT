/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:55:56 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 17:30:30 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_triangle	*new_triangle(t_vec3 vertex, t_vec3 v2, t_vec3 v3)
{
	t_triangle		*t;

	if (!(t = malloc(sizeof(t_triangle))))
		return (NULL);
	t->vertex = vertex;
	t->v2 = v2;
	t->v3 = v3;
	t->e1 = v3_sub_vec_(v2, vertex);
	t->e2 = v3_sub_vec_(v3, vertex);
	t->normal = v3_cross_vec_(t->e1, t->e2);
	t->normal = v3_scale_vec_(t->normal, -1);
	return (t);
}

BOOL		normal_triangle(t_triangle *tri, const t_ray ray, t_hit *param,
			double t)
{
	{
		if (v3_dot_double_(ray.dir, tri->normal) < 0)
			param->normal = tri->normal;
		else
			param->normal = v3_scale_vec_(tri->normal, -1);
		param->t = t;
		param->pos = ray_point_at(ray, param->t);
		v3_normalize(&param->normal);
		return (TRUE);
	}
	return (FALSE);
}

BOOL		hit_triangle(void *obj, const t_ray ray, const double t[2],
			t_hit *param)
{
	t_triangle		*tri;
	t_triangle_var	var;

	tri = (t_triangle*)obj;
	var.p = v3_cross_vec_(ray.dir, tri->e2);
	var.det = v3_dot_double_(tri->e1, var.p);
	if (var.det < t[0] && var.det > t[1])
		return (FALSE);
	var.inv_det = 1.0 / var.det;
	var.ter = v3_sub_vec_(ray.orig, tri->vertex);
	var.u = v3_dot_double_(var.ter, var.p) * var.inv_det;
	if (var.u < 0.f || var.u > 1.f)
		return (FALSE);
	var.q = v3_cross_vec_(var.ter, tri->e1);
	var.v = v3_dot_double_(ray.dir, var.q) * var.inv_det;
	if (var.v < 0.f || var.u + var.v > 1.f)
		return (0);
	var.tbis = v3_dot_double_(tri->e2, var.q) * var.inv_det;
	if (var.tbis > t[0] && var.tbis < t[1])
		return (normal_triangle(tri, ray, param, var.tbis));
	return (FALSE);
}
