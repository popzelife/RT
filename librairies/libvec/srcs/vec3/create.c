/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:06:11 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/01 18:16:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		*v3_new_vec(double const x, double const y, double const z)
{
	t_vec3		*vec;

	vec = (t_vec3 *)malloc(sizeof(t_vec3));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

int			v3_set(t_vec3 *v, double const x, double const y, double const z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	return (1);
}

int			v3_set_hex(t_vec3 *v, unsigned hex)
{
	v->x = ((hex >> 16) & 0xFF);
	v->y = ((hex >> 8) & 0xFF);
	v->z = ((hex) & 0xFF);
	return (1);
}

void		v3_free(t_vec3 *v)
{
	if (v)
		free(v);
}
