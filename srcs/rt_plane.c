/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:43:46 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/04 15:02:06 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane_xy	*new_plane_xy(const double x0, const double x1, double const y0, \
	double const y1, double const k)
{
	t_plane_xy		*p;

	p = malloc(sizeof(t_plane_xy));
	p->x0 = x0;
	p->x1 = x1;
	p->y0 = y0;
	p->y1 = y1;
	p->k = k;
	return (p);
}

BOOL		hit_plane_xy(void *obj, const t_ray *ray, const double t_min, \
	const double t_max, t_hit *param)
{
	t_plane_xy	*plane;
	double		t;
	double		x;
	double		y;
	t_vec3		*set;

	plane = (t_plane_xy*)obj;
	t = (plane->k - ray->orig->z) / ray->dir->z;
	if (t < t_min || t < t_max)
		return (FALSE);
	x = ray->orig->x + t * ray->dir->x;
	y = ray->orig->y + t * ray->dir->y;
	if (x < plane->x0 || x > plane->x1 || y < plane->y0 || y > plane->y1)
		return (FALSE);
	param->u = (x - plane->x0) / (plane->x1 - plane->x0);
	param->v = (y - plane->y0) / (plane->y1 - plane->y0);
	param->t = t;
	set = ray_point_at(ray, param->t);
	v3_set(param->pos, set->x, set->y, set->z);
	v3_free(set);
	v3_set(param->normal, 0, 0, 1);
	return (TRUE);
}
