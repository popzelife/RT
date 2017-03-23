/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:01:31 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/23 18:45:27 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	material_color(t_rt *rt)
{
	if (!rt->panel.viewparam.scene.this_obj->p_mat->m_text)
	{
		sprintf(rt->panel.viewparam.str_color, "Color: %10srgb(%.3g, %.3g,"
		"%.3g)", " ", rt->panel.viewparam.scene.this_obj->p_mat->albedo.x *
		249.9, rt->panel.viewparam.scene.this_obj->p_mat->albedo.y * 249.9,
		rt->panel.viewparam.scene.this_obj->p_mat->albedo.z * 249.9);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM4, TRUE);
	}
	else
	{
		lst_active_button(&rt->panel.lst_button, BTN_PARAM4, TRUE);
		if (rt->panel.viewparam.scene.this_obj->p_mat->m_text->type_texture ==
			TEXT_IMAGE)
			sprintf(rt->panel.viewparam.str_color, "Texture: %6s" "\"%10s\"",
			" ", rt->panel.viewparam.scene.this_obj->p_mat->m_text->filename);
		else if (rt->panel.viewparam.scene.this_obj->p_mat->m_text->type_texture
			== TEXT_CHCKBOARD)
			sprintf(rt->panel.viewparam.str_color, "Texture: %6s"
			"Checkboard", " ");
		else if (rt->panel.viewparam.scene.this_obj->p_mat->m_text->type_texture
			== TEXT_LINEY)
			sprintf(rt->panel.viewparam.str_color, "Texture: %6s"
			"Line Y", " ");
		else if (rt->panel.viewparam.scene.this_obj->p_mat->m_text->type_texture
			== TEXT_LINEX)
			sprintf(rt->panel.viewparam.str_color, "Texture: %6s"
			"Line X", " ");
		else if (rt->panel.viewparam.scene.this_obj->p_mat->m_text->type_texture
			== TEXT_RAINBOW)
			sprintf(rt->panel.viewparam.str_color, "Texture: %6s"
			"Rainbow", " ");
		else
			lst_active_button(&rt->panel.lst_button, BTN_PARAM4, FALSE);
	}
}

void		get_param_material(t_rt *rt)
{
	if (rt->panel.viewparam.scene.this_obj->p_mat->type_mat == MAT_METAL)
	{
		sprintf(rt->panel.viewparam.str_mat, "Material: %5sMetallic", " ");
		sprintf(rt->panel.viewparam.str_param_m, "Reflection: %2s" "%.3g", " ",
		rt->panel.viewparam.scene.this_obj->p_mat->t);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM5, TRUE);
	}
	else if (rt->panel.viewparam.scene.this_obj->p_mat->type_mat == MAT_LAMBERT)
	{
		sprintf(rt->panel.viewparam.str_mat, "Material: %5sLambertian", " ");
		sprintf(rt->panel.viewparam.str_param_m, "");
		lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM5, FALSE);
	}
	else if (rt->panel.viewparam.scene.this_obj->p_mat->type_mat ==
			MAT_DIFF_LIGHT)
	{
		sprintf(rt->panel.viewparam.str_mat, "Material: %5sDiffuse Light", " ");
		sprintf(rt->panel.viewparam.str_param_m, " ");
		lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM5, FALSE);
	}
	else if (rt->panel.viewparam.scene.this_obj->p_mat->type_mat == MAT_DIELECT)
	{
		sprintf(rt->panel.viewparam.str_mat, "Material: %5sDielectric", " ");
		sprintf(rt->panel.viewparam.str_param_m, "Refraction: %2s" "%.3g", " ",
		rt->panel.viewparam.scene.this_obj->p_mat->t);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM5, TRUE);
	}
	material_color(rt);
}
