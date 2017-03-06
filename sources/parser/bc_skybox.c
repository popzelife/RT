/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_skybox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:17:46 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/06 18:48:37 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bc_skybox(t_scene *s, t_parser *p, char *line)
{
	printf("bc_skybox %d\n", p->i_skb);
	if (p->i_skb >= p->lim_skb)
	{
		ft_printf("XML %s ERROR - Can't assign more skybox than "
		"initiated at line %d: '%s'\n", __FUNCTION__, p->l, line);
		exit(-1);
	}
	s->skybox[p->i_skb] = new_skybox(s->skybox[p->i_skb].color1,
	s->skybox[p->i_skb].color2, s->skybox[p->i_skb].type);
	s->this_skb = &s->skybox[p->i_skb];
	p->i_skb++;
	p->f = (void*)&bo_void;
	p->grad = 1;
}
