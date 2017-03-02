/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_button.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:26:31 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 21:55:42 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	draw_button1(t_rt *rt, t_menu *m)
{
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 + 27 * 2, 790, 0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(14 * 2 + 81, 790, 84,
	95));
	set_imgparam(&rt->panel.imgparam, IMG_TOOLSAVE);
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
	butnparam(
		lst_new_string(&m->nullstring, strparam("Snap", rt->panel.word1,
			ft_tab2(WIN_RX - MENU_RX + 32 * 2 + 64, 800 + 64), 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, 0),
	rt->esdl->eng.render, actionparam((void*)rt, button_snap));
}

static void	draw_button2(t_rt *rt, t_menu *m)
{
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 * 2 + 29 * 3, 790,
	0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(14 * 3 + 82 * 2, 790,
	80, 95));
	set_imgparam(&rt->panel.imgparam, IMG_TOOLPAINT);
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
	butnparam(
		lst_new_string(&m->nullstring, strparam("Paint", rt->panel.word1,
			ft_tab2(WIN_RX - MENU_RX + 32 * 3 + 64 * 2, 800 + 64), 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, 0),
	rt->esdl->eng.render, actionparam((void*)rt, button_render));
}

void		draw_button_surface(t_rt *rt, t_menu *m)
{
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(24, 790, 0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(15, 790, 82, 95));
	set_imgparam(&rt->panel.imgparam, IMG_TOOLRENDER);
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
	butnparam(
		lst_new_string(&m->nullstring, strparam("Render",
			rt->panel.word1, ft_tab2(WIN_RX - MENU_RX + 25, 800 + 64), 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, 0),
	rt->esdl->eng.render, actionparam((void*)rt, button_render));
	draw_button1(rt, m);
	draw_button2(rt, m);
}
