/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:42:03 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/01 17:11:13 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double		v3_at(t_vec3 const *v, int const i)
{
	if (i == 0)
		return (v->x);
	else if (i == 1)
		return (v->y);
	else if (i == 2)
		return (v->z);
	return (.0);
}

void		v3_access(t_vec3 *v, int const i, double const f)
{
	if (i == 0)
		v->x = f;
	else if (i == 1)
		v->y = f;
	else if (i == 2)
		v->z = f;
}
