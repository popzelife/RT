/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:09:25 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 11:48:18 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			render_scatter(t_ray ray, t_hit param, t_vec3 *attenuation,
			t_ray *scattered)
{
	if (param.material->type_mat == MAT_METAL)
		scatter_metal(ray, param, attenuation, scattered);
	else if (param.material->type_mat == MAT_LAMBERT)
		scatter_lambertian(ray, param, attenuation, scattered);
	else if (param.material->type_mat == MAT_DIELECT)
		scatter_dielectric(ray, param, attenuation, scattered);
	else
		return (0);
	return (1);
}
