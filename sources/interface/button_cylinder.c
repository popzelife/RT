/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:23:24 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 22:52:13 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		button_cylindpos(void *param)
{
	char			value[256];
	t_cylinder		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cylinder*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder position:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_vec(strtok(&value[0], "\n"), &o->cp)))
			ft_printf("%-40s", "Try a different cylinder position:");
		if (value[0] <= 32)
			exit(-1);
		re_render_win(rt);
	}
}

static void	button_cylindheight(t_rt *rt)
{
	char			value[256];
	t_cylinder		*o;

	o = (t_cylinder*)rt->this_scene->this_obj->p_obj;
	ft_printf("%-40s", "Enter a new cylinder height:");
	while (fgets(value, 255, stdin) && (value[0] == '\n' ||
	!xml_to_double(strtok(&value[0], "\n"), &o->height)))
		ft_printf("%-40s", "Try a different cylinder height:");
	if (value[0] <= 32)
		exit(-1);
}

void		button_cylindradius(void *param)
{
	char			value[256];
	t_cylinder		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cylinder*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder radius:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_double(strtok(&value[0], "\n"), &o->radius)))
			ft_printf("%-40s", "Try a different cylinder radius:");
		if (value[0] <= 32)
			exit(-1);
		o->radius2 = o->radius * o->radius;
		button_cylindheight(rt);
		re_render_win(rt);
	}
}

void		button_cylindnormal(void *param)
{
	char			value[256];
	t_cylinder		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cylinder*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder normal:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_vec(strtok(&value[0], "\n"), &o->vertex)))
			ft_printf("%-40s", "Try a different cylinder normal:");
		if (value[0] <= 32)
			exit(-1);
		v3_normalize(&o->vertex);
		re_render_win(rt);
	}
}
