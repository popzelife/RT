/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:33:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/09 20:31:05 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_plane_rotate(t_scene *s, t_parser *p, char *line)
{
	char		*value;
	t_plane		*o;

	value = NULL;
	o = (t_plane*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_vec(value, &o->normale))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' in plane[%d].normale\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	p->opt |= p->byte[E_TAB_ROTATE];
	free(value);
}

void		bo_plane_pos(t_scene *s, t_parser *p, char *line)
{
	char		*value;
	t_plane		*o;

	value = NULL;
	o = (t_plane*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_vec(value, &o->on_plane))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' in plane[%d].pos\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	p->opt |= p->byte[E_TAB_POS];
	free(value);
}
