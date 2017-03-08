/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:33:27 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/08 20:18:13 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bc_sphere(t_scene *s, t_parser *p, char *line)
{
	t_sphere	*o;

	printf("%s %d\n", __FUNCTION__, p->i_obj);
	if (p->i_obj >= p->lim_obj || p->i_obj < 0)
	{
		ft_printf("XML %s ERROR - Can't assign more or less (%d) spheres than "
		"initiated at line %d: '%s'\n", __FUNCTION__, p->i_obj, p->l, line);
		exit(-1);
	}
	printf("opt flag is %s / %s\n", ft_uitoa_32bit(p->opt), ft_uitoa_32bit(BYTE_CAM | BYTE_POS | BYTE_TARGET));
	if (check_opt(p->opt) != E_TAB_SPHERE || p->mat == FALSE)
	{
		ft_printf("XML %s ERROR - Some flags are missing within <sphere> balise"
		" for sphere %d at line %d: %s\n", __FUNCTION__, p->i_obj, p->l, line);
		exit(-1);
	}
	o = (t_sphere*)s->obj[p->i_obj].p_obj;
	*o = set_sphere(o->center, o->radius);
	s->obj[p->i_obj]= new_object((void*)o, s->type_obj, s->p_mat, s->type_mat);
	s->this_obj = &s->obj[p->i_obj];
	p->f = (void*)&bo_void;
	p->opt = 0;
	p->mat = FALSE;
}

void		bo_sphere(t_scene *s, t_parser *p, char *line)
{
	(void)line;
	p->i_obj++;
	printf("%s %d\n", __FUNCTION__, p->i_obj);
	if (p->i_obj >= p->lim_obj)
	{
		printf("realloc\n");
		p->lim_obj += 6;
		s->obj = (t_obj*)ft_realloc((void*)s->obj, sizeof(t_obj) * p->lim_obj);
	}
	s->obj[p->i_obj].p_obj = (void*)malloc(sizeof(t_sphere));
	s->obj[p->i_obj].type_obj = OBJ_SPHERE;
	p->f = (void*)&bo_void;
	p->opt |= p->byte[E_TAB_SPHERE];
}
