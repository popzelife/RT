/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:44:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 19:07:35 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	bc_flag_triangle(t_scene *s, t_parser *p)
{
	s->obj[p->i_obj] = new_object(s->obj[p->i_obj].p_obj,
	s->obj[p->i_obj].type_obj,
	s->obj[p->i_obj].p_mat, s->obj[p->i_obj].p_mat->type_mat);
	s->this_obj = &s->obj[p->i_obj];
	s->sizeof_obj = p->i_obj + 1;
	p->f = (void*)&bo_void;
	p->opt = 0;
	p->mat = FALSE;
	p->lim_mat = 0;
	p->obj = -1;
	p->triangle = 0;
	p->same--;
}

void		bc_triangle(t_scene *s, t_parser *p, char *line)
{
	if (p->i_obj >= p->lim_obj || p->i_obj < 0)
	{
		ft_printf("XML %s ERROR - Can't assign more or less (%d) triangle than "
		"initiated at line %d: '%s'\n", __FUNCTION__, p->i_obj, p->l, line);
		exit(-1);
	}
	if (check_opt(p->opt) != E_TAB_TRIANGLE || p->mat == FALSE)
	{
		ft_printf("XML %s ERROR - Some flags are missing within <triangle>"
		" balise for triangle %d at line %d: %s\n", __FUNCTION__, p->i_obj,
		p->l, line);
		exit(-1);
	}
	bc_flag_triangle(s, p);
	ft_printf("\t- Triangle[%d] Initiated\n", s->sizeof_obj);
}

void		bo_triangle(t_scene *s, t_parser *p, char *line)
{
	check_objsame(p, line, "triangle");
	p->i_obj++;
	if (p->i_obj >= p->lim_obj)
	{
		p->lim_obj += 1;
		if ((s->obj = (t_obj*)realloc(s->obj, p->lim_obj * sizeof(t_obj)))
			== NULL)
		{
			ft_printf("Realloc %s ERROR - Something went wrong trying to "
			"realloc the given structure at object %d\n", __FUNCTION__,
			p->i_obj);
			exit(-1);
		}
	}
	s->obj[p->i_obj].p_obj = (void*)new_triangle(v3_(0., 0., 0.),
	v3_(0., 0., 0.), v3_(0., 0., 0.));
	s->obj[p->i_obj].type_obj = OBJ_TRIANGLE;
	p->f = (void*)&bo_void;
	p->opt |= p->byte[E_TAB_TRIANGLE];
	p->obj = p->i_obj;
	p->triangle = 1;
	p->opt_m = 0;
}
