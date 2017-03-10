/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:45:32 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 20:30:56 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_metal_color(t_scene *s, t_parser *p, char *line)
{
	char		*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_vec(value, &s->obj[p->i_obj].p_mat->albedo))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' on metal[%d].albedo\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	p->opt_m |= p->byte[E_TAB_COLOR];
	free(value);
}

void		bo_metal_param(t_scene *s, t_parser *p, char *line)
{
	char		*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_double(value, &s->obj[p->i_obj].p_mat->t))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' on metal[%d].param\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	free(value);
}
