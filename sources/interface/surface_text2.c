/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_text2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:02:23 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 12:05:12 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		list_object_bis(t_rt *rt)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 5, 289 + 120 + TILE_RY);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_mat, rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 150 + TILE_RY);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_color, rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	free(i);
}

void		text_list_object(t_rt *rt)
{
	int		*i;

	i = ft_tab2(WIN_RX - MENU_RX + 5, 289 + TILE_RY);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_obj, rt->panel.sub_title1, i, 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 30 + TILE_RY);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_pos, rt->panel.word1, i, 0), rt->esdl->eng.render,
	esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 60 + TILE_RY);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_rotate, rt->panel.word1, i, 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	settab2(i, WIN_RX - MENU_RX + 5, 289 + 90 + TILE_RY);
	rt->panel.lst_string = lst_new_string(&(rt->panel.lst_string), strparam(
	rt->panel.viewparam.str_param_o, rt->panel.word1, i, 0),
	rt->esdl->eng.render, esdl_render_blendedtext);
	list_object_bis(rt);
	free(i);
}
