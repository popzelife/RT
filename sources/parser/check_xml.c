/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:37:19 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 19:50:01 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_void(t_scene *s, t_parser *p, char *line)
{
	(void)p;
	(void)s;
	(void)line;
}

static void	check_bo_bis(t_parser *parser, UINT flag)
{
	if (flag == BYTE_DIELECT)
		parser->f = (void*)&bo_dielectric;
	else if (flag == BYTE_DIFFLIGHT)
		parser->f = (void*)&bo_difflight;
	else if (flag == BYTE_GRADIENT)
		parser->f = (void*)&bo_skybox_gradient;
	else if (flag == BYTE_NONE)
		parser->f = (void*)&bo_skybox_none;
	else
		parser->f = (void*)&bo_void;
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
	else if (flag == BYTE_ELLIPSOID)
		parser->f = (void*)&bo_ellipsoid;
	else if (flag == BYTE_PARABLOID)
		parser->f = (void*)&bo_paraboloid;
	else if (flag == BYTE_TRIANGLE)
		parser->f = (void*)&bo_triangle;
	else if (flag == BYTE_LAMBERT)
		parser->f = (void*)&bo_lambert;
	else if (flag == BYTE_METAL)
		parser->f = (void*)&bo_metal;
	else
		check_bo_bis(parser, flag);
}

static void	check_bc_bis(t_parser *parser, UINT flag)
{
	if (flag == BYTE_DIFFLIGHT)
		parser->f = (void*)&bc_difflight;
	else if (flag == BYTE_GRADIENT)
		parser->f = (void*)&bc_skybox_gradient;
	else if (flag == BYTE_NONE)
		parser->f = (void*)&bc_skybox_none;
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
	else if (flag == BYTE_ELLIPSOID)
		parser->f = (void*)&bc_ellipsoid;
	else if (flag == BYTE_PARABLOID)
		parser->f = (void*)&bc_paraboloid;
	else if (flag == BYTE_TRIANGLE)
		parser->f = (void*)&bc_triangle;
	else if (flag == BYTE_LAMBERT)
		parser->f = (void*)&bc_lambert;
	else if (flag == BYTE_METAL)
		parser->f = (void*)&bc_metal;
	else if (flag == BYTE_DIELECT)
		parser->f = (void*)&bc_dielectric;
	else
		check_bc_bis(parser, flag);
}
