/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:35:08 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 19:05:31 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		button_addtriangle(void *param)
{
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("-- Adding a new triangle --\n");
		rt->parser.i_obj++;
		if (rt->parser.i_obj >= rt->parser.lim_obj)
		{
			rt->parser.lim_obj += 8;
			if ((rt->scene->obj = (t_obj*)realloc(rt->scene->obj,
				rt->parser.lim_obj * sizeof(t_obj))) == NULL)
				exit(-1);
		}
		rt->scene->obj[rt->parser.i_obj] = new_object(new_triangle(
		v3_(0., 0., 0.), v3_(1., 0., 0.), v3_(1., 0., 1.)), OBJ_TRIANGLE,
		new_material(v3_(1., 1., 1.), 0., NULL), MAT_LAMBERT);
		rt->scene->sizeof_obj = rt->parser.i_obj + 1;
		rt->scene->this_obj = &rt->scene->obj[rt->parser.i_obj];
		button_trianglepos1(param);
		button_trianglepos2(param);
		button_trianglepos3(param);
		re_render_win(rt);
	}
}

void		add_triangle(t_rt *rt, t_menu *m, int *i)
{
	settab2(i, WIN_RX - MENU_RX + 210, 540 + 55 + TILE_RY);
	m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(225, 535, 0, 0));
	m->rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(200, 520, 100, 100));
	set_imgparam(&rt->panel.imgparam, "image/Triangle.bmp");
	rt->panel.lst_button = lst_new_button(&rt->panel.lst_button,
		butnparam(
		lst_new_string(&m->nullstring, strparam("Triangle",
			rt->panel.word1, i, 0),
			rt->esdl->eng.render, esdl_render_blendedtext),
		lst_new_image(&m->nullsurf, surfparam(&m->rect, 0,
			&rt->panel.imgparam, 0), rt->esdl->eng.render, esdl_load_texture),
		&m->rect2, 0x10),
		rt->esdl->eng.render, actionparam((void*)rt, button_addtriangle));
}
