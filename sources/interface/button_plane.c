/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:24:40 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 21:23:08 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		button_planepos(void *param)
{
	char			value[256];
	t_plane			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_plane*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new plane position:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->on_plane))
		{
			ft_printf("%-40s", "Try a different plane position:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_planeradius(void *param)
{
	char			value[256];
	t_plane			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_plane*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new plane radius:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
		&o->radius))
		{
			ft_printf("%-40s", "Try a different plane radius:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_planenormal(void *param)
{
	char			value[256];
	t_plane			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_plane*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new plane normal:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->normale))
		{
			ft_printf("%-40s", "Try a different plane normal:");
			fgets(value, 255, stdin);
		}
		v3_normalize(&o->normale);
		re_render_win(rt);
	}
}
