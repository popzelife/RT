/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:56:29 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/27 14:33:18 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		f_min(double const a, double const b)
{
	return (a < b ? a : b);
}

double		f_max(double const a, double const b)
{
	return (a > b ? a : b);
}

t_bound_box	new_bound_box(t_vec3 min, t_vec3 max)
{
	t_bound_box		b;

	b.min = min;
	b.max = max;
	return (b);
}

BOOL		hit_bound_box(t_bound_box *box, const t_ray ray, double t_min,
			double t_max)
{
	double		t0;
	double		t1;
	int			i;

	i = 0;
	while (i < 3)
	{
		t0 = f_min((v3_at_(box->min, i) - v3_at_(ray.orig, i)) / v3_at_(ray.dir,
		i), (v3_at_(box->max, i) - v3_at_(ray.orig, i)) / v3_at_(ray.dir, i));
		t1 = f_max((v3_at_(box->min, i) - v3_at_(ray.orig, i)) / v3_at_(ray.dir,
		i), (v3_at_(box->max, i) - v3_at_(ray.orig, i)) / v3_at_(ray.dir, i));
		t_min = f_min(t0, t_min);
		t_max = f_min(t1, t_max);
		if (t_max <= t_min)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/*
** Moving object from time0 to time1
*/

BOOL		surrounding_box(const t_bound_box box0, const t_bound_box box1)
{
	t_vec3		small;
	t_vec3		big;

	small = v3_(f_min(box0.min.x, box1.min.x),
		f_min(box0.min.y, box1.min.y),
		f_min(box0.min.z, box1.min.z));
	big = v3_(f_max(box0.max.x, box1.max.x),
		f_max(box0.max.y, box1.max.y),
		f_max(box0.max.z, box1.max.z));
	new_bound_box(small, big);
	return (TRUE);
}
