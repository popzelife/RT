/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:01:31 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 21:54:40 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	material_color(t_rt *rt)
{
	sprintf(rt->panel.viewparam.str_color, "Color: %10srgb(%.3g, %.3g, %.3g)",
	" ", rt->panel.viewparam.scene.this_obj->p_mat->albedo.x * 249.9,
	rt->panel.viewparam.scene.this_obj->p_mat->albedo.y * 249.9,
	rt->panel.viewparam.scene.this_obj->p_mat->albedo.z * 249.9);
}

void		get_param_material(t_rt *rt)
{
	if (rt->panel.viewparam.scene.this_obj->p_mat->type_mat == MAT_METAL)
	{
		sprintf(rt->panel.viewparam.str_mat, "Material: %5sMetallic", " ");
		sprintf(rt->panel.viewparam.str_param_m, "Fuzzy: %10.3g",
		rt->panel.viewparam.scene.this_obj->p_mat->t);
	}
	else if (rt->panel.viewparam.scene.this_obj->p_mat->type_mat == MAT_LAMBERT)
	{
		sprintf(rt->panel.viewparam.str_mat, "Material: %5sLambertian", " ");
		sprintf(rt->panel.viewparam.str_param_m, "");
	}
	else if (rt->panel.viewparam.scene.this_obj->p_mat->type_mat ==
			MAT_DIFF_LIGHT)
	{
		sprintf(rt->panel.viewparam.str_mat, "Material: %5sDiffuse Light", " ");
		sprintf(rt->panel.viewparam.str_param_m, " ");
	}
	else if (rt->panel.viewparam.scene.this_obj->p_mat->type_mat == MAT_DIELECT)
	{
		sprintf(rt->panel.viewparam.str_mat, "Material: %5sDielectric", " ");
		sprintf(rt->panel.viewparam.str_param_m, "Reflection: %5.3g",
		rt->panel.viewparam.scene.this_obj->p_mat->t);
	}
	material_color(rt);
}
