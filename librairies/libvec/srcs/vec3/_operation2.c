/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _operation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:50:40 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/01 16:29:04 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		v3_scale_vec_(t_vec3 const v, double const c)
{
	return (v3_(v.x * c, v.y * c, v.z * c));
}

t_vec3		v3_div_vec_(t_vec3 const v, double const c)
{
	return (v3_(v.x / c, v.y / c, v.z / c));
}
