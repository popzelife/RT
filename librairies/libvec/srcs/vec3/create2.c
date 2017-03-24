/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _create.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:39:41 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/01 16:29:06 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		v3_(double const x, double const y, double const z)
{
	t_vec3		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec3		v3_copy_vec_(t_vec3 const v)
{
	return (v3_(v.x, v.y, v.z));
}
