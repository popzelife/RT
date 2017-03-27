/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:56:27 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 22:51:31 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	recalc_triangle_nornmal(t_triangle *t)
{
	t->e1 = v3_sub_vec_(t->v2, t->vertex);
	t->e2 = v3_sub_vec_(t->v3, t->vertex);
	t->normal = v3_cross_vec_(t->e1, t->e2);
	t->normal = v3_scale_vec_(t->normal, -1);
}

void		button_trianglepos1(void *param)
{
	char			value[256];
	t_triangle		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_triangle*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new triangle vertex:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' || !xml_to_vec(
		strtok(&value[0], "\n"), &o->vertex)))
			ft_printf("%-40s", "Try a different triangle vertex:");
		if (value[0] <= 32)
			exit(-1);
		recalc_triangle_nornmal(o);
		re_render_win(rt);
	}
}

void		button_trianglepos2(void *param)
{
	char			value[256];
	t_triangle		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_triangle*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new triangle vertex:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' || !xml_to_vec(
		strtok(&value[0], "\n"), &o->v2)))
			ft_printf("%-40s", "Try a different triangle vertex:");
		if (value[0] <= 32)
			exit(-1);
		recalc_triangle_nornmal(o);
		re_render_win(rt);
	}
}

void		button_trianglepos3(void *param)
{
	char			value[256];
	t_triangle		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_triangle*)rt->this_scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new triangle vertex:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' || !xml_to_vec(
		strtok(&value[0], "\n"), &o->v3)))
			ft_printf("%-40s", "Try a different triangle vertex:");
		if (value[0] <= 32)
			exit(-1);
		recalc_triangle_nornmal(o);
		re_render_win(rt);
	}
}
