/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniview.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:01:12 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/08 18:34:09 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rt_miniview_surface(SDL_Surface *surf, const SDL_Rect *rect,
			const int color, void *param)
{
	t_render		t;
	t_viewparam		*rt;

	(void)color;
	rt = (t_viewparam*)param;
	t.y = 0;
	while (t.y < rect->h)
	{
		t.x = 0;
		while (t.x < rect->w)
		{
			t.s = 0;
			while ((t.s)++ < 10)
			{
				t.u = ((double)t.x + f_rand()) / (double)rect->w;
				t.v = ((double)t.y + f_rand()) / (double)rect->h;
				t.tmp = v3_add_vec_(rt_color(ray_from_cam(rt->scene.cam,
				t.u, t.v), &rt->scene, 0, 2), t.tmp);
			}
			t.tmp = v3_scale_vec_(t.tmp, .1);
			esdl_put_pixel(surf, (t.x)++, t.y, esdl_color_to_int(
			vec3_to_sdlcolor(t.tmp)));
		}
		++(t.y);
	}
}
