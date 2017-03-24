/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:18:43 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/21 17:57:50 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		v3_normalize_(t_vec3 v)
{
	double	m;

	m = v3_magnitude_double_(v);
	v.x /= m;
	v.y /= m;
	v.z /= m;
	return (v);
}

double		v3_magnitude_double_(t_vec3 const v)
{
	return (sqrt(v3_dot_double_(v, v)));
}

double		v3_dot_double_(t_vec3 const v1, t_vec3 const v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double		v3_length_double_(t_vec3 const v)
{
	return (sqrt(v3_dot_double_(v, v)));
}

t_vec3		v3_negative_(t_vec3 v)
{
	v.x *= -1.;
	v.y *= -1.;
	v.z *= -1.;
	return (v);
}
