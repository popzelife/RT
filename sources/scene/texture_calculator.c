/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:44:51 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 20:46:31 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		texture_checkboard(t_vec3 pos, t_vec3 *attenuation)
{
	float	sines;

	sines = sin(10 * pos.x) * sin(10 * pos.y) * sin(10 * pos.z);
	if (sines < 0)
		*attenuation = v3_(0.1, 0.3, 0.1);
	else
		*attenuation = v3_(0.9, 0.9, 0.9);
}

void		texture_linex(t_vec3 pos, t_vec3 *attenuation)
{
	int		jump;

	jump = (int)pos.x % 2;
	if (jump == 0)
		*attenuation = v3_(0.1, 0.3, 0.1);
	else
		*attenuation = v3_(0.9, 0.9, 0.9);
}

void		texture_liney(t_vec3 pos, t_vec3 *attenuation)
{
	int		jump;

	jump = (int)pos.y % 2;
	if (jump == 0)
		*attenuation = v3_(0.1, 0.3, 0.1);
	else
		*attenuation = v3_(0.9, 0.9, 0.9);
}

void		texture_rainbow(t_vec3 pos, t_vec3 *attenuation)
{
	double	fractx;
	double	fracty;
	double	fractz;

	fractx = pos.x - floor(pos.x);
	fracty = pos.y - floor(pos.y);
	fractz = pos.z - floor(pos.z);
	*attenuation = v3_(1 - fabs(2.0 * fractx - 1), 1 - fabs(2.0 * fracty - 1),
			1 - fabs(2.0 * fractz - 1));
}
