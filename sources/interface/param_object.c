/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:52:20 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 18:52:04 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	sphere_param(t_rt *rt)
{
	t_sphere		*sphere;

	sphere = (t_sphere*)rt->panel.viewparam.scene.this_obj->p_obj;
	sprintf(rt->panel.viewparam.str_obj, "Sphere Param:");
	sprintf(rt->panel.viewparam.str_pos, "Position: %5s[%.3g; %.3g; %.3g]", " ",
	sphere->center.x, sphere->center.y, sphere->center.z);
	sprintf(rt->panel.viewparam.str_rotate, "Normal: %6s[%.3g; %.3g; %.3g]",
	" ", sphere->normal.x, sphere->normal.y, sphere->normal.z);
	sprintf(rt->panel.viewparam.str_param_o, "Radius: %7s %.3g %7s", " ",
	sphere->radius, " ");
	lst_active_button(&rt->panel.lst_button, BTN_PARAM1, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM2, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
	lst_set_button(&rt->panel.lst_button, BTN_PARAM1,
	actionparam((void*)rt, button_spherepos));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM2,
	actionparam((void*)rt, button_spherenormal));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM3,
	actionparam((void*)rt, button_sphereradius));
}

static void	plane_param(t_rt *rt)
{
	t_plane			*plane;

	plane = (t_plane*)rt->panel.viewparam.scene.this_obj->p_obj;
	sprintf(rt->panel.viewparam.str_obj, "Plane Param:");
	sprintf(rt->panel.viewparam.str_pos, "Position: %5s[%.3g; %.3g; %.3g]", " ",
	plane->on_plane.x, plane->on_plane.y, plane->on_plane.z);
	sprintf(rt->panel.viewparam.str_rotate, "Normal: %6s[%.3g; %.3g; %.3g]",
	" ", plane->normale.x, plane->normale.y, plane->normale.z);
	sprintf(rt->panel.viewparam.str_param_o, "Radius: %7s %.3g%7s", " ",
	plane->radius, " ");
	lst_active_button(&rt->panel.lst_button, BTN_PARAM1, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM2, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
	lst_set_button(&rt->panel.lst_button, BTN_PARAM1,
	actionparam((void*)rt, button_planepos));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM2,
	actionparam((void*)rt, button_planenormal));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM3,
	actionparam((void*)rt, button_planeradius));
}

static void	cone_param(t_rt *rt)
{
	t_cone			*cone;

	cone = (t_cone*)rt->panel.viewparam.scene.this_obj->p_obj;
	sprintf(rt->panel.viewparam.str_obj, "Cone Param:");
	sprintf(rt->panel.viewparam.str_pos, "Position: %5s[%.3g; %.3g; %.3g]", " ",
	cone->cp.x, cone->cp.y, cone->cp.z);
	sprintf(rt->panel.viewparam.str_rotate, "Normal: %6s[%.3g; %.3g; %.3g]",
	" ", cone->vertex.x, cone->vertex.y, cone->vertex.z);
	sprintf(rt->panel.viewparam.str_param_o, "Tan-Hght: %3s%.3g | %.3g", " ",
	cone->tang, cone->height);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM1, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM2, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
	lst_set_button(&rt->panel.lst_button, BTN_PARAM1,
	actionparam((void*)rt, button_conepos));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM2,
	actionparam((void*)rt, button_conenormal));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM3,
	actionparam((void*)rt, button_coneheight));
}

static void	cylinder_param(t_rt *rt)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder*)rt->panel.viewparam.scene.this_obj->p_obj;
	sprintf(rt->panel.viewparam.str_obj, "Cylinder Param:");
	sprintf(rt->panel.viewparam.str_pos, "Position: %5s[%.3g; %.3g; %.3g]", " ",
	cylinder->cp.x, cylinder->cp.y, cylinder->cp.z);
	sprintf(rt->panel.viewparam.str_rotate, "Normal: %6s[%.3g; %.3g; %.3g]",
	" ", cylinder->vertex.x, cylinder->vertex.y, cylinder->vertex.z);
	sprintf(rt->panel.viewparam.str_param_o, "Rad-Hght: %2s %.3g | %.3g", " ",
	cylinder->radius, cylinder->height);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM1, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM2, TRUE);
	lst_active_button(&rt->panel.lst_button, BTN_PARAM3, TRUE);
	lst_set_button(&rt->panel.lst_button, BTN_PARAM1,
	actionparam((void*)rt, button_cylindpos));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM2,
	actionparam((void*)rt, button_cylindnormal));
	lst_set_button(&rt->panel.lst_button, BTN_PARAM3,
	actionparam((void*)rt, button_cylindradius));
}

void		get_param_object(t_rt *rt)
{
	if (rt->panel.viewparam.scene.this_obj->type_obj == OBJ_SPHERE)
		sphere_param(rt);
	else if (rt->panel.viewparam.scene.this_obj->type_obj == OBJ_PLANE)
		plane_param(rt);
	else if (rt->panel.viewparam.scene.this_obj->type_obj == OBJ_CONE)
		cone_param(rt);
	else if (rt->panel.viewparam.scene.this_obj->type_obj == OBJ_CYLINDER)
		cylinder_param(rt);
	else if (rt->panel.viewparam.scene.this_obj->type_obj == OBJ_TRIANGLE)
		triangle_param(rt);
	else
	{
		sprintf(rt->panel.viewparam.str_obj, "Object Param:");
		sprintf(rt->panel.viewparam.str_pos, " ");
		sprintf(rt->panel.viewparam.str_param_o, " ");
		lst_active_button(&rt->panel.lst_button, BTN_PARAM1, FALSE);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM2, FALSE);
		lst_active_button(&rt->panel.lst_button, BTN_PARAM3, FALSE);
	}
}
