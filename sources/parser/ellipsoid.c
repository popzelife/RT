/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:01:20 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 19:32:39 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_ellipsoid_pos(t_scene *s, t_parser *p, char *line)
{
	char			*value;
	t_ellipsoid		*o;

	value = NULL;
	o = (t_ellipsoid*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
				__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_vec(value, &o->center))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
			" '%s' in ellipsoid[%d].center\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	p->opt |= p->byte[E_TAB_POS];
	free(value);
}

void		bo_ellipsoid_rotate(t_scene *s, t_parser *p, char *line)
{
	char			*value;
	t_ellipsoid		*o;

	value = NULL;
	o = (t_ellipsoid*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
				__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_vec(value, &o->vertex))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
			" '%s' in ellipsoid[%d].rotate\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	v3_normalize(&o->vertex);
	p->opt |= p->byte[E_TAB_ROTATE];
	free(value);
}

void		bo_ellipsoid_radius(t_scene *s, t_parser *p, char *line)
{
	char			*value;
	t_ellipsoid		*o;

	value = NULL;
	o = (t_ellipsoid*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
				__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_double(value, &o->radius))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
			" '%s' in ellipsoid[%d].radius\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	o->radius2 = o->radius * o->radius;
	p->opt |= p->byte[E_TAB_RADIUS];
	free(value);
}

void		bo_ellipsoid_height(t_scene *s, t_parser *p, char *line)
{
	char			*value;
	t_ellipsoid		*o;

	value = NULL;
	o = (t_ellipsoid*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
				__FUNCTION__, p->l, line);
		exit(-1);
	}
	if (!xml_to_double(value, &o->k))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
			" '%s' in ellipsoid[%d].height\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	p->opt |= p->byte[E_TAB_HEIGHT];
	free(value);
}
