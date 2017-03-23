/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_button.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:26:31 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/22 22:48:48 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	draw_button1(t_rt *rt, t_menu *m)
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
		&m->rect2, 0),
	rt->esdl->eng.render, actionparam((void*)rt, button_snap));
	free(i);
}

static void	draw_button2(t_rt *rt, t_menu *m)
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
		&m->rect2, 0),
	rt->esdl->eng.render, actionparam((void*)rt, button_filter));
	free(i);
}

void		draw_button_surface(t_rt *rt, t_menu *m)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 20, 800 + 56 + TILE_RY);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(19, 785, 0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 780, 100, 100));
	set_imgparam(&rt->panel.imgparam, IMG_TOOLRENDER);
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("Render",
			rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, 0),
		rt->esdl->eng.render, actionparam((void*)rt, button_render));
	draw_button1(rt, m);
	draw_button2(rt, m);

	settab2(i, 0, 0);
	m->rect = esdl_rect(WIN_RX - 40, 0, 40, 40);
	set_imgparam(&rt->panel.imgparam, "image/Close.bmp");
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("",
			rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect, 0),
		rt->esdl->eng.render, actionparam((void*)rt, button_close));

	m->rect = esdl_rect(WIN_RX - 80, 0, 40, 40);
	set_imgparam(&rt->panel.imgparam, "image/Minus.bmp");
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("",
			rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect, 0),
		rt->esdl->eng.render, actionparam((void*)rt, button_minus));

	free(i);
}
