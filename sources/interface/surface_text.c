/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:21:37 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/10 01:14:01 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	text_add_prim(t_rt *rt)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 5, 487);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Primitives:", rt->panel.title1, i, 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 32, 530 + 64);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Cube", rt->panel.word1, i, 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 29 * 2 + 64, 530 + 64);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Plane", rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 27 * 3 + 64 * 2, 530 + 64);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Sphere", rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	free(i);
}

static void	list_object2(t_rt *rt)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 5, 289 + 120);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_color, rt->panel.word1, i, 6), rt->esdl->eng.render,
	esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 150);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_m, rt->panel.word1, i, 7),
	rt->esdl->eng.render, esdl_render_blendedtext);
	free(i);
}

void		text_list_object(t_rt *rt)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 5, 289);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_obj, rt->panel.sub_title1, i, 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 30);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_pos, rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 60);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_o, rt->panel.word1, i, 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 90);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_mat, rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 120);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_color, rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	free(i);
}

void		draw_text_list_object(t_rt *rt)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 5, 289);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_obj, rt->panel.sub_title1, i, 2),
	rt->esdl->eng.render, esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 30);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_pos, rt->panel.word1, i, 3), rt->esdl->eng.render,
	esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 60);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_o, rt->panel.word1, i, 4),
	rt->esdl->eng.render, esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 90);
	lst_set_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_mat, rt->panel.word1, i, 5), rt->esdl->eng.render,
	esdl_render_blendedtext);
	list_object2(rt);
	free(i);
}

void		draw_text_surface(t_rt *rt)
{
	int		*i;

	rt->panel.title1 = esdl_load_font(QUICKFONT, 22, 0x222222ff);
	rt->panel.sub_title1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
	rt->panel.word1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
	i = ft_tab2(WIN_RX - MENU_RX + 5, 7);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Object Setting:", rt->panel.title1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 220, 257);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"MiniRT", rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	text_list_object(rt);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 150);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_m, rt->panel.word1, i, 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	text_add_prim(rt);
	settab2(i, WIN_RX - MENU_RX + 5, 757);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	"Render Tools:", rt->panel.title1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	free(i);
}
