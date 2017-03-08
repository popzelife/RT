/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:15:07 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/08 16:50:47 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_cam_pos(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
	char	*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	printf("%s\n", value);
	if (!xml_to_vec(value, &s->cam[p->i_cam].param.look_from))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' in cam[%d].param.look_from\n", __FUNCTION__, value, p->i_cam);
		exit(-1);
	}
	p->opt |= p->byte[E_TAB_POS];
	printf("opt flag is %s\n", ft_uitoa_32bit(p->opt));
	free(value);
}

void		bo_cam_target(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
	char	*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	printf("%s\n", value);
	if (!xml_to_vec(value, &s->cam[p->i_cam].param.look_at))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s'' in cam[%d].param.look_at\n", __FUNCTION__, value, p->i_cam);
		exit(-1);
	}
	p->opt |= p->byte[E_TAB_TARGET];
	printf("opt flag is %s\n", ft_uitoa_32bit(p->opt));
	free(value);
}

void		bo_cam_rotate(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
	char	*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	printf("%s\n", value);
	if (!xml_to_vec(value, &s->cam[p->i_cam].param.v_up))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' in cam[%d].param.v_up\n", __FUNCTION__, value, p->i_cam);
		exit(-1);
	}
	free(value);
}

void		bo_cam_fov(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
	char	*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	printf("%s\n", value);
	if (!xml_to_double(value, &s->cam[p->i_cam].param.vfov))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' in cam[%d].param.vfov\n", __FUNCTION__, value, p->i_cam);
		exit(-1);
	}
	free(value);
}

void		bo_cam_apert(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
	char	*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	printf("%s\n", value);
	if (!xml_to_double(value, &s->cam[p->i_cam].param.aperture))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' in cam[%d].param.aperture\n", __FUNCTION__, value, p->i_cam);
		exit(-1);
	}
	free(value);
}
