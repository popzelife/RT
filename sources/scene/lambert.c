/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:08:38 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/23 13:39:57 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

BOOL		scatter_lambertian(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3		target;

	(void)ray;
	target = v3_add_vec_(v3_add_vec_(param.pos, param.normal),
	random_in_unit_sphere());
	*scattered = new_ray(param.pos, v3_sub_vec_(target, param.pos));
	texture_it(param, attenuation);
	return (TRUE);
}
