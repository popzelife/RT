/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_object_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:52:22 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 19:03:39 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		triangle_param(t_rt *rt)
{
	t_triangle		*trian;

	trian = (t_triangle*)rt->panel.viewparam.scene.this_obj->p_obj;
	sprintf(rt->panel.viewparam.str_obj, "Cone Param:");
	sprintf(rt->panel.viewparam.str_pos, "Vertex 1: %5s[%.3g; %.3g; %.3g]", " ",
	trian->vertex.x, trian->vertex.y, trian->vertex.z);
	sprintf(rt->panel.viewparam.str_rotate, "Vertex 2: %4s[%.3g; %.3g; %.3g]",
	" ", trian->v2.x, trian->v2.y, trian->v2.z);
	sprintf(rt->panel.viewparam.str_param_o, "Vertex 3: %4s[%.3g; %.3g; %.3g]",
	" ", trian->v3.x, trian->v3.y, trian->v3.z);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM1, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM2, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
	lst_set_button(&rt->panel.lst_button, BTN_PARAM1,
	actionparam((void*)rt, button_trianglepos1));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM2,
	actionparam((void*)rt, button_trianglepos2));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM3,
	actionparam((void*)rt, button_trianglepos3));
}
