/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:23:24 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 14:21:33 by qfremeau         ###   ########.fr       */
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
		o = (t_cylinder*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder position:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"), &o->cp))
		{
			ft_printf("%-40s", "Try a different cylinder position:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

static void	button_cylindheight(t_rt *rt)
{
	char			value[256];
	t_cylinder		*o;

	o = (t_cylinder*)rt->scene->this_obj->p_obj;
	ft_printf("%-40s", "Enter a new cylinder height:");
	fgets(value, 255, stdin);
	while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
	&o->height))
	{
		ft_printf("%-40s", "Try a different cylinder height:");
		fgets(value, 255, stdin);
	}
}

void		button_cylindradius(void *param)
{
	char			value[256];
	t_cylinder		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cylinder*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder radius:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
		&o->radius))
		{
			ft_printf("%-40s", "Try a different cylinder radius:");
			fgets(value, 255, stdin);
		}
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
		o = (t_cylinder*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder normal:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->vertex))
		{
			ft_printf("%-40s", "Try a different cylinder normal:");
			fgets(value, 255, stdin);
		}
		v3_normalize(&o->vertex);
		re_render_win(rt);
	}
}
