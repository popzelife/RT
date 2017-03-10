/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xml_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:39:28 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/09 22:16:53 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	check_flag_ter(t_parser *parser, UINT flag)
{
	if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM))
		parser->f = (void*)&bo_metal_param;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR))
		parser->f = (void*)&bo_dielect_color;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM))
		parser->f = (void*)&bo_dielect_param;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR))
		parser->f = (void*)&bo_difflight_color;
	else if (flag == (BYTE_SKYBOX | BYTE_GRADIENT | BYTE_COLOR))
		parser->f = (void*)&bo_skgradient_color;
	else
		parser->f = (void*)&bo_void;
}

static void	check_flag_bis(t_parser *parser, UINT flag)
{
	if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_RADIUS))
		parser->f = (void*)&bo_cone_radius;
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_ROTATE))
		parser->f = (void*)&bo_cone_rotate;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_POS))
		parser->f = (void*)&bo_cylinder_pos;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_RADIUS))
		parser->f = (void*)&bo_cylinder_radius;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_ROTATE))
		parser->f = (void*)&bo_cylinder_rotate;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR))
		parser->f = (void*)&bo_lambert_color;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR))
		parser->f = (void*)&bo_metal_color;
	else
		check_flag_ter(parser, flag);
}

void		check_flag(t_parser *parser, UINT flag)
{
	if (flag == (BYTE_CAM | BYTE_POS))
		parser->f = (void*)&bo_cam_pos;
	else if (flag == (BYTE_CAM | BYTE_TARGET))
		parser->f = (void*)&bo_cam_target;
	else if (flag == (BYTE_CAM | BYTE_ROTATE))
		parser->f = (void*)&bo_cam_rotate;
	else if (flag == (BYTE_CAM | BYTE_FOV))
		parser->f = (void*)&bo_cam_fov;
	else if (flag == (BYTE_CAM | BYTE_APERT))
		parser->f = (void*)&bo_cam_apert;
	else if (flag == (BYTE_OBJ | BYTE_SPHERE | BYTE_POS))
		parser->f = (void*)&bo_sphere_pos;
	else if (flag == (BYTE_OBJ | BYTE_SPHERE | BYTE_RADIUS))
		parser->f = (void*)&bo_sphere_radius;
	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_POS))
		parser->f = (void*)&bo_plane_pos;
	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_ROTATE))
		parser->f = (void*)&bo_plane_rotate;
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_POS))
		parser->f = (void*)&bo_cone_pos;
	else
		check_flag_bis(parser, flag);
}

void		check_objsame(t_parser *p, char *line, char *str)
{
	if (1 != p->same)
	{
		ft_printf("XML %s ERROR - Can't assign more or less (%d) %s than "
		"initiated at line %d: '%s'\n", __FUNCTION__, p->i_obj, str, p->l,
		line);
		exit(-1);
	}
	p->same++;
}
