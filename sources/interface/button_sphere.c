/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:25:12 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 22:46:15 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		button_spherepos(void *param)
{
	char			value[256];
	t_sphere		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_sphere*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new sphere position:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_vec(strtok(&value[0], "\n"), &o->center)))
			ft_printf("%-40s", "Try a different sphere position:");
		if (value[0] <= 32)
			exit(-1);
		re_render_win(rt);
	}
}

void		button_spherenormal(void *param)
{
	char			value[256];
	t_sphere		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_sphere*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new sphere normal:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_vec(strtok(&value[0], "\n"), &o->normal)))
			ft_printf("%-40s", "Try a different sphere normal:");
		if (value[0] <= 32)
			exit(-1);
		re_render_win(rt);
	}
}

void		button_sphereradius(void *param)
{
	char			value[256];
	t_sphere		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_sphere*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new sphere radius:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_double(strtok(&value[0], "\n"), &o->radius)))
			ft_printf("%-40s", "Try a different sphere radius:");
		if (value[0] <= 32)
			exit(-1);
		o->radius2 = o->radius * o->radius;
		re_render_win(rt);
	}
}
