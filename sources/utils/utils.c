/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:31:00 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/01 14:53:14 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				*ft_tab2(const int x, const int y)
{
	int		*xy;

	xy = (int*)malloc(2 * sizeof(int));
	xy[0] = x;
	xy[1] = y;
	return (xy);
}

t_surfparam		surfparam(SDL_Rect *rect, int color, void *param, int i)
{
	t_surfparam		p;

	p.rect = rect;
	p.color = color;
	p.param = param;
	p.i_lst = i;
	return (p);
}

t_strparam		strparam(char *string, t_font font, int xy[2], int i)
{
	t_strparam		p;

	p.string = string;
	p.font = font;
	p.xy[0] = xy[0];
	p.xy[1] = xy[1];
	p.i_lst = i;
	return (p);
}

t_butnparam		butnparam(t_string *string, t_surface *surface, SDL_Rect *rect,
				int i)
{
	t_butnparam		p;

	p.string = string;
	p.surface = surface;
	p.rect = rect;
	p.i_lst = i;
	return (p);
}

t_camparam		camparam(double vfov, double aspect, double aperture,
				double focus)
{
	t_camparam		p;

	p.vfov = vfov;
	p.aspect = aspect;
	p.aperture = aperture;
	p.focus = focus;
	return (p);
}
