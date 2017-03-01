/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:33:00 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/01 18:18:43 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		*v3_unit_vec(t_vec3 const *v)
{
	return (v3_div_vec(v, v3_lenght_double(v)));
}

void		v3_normalize(t_vec3 *v)
{
	double	m;

	m = v3_magnitude_double(v);
	v->x /= m;
	v->y /= m;
	v->z /= m;
}
