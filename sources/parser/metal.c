/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:45:32 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 17:53:07 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_metal_color(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
	char		*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	printf("%s\n", value);
	if (!xml_to_vec(value, &s->obj[p->i_obj].p_mat->albedo))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' on metal[%d].albedo\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	p->opt_m |= p->byte[E_TAB_COLOR];
	printf("opt flag is %s\n", ft_uitoa_32bit(p->opt));
	free(value);
}

void		bo_metal_param(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
	char		*value;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	printf("%s\n", value);
	if (!xml_to_double(value, &s->obj[p->i_obj].p_mat->t))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value:"
		" '%s' on metal[%d].param\n", __FUNCTION__, value, p->i_obj);
		exit(-1);
	}
	printf("opt flag is %s\n", ft_uitoa_32bit(p->opt));
	free(value);
}
