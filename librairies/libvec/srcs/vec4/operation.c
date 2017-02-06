/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:37:25 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/07 22:01:37 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec4		*v4_add_vec(t_vec4 const v1, t_vec4 const v2)
{
	return (v4_new_vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w));
}

t_vec4		*v4_sub_vec(t_vec4 const v1, t_vec4 const v2)
{
	return (v4_new_vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w));
}

t_vec4		*v4_cross_vec(t_vec4 const v1, t_vec4 const v2)
{
	return (v4_new_vec(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
	v1.x * v2.y - v1.y * v2.x, v1.x * v2.y - v1.y * v2.x));
}

t_vec4		*v4_multiply_vec(t_vec4 const v1, t_vec4 const v2)
{
	return (v4_new_vec(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w));
}

t_vec4		*v4_scale_vec(t_vec4 const v, double const c)
{
	return (v4_new_vec(v.x * c, v.y * c, v.z * c, v.w * c));
}

t_vec4		*v4_div_vec(t_vec4 const v, double const c)
{
	return (v4_new_vec(v.x / c, v.y / c, v.z / c, v.w / c));
}