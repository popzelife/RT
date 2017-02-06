/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:37:08 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/07 22:01:42 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec4		v4(double const x, double const y, double const z, double const w)
{
	t_vec4	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}

t_vec4		*v4_new_vec(double const x, double const y, double const z,
			double const w)
{
	t_vec4	*vec;

	vec = malloc(sizeof(t_vec4));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = w;
	return (vec);
}

t_vec4		*v4_copy_vec(t_vec4 const v)
{
	return (v4_new_vec(v.x, v.y, v.z, v.w));
}

void		v4_set(t_vec4 *v, t_vec3 const xyz, double const w)
{
	v->x = xyz.x;
	v->y = xyz.y;
	v->z = xyz.z;
	v->w = w;
}

void		v4_free(t_vec4 *v)
{
	if (v)
		free(v);
}

double		v4_access(t_vec4 *v, int i)
{
	if (v)
	{
		if (i == 0)
			return (v->x);
		else if (i == 1)
			return (v->y);
		else if (i == 2)
			return (v->z);
		else if (i == 3)
			return (v->w);
	}
	return (.0);
}