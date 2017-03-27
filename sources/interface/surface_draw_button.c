/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_draw_button.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:48:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 13:49:20 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_button_render_surface(t_rt *rt, t_menu *m, int *i)
{
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
		&m->rect2, BTN_RENDER),
		rt->esdl->eng.render, actionparam((void*)rt, button_render));
	draw_button1(rt, m);
	draw_button2(rt, m);
}

void		draw_button_close_surface(t_rt *rt, t_menu *m, int *i)
{
	m->rect = esdl_rect(WIN_RX - 40, 0, 40, 40);
	set_imgparam(&rt->panel.imgparam, "image/Close.bmp");
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("",
			rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect, BTN_CLOSE),
		rt->esdl->eng.render, actionparam((void*)rt, button_close));
}

void		draw_button_minus_surface(t_rt *rt, t_menu *m, int *i)
{
	m->rect = esdl_rect(WIN_RX - 80, 0, 40, 40);
	set_imgparam(&rt->panel.imgparam, "image/Minus.bmp");
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("",
			rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect, BTN_MINUS),
		rt->esdl->eng.render, actionparam((void*)rt, button_minus));
}
