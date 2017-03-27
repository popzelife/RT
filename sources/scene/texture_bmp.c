/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:56:15 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/06 14:55:29 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sphere_uv(const t_vec3 p, double *u, double *v)
{
	double	phi;
	double	theta;

	phi = atan2(p.x, p.z);
	theta = asin(p.y);
	*u = 1 - ((phi + M_PI) / (2 * M_PI));
	*v = (theta + (M_PI / 2)) / M_PI;
}

void	cylinder_uv(const t_vec3 p, double h, double *u, double *v)
{
	double	theta;

	theta = atan(p.x / p.y);
	*u = theta / (2 * M_PI);
	*v = p.z / h;
}

t_vec3	surface_value(SDL_Surface *data, double u, double v)
{
	t_textvalue	t;

	t.i = u * data->w;
	t.j = (1 - v) * data->h - 0.001;
	if (t.i < 0)
		t.i = 0;
	if (t.j < 0)
		t.j = 0;
	if (t.i > data->w - 1)
		t.i = data->w - 1;
	if (t.j > data->h - 1)
		t.j = data->h - 1;
	t.pixel = getpixel(data, t.i, t.j);
	SDL_GetRGB(t.pixel, data->format, &t.ri, &t.gi, &t.bi);
	t.r = t.ri / 255.0;
	t.g = t.gi / 255.0;
	t.b = t.bi / 255.0;
	return (v3_(t.r, t.g, t.b));
}
