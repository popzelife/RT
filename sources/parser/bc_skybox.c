/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_skybox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:17:46 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 15:42:20 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bc_skybox_gradient(t_scene *s, t_parser *p, char *line)
{
	printf("%s %d\n", __FUNCTION__, p->i_skb);
	if (p->i_skb >= p->lim_skb || p->i_skb < 0)
	{
		ft_printf("XML %s ERROR - Can't assign more or less (%d) skybox than "
		"initiated at line %d: '%s'\n", __FUNCTION__, p->i_skb, p->l, line);
		exit(-1);
	}
	printf("opt flag is %s / %s\n", ft_uitoa_32bit(p->opt), ft_uitoa_32bit(BYTE_GRADIENT | BYTE_COLOR));
	if (check_opt(p->opt) != E_TAB_GRADIENT)
	{
		ft_printf("XML %s ERROR - Some flags are missing within <skybox> balise"
		" for gradient_skybox %d at line %d: %s\n", __FUNCTION__, p->i_cam,
		p->l, line);
		exit(-1);
	}
	if (p->grad == 2)
		s->skybox[p->i_skb].color2 = s->skybox[p->i_skb].color1;
	s->skybox[p->i_skb] = new_skybox(s->skybox[p->i_skb].color1,
	s->skybox[p->i_skb].color2, s->skybox[p->i_skb].type);
	s->this_skb = &s->skybox[p->i_skb];
	s->sizeof_skb = p->i_skb + 1;
	p->f = (void*)&bo_void;
	p->opt = 0;
}

void		bc_skybox_none(t_scene *s, t_parser *p, char *line)
{
	printf("%s %d\n", __FUNCTION__, p->i_skb);
	if (p->i_skb >= p->lim_skb || p->i_skb < 0)
	{
		ft_printf("XML %s ERROR - Can't assign more or less (%d) skybox than "
		"initiated at line %d: '%s'\n", __FUNCTION__, p->i_skb, p->l, line);
		exit(-1);
	}
	printf("opt flag is %s / %s\n", ft_uitoa_32bit(p->opt), ft_uitoa_32bit(BYTE_NONE));
	if (check_opt(p->opt) != E_TAB_NONE)
	{
		ft_printf("XML %s ERROR - Some flags are missing within <skybox> balise"
		" for none_skybox %d at line %d: %s\n", __FUNCTION__, p->i_cam, p->l,
		line);
		exit(-1);
	}
	s->skybox[p->i_skb] = new_skybox(s->skybox[p->i_skb].color1,
	s->skybox[p->i_skb].color2, s->skybox[p->i_skb].type);
	s->this_skb = &s->skybox[p->i_skb];
	s->sizeof_skb = p->i_skb;
	p->f = (void*)&bo_void;
	p->opt = 0;
}

void		bo_skybox_gradient(t_scene *s, t_parser *p, char *line)
{
	(void)line;
	p->i_skb++;
	printf("%s %d\n", __FUNCTION__, p->i_skb);
	if (p->i_skb >= p->lim_skb)
	{
		printf("realloc\n");
		p->lim_skb += 4;
		s->skybox = (t_skybox*)ft_realloc((void*)s->skybox, sizeof(t_skybox) *
		p->lim_skb);
	}
	p->grad = 1;
	s->skybox[p->i_skb].type = SKYBX_GRADIENT;
	p->f = (void*)&bo_void;
	p->opt |= p->byte[E_TAB_GRADIENT];
}

void		bo_skybox_none(t_scene *s, t_parser *p, char *line)
{
	(void)line;
	p->i_skb++;
	printf("%s %d\n", __FUNCTION__, p->i_skb);
	if (p->i_skb >= p->lim_skb)
	{
		printf("realloc\n");
		p->lim_skb += 4;
		if ((s->skybox = (t_skybox*)realloc(s->cam, p->lim_skb *
			sizeof(t_skybox))) == NULL)
		{
			ft_printf("Realloc %s ERROR - Something went wrong trying to "
			"realloc the given structure at skybox %d\n", __FUNCTION__,
			p->i_skb);
			exit(-1);
		}
	}
	p->grad = 1;
	s->skybox[p->i_skb].type = SKYBX_NONE;
	s->skybox[p->i_skb].color1 = v3_(0., 0., 0.);
	s->skybox[p->i_skb].color2 = v3_(0., 0., 0.);
	p->f = (void*)&bo_void;
	p->opt |= p->byte[E_TAB_NONE];
}
