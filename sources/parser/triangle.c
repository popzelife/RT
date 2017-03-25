/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:52:00 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 19:29:22 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	error_triangle_assign(t_parser *p, char *value)
{
	ft_printf("XML %s ERROR - Something went wrong while assigning value: "
	"'%s' in triangle[%d].color%d\n", __FUNCTION__, value, p->i_skb, p->grad);
	exit(-1);
}

static void	error_triangle(t_parser *p, char *line)
{
	ft_printf("XML %s ERROR - Too many coord specified at line %d: '%s'\n",
	__FUNCTION__, p->l, line);
	exit(-1);
}

static void	error_triangle_value(t_parser *p, char *line)
{
	ft_printf("XML bo_triangle_pos ERROR -  Value not found at line %d: '%s'\n",
	p->l, line);
	exit(-1);
}

static void	calc_triangle(t_triangle *tri)
{
	tri->e1 = v3_sub_vec_(tri->v2, tri->vertex);
	tri->e2 = v3_sub_vec_(tri->v3, tri->vertex);
	tri->normal = v3_cross_vec_(tri->e1, tri->e2);
	tri->normal = v3_scale_vec_(tri->normal, -1);
}

void		bo_triangle_pos(t_scene *s, t_parser *p, char *line)
{
	t_triangle	*tri;
	char		*value;
	t_vec3		*pos;

	value = NULL;
	pos = NULL;
	tri = (t_triangle*)s->obj[p->i_obj].p_obj;
	if (!xml_get_value(line, &value))
		error_triangle_value(p, line);
	if (p->triangle == 1)
		pos = &tri->vertex;
	else if (p->triangle == 2)
		pos = &tri->v2;
	else if (p->triangle == 3)
		pos = &tri->v3;
	else
		error_triangle(p, line);
	if (!xml_to_vec(value, pos))
		error_triangle_assign(p, value);
	if (p->triangle == 3)
		calc_triangle(tri);
	p->triangle++;
	p->opt |= p->byte[E_TAB_POS];
	free(value);
}
