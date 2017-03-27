/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_draw_button_param2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:00:52 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 14:06:44 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_button_param6(t_rt *rt, t_menu *m, int *i)
{
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(105, 310 + 151,
	MENU_RX - 105, 29));
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("", rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_surface(&m->nullsurf, surfparam(&m->rect, 0x00000000, NULL, 0),
			rt->esdl->eng.render, esdl_clear_surface),
		&m->rect, BTN_PARAM6),
		rt->esdl->eng.render, actionparam(NULL, NULL));
	lst_active_button(&rt->panel.lst_button, BTN_PARAM6, FALSE);
}
