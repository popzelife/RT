/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:09:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 14:18:38 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		reflect(const t_vec3 v, const t_vec3 n)
{
	return (v3_sub_vec_(v, v3_scale_vec_(n, 2. * v3_dot_double_(v, n))));
}

BOOL		scatter_metal(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3		reflected;

	reflected = reflect(v3_unit_vec_(ray.dir), param.normal);
	*scattered = new_ray(param.pos, v3_add_vec_(reflected, v3_scale_vec_(
	random_in_unit_sphere(), param.material->t)));
	texture_it(param, attenuation);
	return ((v3_dot_double_(scattered->dir, param.normal) > 0) ? TRUE : FALSE);
}
