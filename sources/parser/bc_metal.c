/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_metal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:45:35 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 19:40:24 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bc_metal(t_scene *s, t_parser *p, char *line)
{
	(void)s;
	if (p->i_obj >= p->lim_obj || p->i_obj < 0)
	{
		ft_printf("XML %s ERROR - Can't assign mat to more or less (%d)"
		" object than initiated at line %d: '%s'\n", __FUNCTION__, p->i_obj,
		p->l, line);
		exit(-1);
	}
	if (check_opt(p->opt_m) != E_TAB_METAL)
	{
		ft_printf("XML %s ERROR - Some flags are missing within <metal> "
		"balise for mat %d at line %d: %s\n", __FUNCTION__, p->i_obj, p->l,
		line);
		exit(-1);
	}
	p->f = (void*)&bo_void;
	p->mat = TRUE;
}

void		bo_metal(t_scene *s, t_parser *p, char *line)
{
	(void)line;
	if (p->obj != p->i_obj)
	{
		ft_printf("XML %s ERROR - Material need to be assigned to a declared"
		" object at line %d: '%s'\n", __FUNCTION__, p->l, line);
		exit(-1);
	}
	if (p->lim_mat >= 1)
	{
		ft_printf("XML %s ERROR - Can't assign more than one material (%d) to"
		" object (%d) at line %d: '%s'\n", __FUNCTION__, p->lim_mat, p->i_obj,
		p->l, line);
		exit(-1);
	}
	s->obj[p->i_obj].p_mat = (void*)new_material(v3_(0., 0., 0.), 0.);
	s->obj[p->i_obj].p_mat->type_mat = MAT_METAL;
	p->f = (void*)&bo_void;
	p->opt_m |= p->byte[E_TAB_METAL];
	p->lim_mat++;
}
