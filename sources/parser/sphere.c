/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:33:24 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 20:16:21 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_sphere_pos(t_scene *s, t_parser *p, char *line)
{
	char		*value;
	t_sphere	*o;

	value = NULL;
	o = (t_sphere*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_vec(value, &o->center))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' in sphere[%d].center\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	p->opt |= p->byte[E_TAB_POS];
	free(value);
}

void		bo_sphere_radius(t_scene *s, t_parser *p, char *line)
{
	char		*value;
	t_sphere	*o;

	value = NULL;
	o = (t_sphere*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_double(value, &o->radius))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' in sphere[%d].radius\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	o->radius2 = o->radius * o->radius;
	p->opt |= p->byte[E_TAB_RADIUS];
	free(value);
}
