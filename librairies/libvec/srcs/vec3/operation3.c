/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _operation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:40:40 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/01 17:13:41 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		v3_add_vec_(t_vec3 const v1, t_vec3 const v2)
{
	return (v3_(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec3		v3_sub_vec_(t_vec3 const v1, t_vec3 const v2)
{
	return (v3_(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vec3		v3_cross_vec_(t_vec3 const v1, t_vec3 const v2)
{
	return (v3_(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
	v1.x * v2.y - v1.y * v2.x));
}

t_vec3		v3_multiply_vec_(t_vec3 const v1, t_vec3 const v2)
{
	return (v3_(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}
