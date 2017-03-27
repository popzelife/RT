/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_bkg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:33:05 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 17:24:41 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	prim_surface(t_rt *rt, t_menu *m)
{
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 750, MENU_RX, 30));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_rect(5, 0, 191, TILE_RY - 10);
	set_imgparam(&rt->panel.imgparam, "image/Title.bmp");
	rt->panel.lst_surf = lst_new_image(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0, &rt->panel.imgparam, 0), rt->esdl->eng.render,
	esdl_load_texture);
}

void		bkg_surface_bis(t_rt *rt, t_menu *m)
{
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 340, MENU_RX, 1));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff111111, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 370, MENU_RX, 1));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff111111, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 400, MENU_RX, 1));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff111111, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 430, MENU_RX, 1));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff111111, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 460, MENU_RX, 1));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff111111, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 490, MENU_RX, 30));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	prim_surface(rt, m);
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
	m->rect = esdl_rect(0, 0, WIN_RX, TILE_RY);
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff373737, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 280, MENU_RX, 30));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff242424, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(105, 310, MENU_RX - 105,
	180));
	rt->panel.lst_surf = lst_new_surface(&(rt->panel.lst_surf), surfparam(
	&m->rect, 0xff202020, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);
	bkg_surface_bis(rt, m);
}
