/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:14:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/03 13:53:44 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*void		check_flag(t_rt *rt, UINT flag)
{
	if (flag == (BYTE_CAM | BYTE_POS))
		rt->parse.f = &bo_cam_pos;
	else if (flag == (BYTE_CAM | BYTE_TARGET))
		rt->parse.f = &bo_cam_target;
	else if (flag == (BYTE_CAM | BYTE_ROTATE))
		rt->parse.f = &bo_cam_rotate;
	else if (flag == (BYTE_CAM | BYTE_FOV))
		rt->parse.f = &bo_cam_fov;
	else if (flag == (BYTE_CAM | BYTE_APERT))
		rt->parse.f = &bo_cam_apert;

	else if (flag == (BYTE_OBJ | BYTE_SPHERE | BYTE_POS))
		rt->parse.f = &bo_sphere_pos;
	else if (flag == (BYTE_OBJ | BYTE_SPHERE | BYTE_RADIUS))
		rt->parse.f = &bo_sphere_radius;

	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_POS))
		rt->parse.f = &bo_plane_pos;
	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_ROTATE))
		rt->parse.f = &bo_plane_rotate;

	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_POS))
		rt->parse.f = &bo_cone_pos;
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_RADIUS))
		rt->parse.f = &bo_cone_radius;
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_ROTATE))
		rt->parse.f = &bo_cone_rotate;

	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_POS))
		rt->parse.f = &bo_cylinder_pos;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_RADIUS))
		rt->parse.f = &bo_cylinder_radius;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_ROTATE))
		rt->parse.f = &bo_cylinder_rotate;

	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR))
		rt->parse.f = &bo_lamber_color;

	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_COLOR))
		rt->parse.f = &bo_metal_color;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_METAL | BYTE_PARAM))
		rt->parse.f = &bo_metal_param;

	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_COLOR))
		rt->parse.f = &bo_dielect_color;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIELECT | BYTE_PARAM))
		rt->parse.f = &bo_dielect_param;

	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
			(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR))
		rt->parse.f = &bo_difflight_color;

	else if (flag == (BYTE_SKYBOX | BYTE_GRADIENT | BYTE_COLOR))
		rt->parse.f = &bo_gradient_color;

	else if (flag == (BYTE_SKYBOX | BYTE_NONE))
		rt->parse.f = &bo_none;
}*/

void		check_flag(t_rt *rt, UINT flag)
{
	(void)rt;
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
		ft_printf("bo_lamber_color\n");

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
		ft_printf("bo_gradient_color\n");

	else if (flag == (BYTE_SKYBOX | BYTE_NONE))
		ft_printf("bo_skybox_none\n");
}

BOOL			ft_strloopstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != s2[j])
			++i;
		while (s1[i] == s2[j] && s1[i] && s2[j])
		{
			++i;
			++j;
			if (!s2[j])
			{
				printf("match: %s\n", s2);
				return (0);
			}
		}
	}
	return (-1);
}

int				strcmp_tab(char *line, char**tab)
{
	int		i;

	i = 0;
	while (i < NB_BALISE)
	{
		if ((ft_strloopstr(line, tab[i])) == 0)
			return (i);
		++i;
	}
	return (-1);
}

UINT			xml_to_flag(t_rt *rt, char *line)
{
	int		pos;
	
	if (!line)
		return (0);
	if ((pos = strcmp_tab(line, rt->parser.bo)) != -1)
	{
		rt->parser.is_close = 0;
		rt->parser.flag |= rt->parser.byte[pos];
		printf("BO flag is %s from pos %d\n", ft_uitoa_32bit(rt->parser.flag),
		pos);
		check_flag(rt, rt->parser.flag);
	}
	if ((pos = strcmp_tab(line, rt->parser.bc)) != -1)
	{
		rt->parser.is_close = 1;
		rt->parser.flag ^= rt->parser.byte[pos];
		printf("BC flag is %s from pos %d\n", ft_uitoa_32bit(rt->parser.flag),
		pos);
		check_flag(rt, rt->parser.flag);
	}
	return (0);
}

void			read_xml(t_rt *rt, t_scene *scene)
{
	char	*line;
	int		fd;

	(void)scene;
	rt->parser.flag = 0;
	if ((fd = open(rt->filename, O_RDONLY)) == -1)
	{
		ft_printf("XML Parse ERROR - No such a file '%s'\n", rt->filename);
		exit(-1);
	}
	get_next_line(fd, &line);
	printf("%s\n", line);
	if (ft_strcmp(ft_trim(line), FILE_DEF) != 0)
	{
		ft_printf("XML Parse ERROR - '%s' is not a valid file\n", rt->filename);
		exit(-1);
	}
	free(line);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", ft_strtolower(ft_trim(line)));
		xml_to_flag(rt, ft_strtolower(ft_trim(line)));
		free(line);
		printf("\n");
	}
}
