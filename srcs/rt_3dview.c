/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_3dview.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:01:12 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/20 16:51:55 by qfremeau         ###   ########.fr       */
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
	t_vec3			tp;
	t_viewparam		*rt;

	(void)color;
	rt = (t_viewparam*)param;
	y = 0;
	while (y < rect->h)
	{
		x = 0;
		tp = v3_(0., 0., 0.);
		while (x < rect->w)
		{
			s = 0;
			while (s < 10)
			{
				u = ((double)x + f_random()) / (double)rect->w;
				v = ((double)y + f_random()) / (double)rect->h;
				tp = v3_add_vec_(rt_color(ray_from_cam(rt->scene.cam, u, v),
				&rt->scene, 0, 2), tp);
				++s;
			}
			tp = v3_scale_vec_(tp, .1);
			esdl_put_pixel(surf, x, y, esdl_color_to_int(vec3_to_sdlcolor(tp)));
			++x;
		}
		++y;
	}
}
