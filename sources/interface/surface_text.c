/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:21:37 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 21:56:02 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	text_add_prim(t_rt *rt)
{
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Primitives:", rt->panel.title1, ft_tab2(WIN_RX - MENU_RX + 5, 487), 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Cube", rt->panel.word1, ft_tab2(WIN_RX - MENU_RX + 32, 530 + 64), 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Plane", rt->panel.word1, ft_tab2(WIN_RX - MENU_RX + 29 * 2 + 64, 530 + 64),
	0), rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Sphere", rt->panel.word1, ft_tab2(WIN_RX - MENU_RX + 27 * 3 + 64 * 2, 530
	+ 64), 0), rt->esdl->eng.render, esdl_render_blendedtext);
}

void		text_list_object(t_rt *rt)
{
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_obj, rt->panel.sub_title1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289), 0), rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_pos, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 30), 0), rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_o, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 60), 0), rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_mat, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 90), 0), rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_color, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 120), 0), rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_m, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 150), 0), rt->esdl->eng.render, esdl_render_blendedtext);
}

void		draw_text_list_object(t_rt *rt)
{
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_obj, rt->panel.sub_title1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289), 2), rt->esdl->eng.render, esdl_render_blendedtext);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_pos, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 30), 3), rt->esdl->eng.render, esdl_render_blendedtext);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_o, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 60), 4), rt->esdl->eng.render, esdl_render_blendedtext);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_mat, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 90), 5), rt->esdl->eng.render, esdl_render_blendedtext);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_color, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 120), 6), rt->esdl->eng.render, esdl_render_blendedtext);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_m, rt->panel.word1, ft_tab2(WIN_RX -
	MENU_RX + 5, 289 + 150), 7), rt->esdl->eng.render, esdl_render_blendedtext);
}

void		draw_text_surface(t_rt *rt)
{
	rt->panel.title1 = esdl_load_font(QUICKFONT, 22, 0x222222ff);
	rt->panel.sub_title1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
	rt->panel.word1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Object Setting:", rt->panel.title1, ft_tab2(WIN_RX - MENU_RX + 5, 7), 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"2D view", rt->panel.word1, ft_tab2(WIN_RX - MENU_RX + 220, 257), 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	text_list_object(rt);
	text_add_prim(rt);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Render Tools:", rt->panel.title1, ft_tab2(WIN_RX - MENU_RX + 5, 757), 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
}
