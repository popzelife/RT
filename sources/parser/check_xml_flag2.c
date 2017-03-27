/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xml_flag2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:13:20 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 20:49:32 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	check_flag_uno(t_parser *parser, UINT flag)
{
	if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_PATH) ||
		(flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_PATH) ||
		(flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PATH))
		parser->f = (void*)&bo_texture_filename;
	else
		parser->f = (void*)&bo_void;
}

static void	check_flag_texture(t_parser *parser, UINT flag)
{
	if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_TEXTURE) ||
		(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_TEXTURE) ||
		(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_TEXTURE) ||
		(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_TEXTURE) ||
		(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_TEXTURE) ||
		(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_TEXTURE) ||
		(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_TEXTURE) ||
		(flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_TEXTURE) ||
		(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_TEXTURE) ||
		(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_TEXTURE) ||
		(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_TEXTURE) ||
		(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_METAL | BYTE_TEXTURE) ||
		(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_METAL | BYTE_TEXTURE) ||
		(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_METAL | BYTE_TEXTURE) ||
		(flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_TEXTURE) ||
		(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_TEXTURE) ||
		(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_TEXTURE) ||
		(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_TEXTURE) ||
		(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_DIELECT | BYTE_TEXTURE) ||
		(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_DIELECT | BYTE_TEXTURE) ||
		(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_TEXTURE))
		parser->f = (void*)&bo_texture;
	else
		check_flag_uno(parser, flag);
}

static void	check_flag_metal(t_parser *parser, UINT flag)
{
	if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR))
		parser->f = (void*)&bo_metal_color;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM))
		parser->f = (void*)&bo_metal_param;
	else
		check_flag_texture(parser, flag);
}

void		check_flag_dielect(t_parser *parser, UINT flag)
{
	if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR))
		parser->f = (void*)&bo_dielect_color;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM))
		parser->f = (void*)&bo_dielect_param;
	else
		check_flag_metal(parser, flag);
}
