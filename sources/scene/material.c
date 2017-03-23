/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:46:01 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/23 13:30:21 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mat		*new_material(t_vec3 albedo, double t, t_texture *text)
{
	t_mat		*m;

	m = malloc(sizeof(t_mat));
	m->albedo = albedo;
	m->t = t;
	m->m_text = text;
	return (m);
}

BOOL		scatter_none(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered)
{
	(void)ray;
	(void)param;
	(void)attenuation;
	(void)scattered;
	return (FALSE);
}
