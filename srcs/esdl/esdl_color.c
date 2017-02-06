/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:29:04 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/06 12:31:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Color	esdl_int_to_color(int color)
{
	SDL_Color				ret_color;

	ret_color.r = (color >> 24) & 0xFF;
	ret_color.g = (color >> 16) & 0xFF;
	ret_color.b = (color >> 8) & 0xFF;
	ret_color.a = (color) & 0xFF;
	return (ret_color);
}

int			esdl_color_to_int(SDL_Color color)
{
	int						ret_color;

	ret_color = 0;
	ret_color = (ret_color << 8) + color.a;
	ret_color = (ret_color << 8) + color.b;
	ret_color = (ret_color << 8) + color.g;
	ret_color = (ret_color << 8) + color.r;
	return (ret_color);
}

t_vec3		*v3_multisampling_x2(t_vec3 c1, t_vec3 c2, t_vec3 c3, t_vec3 c4)
{
	t_vec3		*ret;

	ret = v3_new_vec((c1.x + c2.x + c3.x + c4.x) / 4, \
		(c1.y + c2.y + c3.y + c4.y) / 4, \
		(c1.z + c2.z + c3.z + c4.z) / 4);
	return (ret);
}
