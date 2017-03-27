/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_button.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:26:31 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 18:50:30 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_button1(t_rt *rt, t_menu *m)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 32 * 2 + 64, 800 + 56 + TILE_RY);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 + 27 * 2, 785, 0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(100, 780, 100, 100));
	set_imgparam(&rt->panel.imgparam, IMG_TOOLSAVE);
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
	butnparam(
		lst_new_string(&m->nullstring, strparam("Snap", rt->panel.word1,
			i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, BTN_SNAP),
	rt->esdl->eng.render, actionparam((void*)rt, button_snap));
	free(i);
}

void		draw_button2(t_rt *rt, t_menu *m)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 32 * 3 + 66 * 2, 800 + 56 + TILE_RY);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(66 * 2 + 29 * 3, 785,
	0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(200, 780, 100, 100));
	set_imgparam(&rt->panel.imgparam, IMG_TOOLPAINT);
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
	butnparam(
		lst_new_string(&m->nullstring, strparam("Filter", rt->panel.word1,
			i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, BTN_FILTER),
	rt->esdl->eng.render, actionparam((void*)rt, button_filter));
	free(i);
}

void		draw_button_surface(t_rt *rt, t_menu *m)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 20, 800 + 56 + TILE_RY);
	draw_button_render_surface(rt, m, i);
	settab2(i, 0, 0);
	draw_button_close_surface(rt, m, i);
	draw_button_minus_surface(rt, m, i);
	free(i);
}

void		buffer_button_param(t_rt *rt, t_menu *m)
{
	int		*i;

	i = ft_tab2(0, 0);
	draw_button_param1(rt, m, i);
	draw_button_param2(rt, m, i);
	draw_button_param3(rt, m, i);
	draw_button_param4(rt, m, i);
	draw_button_param5(rt, m, i);
	draw_button_param6(rt, m, i);
	add_plane(rt, m, i);
	add_cone(rt, m, i);
	add_cylinder(rt, m, i);
	add_triangle(rt, m, i);
	add_sphere(rt, m, i);
	free(i);
}
