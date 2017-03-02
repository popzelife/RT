/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_bkg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:33:05 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 21:15:40 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	prim_surface(t_rt *rt, t_menu *m)
{
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(27, 520, 0, 0));
	rt->panel.lst_surf = lst_new_image(&(rt->panel.lst_surf),
	surfparam(&m->rect, 0, &rt->panel.imgparam, 0), rt->esdl->eng.render,
	esdl_load_texture);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 + 27 * 2, 520, 0, 0));
	set_imgparam(&rt->panel.imgparam, IMG_ADDPLANE);
	rt->panel.lst_surf = lst_new_image(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0, &rt->panel.imgparam, 0), rt->esdl->eng.render,
	esdl_load_texture);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 * 2 + 27 * 3, 520, 0,
	0));
	set_imgparam(&rt->panel.imgparam, IMG_ADDSPHERE);
	rt->panel.lst_surf = lst_new_image(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0, &rt->panel.imgparam, 0), rt->esdl->eng.render,
	esdl_load_texture);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 750, MENU_RX, 30));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
}

void		draw_bkg_surface(t_rt *rt, t_menu *m)
{
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	rt->r_menu, 0xff373737, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 0, MENU_RX, 30));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(50, 50, 200, 200));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0, (void*)&rt->panel.viewparam, 0), rt->esdl->eng.render,
	rt_miniview_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 280, MENU_RX, 30));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff222222, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 480, MENU_RX, 30));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	prim_surface(rt, m);
}
