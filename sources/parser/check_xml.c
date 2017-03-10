/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:37:19 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/09 20:41:32 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_void(t_scene *s, t_parser *p, char *line)
{
	(void)p;
	(void)s;
	(void)line;
}

void		check_bo(t_parser *parser, UINT flag)
{
	if (flag == BYTE_CAM)
		parser->f = (void*)&bo_cam;
	else if (flag == BYTE_SPHERE)
		parser->f = (void*)&bo_sphere;
	else if (flag == BYTE_PLANE)
		parser->f = (void*)&bo_plane;
	else if (flag == BYTE_CONE)
		parser->f = (void*)&bo_cone;
	else if (flag == BYTE_CYLINDER)
		parser->f = (void*)&bo_cylinder;
	else if (flag == BYTE_LAMBERT)
		parser->f = (void*)&bo_lambert;
	else if (flag == BYTE_METAL)
		parser->f = (void*)&bo_metal;
	else if (flag == BYTE_DIFFLIGHT)
		parser->f = (void*)&bo_difflight;
	else if (flag == BYTE_GRADIENT)
		parser->f = (void*)&bo_skybox_gradient;
	else if (flag == BYTE_NONE)
		parser->f = (void*)&bo_skybox_none;
	else
		parser->f = (void*)&bo_void;
}

void		check_bc(t_parser *parser, UINT flag)
{
	if (flag == BYTE_CAM)
		parser->f = (void*)&bc_cam;
	else if (flag == BYTE_SPHERE)
		parser->f = (void*)&bc_sphere;
	else if (flag == BYTE_PLANE)
		parser->f = (void*)&bc_plane;
	else if (flag == BYTE_CONE)
		parser->f = (void*)&bc_cone;
	else if (flag == BYTE_CYLINDER)
		parser->f = (void*)&bc_cylinder;
	else if (flag == BYTE_LAMBERT)
		parser->f = (void*)&bc_lambert;
	else if (flag == BYTE_METAL)
		parser->f = (void*)&bc_metal;
	else if (flag == BYTE_DIFFLIGHT)
		parser->f = (void*)&bc_difflight;
	else if (flag == BYTE_GRADIENT)
		parser->f = (void*)&bc_skybox_gradient;
	else if (flag == BYTE_NONE)
		parser->f = (void*)&bc_skybox_none;
	else
		parser->f = (void*)&bo_void;
}

int			check_opt(UINT opt)
{
	if (opt == (BYTE_CAM | BYTE_POS | BYTE_TARGET))
		return (E_TAB_CAM);
	else if (opt == (BYTE_SPHERE | BYTE_POS | BYTE_RADIUS))
		return (E_TAB_SPHERE);
	else if (opt == (BYTE_PLANE | BYTE_POS | BYTE_ROTATE))
		return (E_TAB_PLANE);
	else if (opt == (BYTE_CONE | BYTE_POS | BYTE_RADIUS | BYTE_ROTATE))
		return (E_TAB_CONE);
	else if (opt == (BYTE_CYLINDER | BYTE_POS | BYTE_RADIUS | BYTE_ROTATE))
		return (E_TAB_CYLINDER);
	else if (opt == (BYTE_LAMBERT | BYTE_COLOR))
		return (E_TAB_LAMBERT);
	else if (opt == (BYTE_METAL | BYTE_COLOR))
		return (E_TAB_METAL);
	else if (opt == (BYTE_DIFFLIGHT | BYTE_COLOR))
		return (E_TAB_DIFFLIGHT);
	else if (opt == (BYTE_GRADIENT | BYTE_COLOR))
		return (E_TAB_GRADIENT);
	else if (opt == (BYTE_NONE))
		return (E_TAB_NONE);
	return (0);
}
