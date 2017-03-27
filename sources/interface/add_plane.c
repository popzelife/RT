/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:23:07 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 22:52:35 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		button_addplane(void *param)
{
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("-- Adding a new plane --\n");
		expand_obj_struct(rt);
		rt->this_scene->obj[rt->parser.i_obj] = new_object(new_plane(
		v3_(0., 1., 0.), v3_(0., 0., 0.), 0.), OBJ_PLANE, new_material(
		v3_(1., 1., 1.), 0., NULL), MAT_LAMBERT);
		rt->this_scene->this_obj = &rt->this_scene->obj[rt->parser.i_obj];
		button_planepos(param);
		button_planenormal(param);
		button_planeradius(param);
		re_render_win(rt);
	}
}

void		add_plane(t_rt *rt, t_menu *m, int *i)
{
	settab2(i, WIN_RX - MENU_RX + 28, 540 + 55 + TILE_RY);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(25, 535, 0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 520, 100, 100));
	set_imgparam(&rt->panel.imgparam, "image/Plane.bmp");
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("Plane",
			rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, 0x10),
		rt->esdl->eng.render, actionparam((void*)rt, button_addplane));
}
