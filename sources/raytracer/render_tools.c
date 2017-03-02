/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:01:05 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/02 14:12:33 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		v3_multismp(t_vec3 c1, t_vec3 c2, t_vec3 c3, t_vec3 c4)
{
	return (v3_((c1.x + c2.x + c3.x + c4.x) / 4,
		(c1.y + c2.y + c3.y + c4.y) / 4, (c1.z + c2.z + c3.z + c4.z) / 4));
}

SDL_Color	vec3_to_sdlcolor(t_vec3 v)
{
	SDL_Color	c;

	c.r = (v.x * 255.0) > 255 ? 255 : v.x * 254.99;
	c.g = (v.y * 255.0) > 255 ? 255 : v.y * 254.99;
	c.b = (v.z * 255.0) > 255 ? 255 : v.z * 254.99;
	c.a = 255.0;
	return (c);
}

void		init_rt_color(t_vec3 *pos, t_vec3 *normal, double *t0, double *t1)
{
	*pos = v3_(0., 0., 0.);
	*normal = v3_(0., 0., 0.);
	*t0 = .001;
	*t1 = FLT_MAX;
}
