/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:34:57 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 22:52:50 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		button_addcone(void *param)
{
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("-- Adding a new cone --\n");
		expand_obj_struct(rt);
		rt->this_scene->obj[rt->parser.i_obj] = new_object(new_cone(
		v3_(0., 1., 0.), v3_(0., 0., 0.), 1., 1.), OBJ_CONE, new_material(
		v3_(1., 1., 1.), 0., NULL), MAT_LAMBERT);
		rt->this_scene->this_obj = &rt->this_scene->obj[rt->parser.i_obj];
		button_conepos(param);
		button_conenormal(param);
		button_coneheight(param);
		re_render_win(rt);
	}
}

void		add_cone(t_rt *rt, t_menu *m, int *i)
{
	settab2(i, WIN_RX - MENU_RX + 76, 640 + 55 + TILE_RY);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(75, 635, 0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(50, 620, 100, 100));
	set_imgparam(&rt->panel.imgparam, "image/Cone.bmp");
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("Cone",
			rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, 0x10),
		rt->esdl->eng.render, actionparam((void*)rt, button_addcone));
}
