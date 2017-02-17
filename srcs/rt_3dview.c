/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_3dview.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:01:12 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/17 14:24:08 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rt_3dview_surface(SDL_Surface *surf, const SDL_Rect *rect, \
	const int color, void *param)
{
	register int	x;
	register int	y;
	register int	s;
	register double	u;
	register double	v;
	t_ray			ray;
	t_vec3			ret;
	t_vec3			temp;
	SDL_Color		pixel;
	t_viewparam		*viewparam;

	(void)color;
	viewparam = (t_viewparam*)param;
	y = 0;
	while (y < rect->h)
	{
		x = 0;
		temp = v3(0.0, 0.0, 0.0);
		while (x < rect->w)
		{
			s = 0;
			while (s < 10)
			{
				u = ((double)x + f_random()) / (double)rect->w;
				v = ((double)y + f_random()) / (double)rect->h;
				ray = camera_ray(viewparam->scene->cam, u, v);
				ret = rt_color(ray, viewparam->scene, 0, 2);
				free_ray(ray);
				temp = v3(temp.x + ret->x, temp.y + ret->y, temp.z + ret->z);
				v3_free(ret);
				++s;
			}
			temp = v3(temp.x / 10, temp.y / 10, temp.z / 10);
			pixel = vec3_to_sdlcolor(temp);
			esdl_put_pixel(surf, x, y, esdl_color_to_int(pixel));
			++x;
		}
		++y;
	}
}
