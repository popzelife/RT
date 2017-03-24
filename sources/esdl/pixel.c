/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:10:16 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 20:27:15 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			esdl_put_pixel(SDL_Surface *surf, const int x, const int y,
				const int color)
{
	Uint32		*pixels;

	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
	{
		pixels = (Uint32 *)surf->pixels;
		pixels[y * surf->w + x] = color;
	}
}

Uint32			esdl_read_pixel(SDL_Surface *surf, const int x, const int y)
{
	Uint32		pixel;

	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
		pixel = (Uint32)(surf->pixels + y * surf->w + x);
	else
		pixel = 0;
	return (pixel);
}
