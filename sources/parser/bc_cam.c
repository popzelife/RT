/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:23:51 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/06 18:53:43 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bc_cam(t_scene *s, t_parser *p, char *line)
{
	printf("bc_cam %d\n", p->i_cam);
	if (p->i_cam >= p->lim_cam)
	{
		ft_printf("XML %s ERROR - Can't assign more cameras than "
		"initiated at line %d: '%s'\n", __FUNCTION__, p->l, line);
		exit(-1);
	}
	s->cam[p->i_cam].param.aspect = p->ratio;
	s->cam[p->i_cam].param.focus = v3_lenght_double_(v3_sub_vec_(
	s->cam[p->i_cam].param.look_from, s->cam[p->i_cam].param.look_at));
	s->cam[p->i_cam]= set_camera(s->cam[p->i_cam].param.look_from,
	s->cam[p->i_cam].param.look_at, s->cam[p->i_cam].param.v_up,
	s->cam[p->i_cam].param);
	s->this_cam = &s->cam[p->i_cam];
	p->i_cam++;
	p->f = (void*)&bo_void;
}
