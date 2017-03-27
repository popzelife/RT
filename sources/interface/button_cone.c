/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:24:09 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 13:24:16 by vafanass         ###   ########.fr       */
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
		o = (t_cone*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cone position:");
		fgets(value, 255, stdin);
		while (!xml_to_vec(strtok(&value[0], "\n"), &o->cp))
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
		o = (t_cone*)rt->scene->this_obj->p_obj;
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

void		button_coneheight(void *param)
{
	char			value[256];
	t_cone			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cone*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cone radius:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
		&o->height))
		{
			ft_printf("%-40s", "Try a different cone radius:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}
