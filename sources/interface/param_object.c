/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:52:20 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 22:18:59 by qfremeau         ###   ########.fr       */
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
	sprintf(rt->panel.viewparam.str_param_o, "Radius: %6s %.3g %7s", " ",
	sphere->radius, " ");
}

static void	plane_param(t_rt *rt)
{
	t_plane			*plane;

	plane = (t_plane*)rt->panel.viewparam.scene.this_obj->p_obj;
	sprintf(rt->panel.viewparam.str_obj, "Plane Param:");
	sprintf(rt->panel.viewparam.str_pos, "Position: %5s[%.3g; %.3g; %.3g]", " ",
	plane->on_plane.x, plane->on_plane.y, plane->on_plane.z);
	sprintf(rt->panel.viewparam.str_param_o, "Normal: %6s[%.3g; %.3g; %.3g]",
	" ", plane->normale.x, plane->normale.y, plane->normale.z);
}

static void	cone_param(t_rt *rt)
{
	t_cone			*cone;

	cone = (t_cone*)rt->panel.viewparam.scene.this_obj->p_obj;
	sprintf(rt->panel.viewparam.str_obj, "Cone Param:");
	sprintf(rt->panel.viewparam.str_pos, "Position: %5s[%.3g; %.3g; %.3g]", " ",
	cone->vertex.x, cone->vertex.y, cone->vertex.z);
	sprintf(rt->panel.viewparam.str_param_o, "Normal: %6s[%.3g; %.3g; %.3g]",
	" ", cone->cp.x, cone->cp.y, cone->cp.z);
}

static void	cylinder_param(t_rt *rt)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder*)rt->panel.viewparam.scene.this_obj->p_obj;
	sprintf(rt->panel.viewparam.str_obj, "Cylinder Param:");
	sprintf(rt->panel.viewparam.str_pos, "Position: %5s[%.3g; %.3g; %.3g]", " ",
	cylinder->vertex.x, cylinder->vertex.y, cylinder->vertex.z);
	sprintf(rt->panel.viewparam.str_param_o, "Radius: %6s %.3g%7s", " ",
	cylinder->radius, " ");
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
}
