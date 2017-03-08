/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:13:14 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/08 16:23:41 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bo_skgradient_color(t_scene *s, t_parser *p, char *line)
{
	printf("%s\n", __FUNCTION__);
	char		*value;
	t_vec3		*color;

	value = NULL;
	if (!xml_get_value(line, &value))
	{
		ft_printf("XML %s ERROR - Value not found at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	printf("%s\n", value);
	if (p->grad == 1)
		color = &s->skybox[p->i_skb].color1;
	else if (p->grad == 2)
		color = &s->skybox[p->i_skb].color2;
	else
	{
		ft_printf("XML %s ERROR - Too many color specified at line %d: '%s'\n",
		__FUNCTION__, p->l, line);
		exit(-1);
	}
	p->grad++;
	if (!xml_to_vec(value, color))
	{
		ft_printf("XML %s ERROR - Something went wrong while assigning value: "
		"'%s' in skybox[%d].color%d\n", __FUNCTION__, value, p->i_skb, p->grad);
		exit(-1);
	}
	p->opt |= p->byte[E_TAB_COLOR];
	free(value);
}
