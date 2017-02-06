/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:48:35 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/24 17:52:45 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		*v3_scale_vec(t_vec3 const *v, double const c)
{
	return (v3_new_vec(v->x * c, v->y * c, v->z * c));
}

t_vec3		*v3_div_vec(t_vec3 const *v, double const c)
{
	return (v3_new_vec(v->x / c, v->y / c, v->z / c));
}
