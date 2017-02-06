/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:50 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/25 15:51:28 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		*v3_copy_vec(t_vec3 const *v)
{
	return (v3_new_vec(v->x, v->y, v->z));
}

int			v3_duplicate(t_vec3 *v1, t_vec3 const *v2)
{
	if (*v1 && *v2)
	{
		v1->x = v2->x;
		v1->y = v2->y;
		v1->z = v2->z;
		return (1);
	}
	return (0);
}
