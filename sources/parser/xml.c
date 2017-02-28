/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:14:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/28 18:56:24 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char*			ft_strtolower(char *s)
{
	while (*s)
		*s = ft_tolower(*s++);
	return (s);
}

char*			ft_ltrim(char *s)
{
	while(ft_isspace(*s) != 0)
		s++;
	return (s);
}

char*			ft_rtrim(char *s)
{
	char	*back;

	back = s + ft_strlen(s);
	while(ft_isspace(*--back) != 0)
		*(back + 1) = '\0';
	return (s);
}
}

char*			ft_trim(char *s)
{
	return (ft_rtrim(ft_ltrim(s)));
}

void		init_xml_balise(t_rt *rt)
{
	/*
	** Scene type
	*/
	rt->parser.bo[0] = &bo_camera;
	rt->parser.bo[1] = &bo_obj;
	rt->parser.bo[2] = &bo_skybox;
	/*
	** Camera param
	*/
	rt->parser.bo[0][0] = &bo_cam_pos;
	rt->parser.bo[0][1] = &bo_cam_target;
	rt->parser.bo[0][2] = &bo_cam_rotate;
	rt->parser.bo[0][3] = &bo_cam_fov;
	rt->parser.bo[0][4] = &bo_cam_aperture;
	/*
	** Object type
	*/
	rt->parser.bo[1][0][0] = &bo_sphere;
	rt->parser.bo[1][0][1] = &bo_plane;
	rt->parser.bo[1][0][2] = &bo_cone;
	rt->parser.bo[1][0][3] = &bo_cylinder;
	/*
	** Material type
	*/
	rt->parser.bo[1][1][0] = &bo_lambert;
	rt->parser.bo[1][1][1] = &bo_metal;
	rt->parser.bo[1][1][2] = &bo_difflight;
	/*
	** Sphere param
	*/
	rt->parser.bo[1][0][0][0] = &bo_sphere_pos;
	rt->parser.bo[1][0][0][1] = &bo_sphere_radius;
	/*
	** Plane param
	*/
	rt->parser.bo[1][0][1][0] = &bo_plane_pos;
	rt->parser.bo[1][0][1][1] = &bo_plane_rotate;
	/*
	** Cone param
	*/
	rt->parser.bo[1][0][2][0] = &bo_cone_pos;
	rt->parser.bo[1][0][2][1] = &bo_cone_radius;
	rt->parser.bo[1][0][2][2] = &bo_cone_rotate;
	/*
	** Cylinder param
	*/
	rt->parser.bo[1][0][2][0] = &bo_cylinder_pos;
	rt->parser.bo[1][0][2][1] = &bo_cylinder_radius;
	rt->parser.bo[1][0][2][2] = &bo_cylinder_rotate;
	/*
	** Lambert param
	*/
	rt->parser.bo[1][1][0][0] = &bo_lamber_color;
	/*
	** Metal param
	*/
	rt->parser.bo[1][1][1][0] = &bo_metal_color;
	rt->parser.bo[1][1][1][0] = &bo_metal_param;
	/*
	** DiffLight param
	*/
	rt->parser.bo[1][1][2][0] = &bo_difflight_color;
	/*
	** Skybox type
	*/
	rt->parser.bo[2][0] = &bo_skybox_gradient;
	rt->parser.bo[2][1] = &bo_skybox_none;
	/*
	** Gradient param
	*/
	rt->parser.bo[2][0][0] = &bo_gradient_color1;
	rt->parser.bo[2][0][1] = &bo_gradient_color2;
}

int				xml_cmp(t_rt *rt, char *line)
{
	if (ft_strcmp(line, "BO_") == 0)
	{
		if ((rt->parse.f = check_balise(line, rt->parse.bo)) == NULL)
			return (0);
		return (1);
	}
	if (ft_strcmp(line, "BC_") == 0)
	{
		if ((rt->parse.f = check_balise(line, rt->parse.bc)) == NULL)
			return (0);
		return (2);
	}
	return (0);
}

void			read_xml(t_rt *rt, t_scene *scene)
{
	char	*line;
	int		fd;
	int		ret;
	
	if ((fd = open(rt->filename, O_RDONLY) == -1))
		exit(-1);
	if (!get_next_line(fd, &line) || ft_strcmp(ft_strtolower(ft_trim(line)),
		FILE_DEF));
		exit(-1);
	free(line);
	while (get_next_line(fd, &line))
	{
		if ((ret = xml_comp(rt, ft_strtolower(ft_trim(line)))) == 1)
			rt->parse.f();
		else if (ret == 2)
			rt->parse.f();
		free(line);
	}
}
