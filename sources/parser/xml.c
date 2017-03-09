/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:14:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 18:58:34 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_void(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
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
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_RADIUS))
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
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
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

void		print_flag(UINT flag)
{
	if (flag == (BYTE_CAM | BYTE_POS))
		ft_printf("bo_cam_pos\n");
	else if (flag == (BYTE_CAM | BYTE_TARGET))
		ft_printf("bo_cam_target\n");
	else if (flag == (BYTE_CAM | BYTE_ROTATE))
		ft_printf("bo_cam_rotate\n");
	else if (flag == (BYTE_CAM | BYTE_FOV))
		ft_printf("bo_cam_fov\n");
	else if (flag == (BYTE_CAM | BYTE_APERT))
		ft_printf("bo_cam_apert\n");

	else if (flag == (BYTE_OBJ | BYTE_SPHERE | BYTE_POS))
		ft_printf("bo_sphere_pos\n");
	else if (flag == (BYTE_OBJ | BYTE_SPHERE | BYTE_RADIUS))
		ft_printf("bo_sphere_radius\n");

	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_POS))
		ft_printf("bo_plane_pos\n");
	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_ROTATE))
		ft_printf("bo_plane_rotate\n");

	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_POS))
		ft_printf("bo_cone_pos\n");
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_RADIUS))
		ft_printf("bo_cone_radius\n");
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_ROTATE))
		ft_printf("bo_cone_rotate\n");

	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_POS))
		ft_printf("bo_cylinder_pos\n");
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_RADIUS))
		ft_printf("bo_cylinder_radius\n");
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_ROTATE))
		ft_printf("bo_cylinder_rotate\n");

	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR))
		ft_printf("bo_lambert_color\n");

	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR))
		ft_printf("bo_metal_color\n");
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM))
		ft_printf("bo_metal_param\n");

	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR))
		ft_printf("bo_dielect_color\n");
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM))
		ft_printf("bo_dielect_param\n");

	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR))
		ft_printf("bo_difflight_color\n");

	else if (flag == (BYTE_SKYBOX | BYTE_GRADIENT | BYTE_COLOR))
		ft_printf("bo_skgradient_color\n");

	else
		ft_printf("bo_void\n");
}

UINT			xml_to_flag(t_scene *scene, t_parser *parser, char *line)
{
	int		pos;
	
	if (!line)
		return (0);
	if ((pos = ft_strcmptab(line, parser->bo, parser->nb_balise)) != -1)
	{
		parser->is_close = 0;
		parser->flag |= parser->byte[pos];
		printf("BO flag is %s from pos %d\n", ft_uitoa_32bit(parser->flag), pos);
		check_bo(parser, parser->byte[pos]);
		parser->f(scene, parser, line);
		check_flag(parser, parser->flag);
	}
	print_flag(parser->flag);
	parser->f(scene, parser, line);
	if ((pos = ft_strcmptab(line, parser->bc, parser->nb_balise)) != -1)
	{
		parser->is_close = 1;
		parser->flag ^= parser->byte[pos];
		printf("BC flag is %s from pos %d\n", ft_uitoa_32bit(parser->flag), pos);
		check_bc(parser, parser->byte[pos]);
		parser->f(scene, parser, line);
	}
	return (0);
}

void			read_xml(t_rt *rt, t_scene *scene)
{
	char	*line;
	int		fd;

	rt->parser.i_obj = -1;
	rt->parser.i_cam = -1;
	rt->parser.i_skb = -1;
	rt->parser.flag = 0;
	rt->parser.opt = 0;
	rt->parser.opt_m = 0;
	rt->parser.f = &bo_void;
	rt->parser.ratio = (double)rt->r_view->w / (double)rt->r_view->h;
	rt->parser.l = 1;
	rt->parser.obj = -1;
	rt->parser.mat = false;
	if ((fd = open(rt->filename, O_RDONLY)) == -1)
	{
		ft_printf("XML Parse ERROR - No such a file '%s'\n", rt->filename);
		exit(-1);
	}
	get_next_line(fd, &line);
	if (ft_strcmp(ft_trim(line), FILE_DEF) != 0)
	{
		ft_printf("XML Parse ERROR - '%s' is not a valid file\n", rt->filename);
		exit(-1);
	}
	printf("%s\n", ft_strtolower(ft_trim(line)));
	free(line);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", ft_strtolower(ft_trim(line)));
		xml_to_flag(scene, &rt->parser, ft_strtolower(ft_trim(line)));
		free(line);
		rt->parser.l++;
		printf("\n\n");
	}
}
