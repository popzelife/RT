/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:17:20 by popzelife         #+#    #+#             */
/*   Updated: 2017/03/27 21:31:29 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_param(t_rt *rt, t_menu *m)
{
	m->nullsurf = NULL;
	m->nullstring = NULL;
	rt->panel.lst_surf = NULL;
	rt->panel.lst_string = NULL;
	rt->panel.lst_button = NULL;
	rt->panel.viewparam = new_viewparam(rt->this_scene);
	rt->panel.imgparam = new_imgparam(IMG_ADDCUBE);
	rt->r_menu = malloc(sizeof(SDL_Rect));
	SDL_GetWindowSize(rt->win_temp, &(rt->r_menu->w), &(rt->r_menu->h));
	rt->r_menu->x = rt->r_menu->w - MENU_RX;
	rt->r_menu->y = TILE_RY;
	rt->r_menu->h -= TILE_RY;
	rt->panel.title1 = esdl_load_font(QUICKFONT, 22, 0x222222ff);
	rt->panel.sub_title1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
	rt->panel.word1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
}

void		draw_menu(t_rt *rt)
{
	t_menu			m;

	init_param(rt, &m);
	draw_bkg_surface(rt, &m);
	buffer_button_param(rt, &m);
	get_param_object(rt);
	get_param_material(rt);
	draw_text_surface(rt);
	draw_button_surface(rt, &m);
}

void		update_menu(t_rt *rt)
{
	SDL_GetWindowSize(rt->esdl->eng.win, &rt->r_menu->w, &rt->r_menu->h);
	rt->r_menu->x = rt->r_menu->w - MENU_RX;
	rt->r_menu->y = 0;
	set_imgparam(&rt->panel.imgparam, "image/Triangle.bmp");
	lst_set_surface(&(rt->panel.lst_surf), surfparam(NULL, 0,
	&rt->panel.viewparam, 2), rt->esdl->eng.render, rt_miniview_surface);
	get_param_object(rt);
	get_param_material(rt);
	draw_text_list_object(rt);
}
