/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:37:39 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/07 22:01:36 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void		v4_negative(t_vec4 *v)
{
	v->x *= -1;
	v->y *= -1;
	v->z *= -1;
	v->w *= -1;
}

void		v4_normalize(t_vec4 *v)
{
	double	m;

	m = v4_magnitude_double(*v);
	v->x *= m;
	v->y *= m;
	v->z *= m;
	v->w *= m;
}

double		v4_dot_double(t_vec4 const v1, t_vec4 const v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

double		v4_magnitude_double(t_vec4 const v)
{
	return (1 / sqrt(v4_dot_double(v, v)));
}

double		v4_lenght_double(t_vec4 const v)
{
	return (sqrt(v4_dot_double(v, v)));
}