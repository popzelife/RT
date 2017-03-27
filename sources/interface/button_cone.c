/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:24:09 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 21:49:59 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		button_conepos(void *param)
{
	char			value[256];
	t_cone			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cone*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cone position:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"), &o->cp))
		{
			ft_printf("%-40s", "Try a different cone position:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_conenormal(void *param)
{
	char			value[256];
	t_cone			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cone*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cone normal:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->vertex))
		{
			ft_printf("%-40s", "Try a different cone normal:");
			fgets(value, 255, stdin);
		}
		v3_normalize(&o->vertex);
		re_render_win(rt);
	}
}

static void	button_conetang(t_rt *rt)
{
	char			value[256];
	t_cone			*o;

	o = (t_cone*)rt->this_scene->this_obj->p_obj;
	ft_printf("%-40s", "Enter a new cone height:");
	fgets(value, 255, stdin);
	while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
	&o->height))
	{
		ft_printf("%-40s", "Try a different cone height:");
		fgets(value, 255, stdin);
	}
}

void		button_coneheight(void *param)
{
	char			value[256];
	t_cone			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cone*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cone tangent:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
		&o->tang))
		{
			ft_printf("%-40s", "Try a different cone tangent:");
			fgets(value, 255, stdin);
		}
		button_conetang(rt);
		re_render_win(rt);
	}
}
