/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:55:34 by popzelife         #+#    #+#             */
/*   Updated: 2017/02/17 18:54:44 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

BOOL		scatter_diffuse_light(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered)
{
	(void)ray;
	(void)param;
	(void)attenuation;
	(void)scattered;
	return (FALSE);
}
