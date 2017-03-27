/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:21:54 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 23:38:14 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		button_matalbedo(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new material albedo:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_vec(strtok(&value[0], "\n"),
		&rt->this_scene->this_obj->p_mat->albedo)))
			ft_printf("%-40s", "Try a different material albedo:");
		if (value[0] <= 32)
			exit(-1);
		if (rt->this_scene->this_obj->p_mat->type_mat == MAT_DIFF_LIGHT)
			rt->this_scene->this_obj->p_mat->emitted =
			rt->this_scene->this_obj->p_mat->albedo;
		re_render_win(rt);
	}
}

void		button_mattexture(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new material texture:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_texture(strtok(&value[0], "\n"),
		&rt->this_scene->this_obj->p_mat->m_text->type_texture)))
			ft_printf("%-40s", "Try a different material texture:");
		if (value[0] <= 32)
			exit(-1);
		re_render_win(rt);
	}
}

void		button_mattype(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new material type:");
		while (fgets(value, 255, stdin) && (*value == '\n' || !xml_to_material(
		strtok(&value[0], "\n"), &rt->this_scene->this_obj->p_mat->type_mat)))
			ft_printf("%-40s", "Try a different material type:");
		if (value[0] <= 32)
			exit(-1);
		rt->this_scene->this_obj->p_mat->scatter = select_scatter(
		rt->this_scene->this_obj->p_mat->type_mat);
		if (rt->this_scene->this_obj->p_mat->type_mat == MAT_DIFF_LIGHT)
			rt->this_scene->this_obj->p_mat->emitted =
			rt->this_scene->this_obj->p_mat->albedo;
		else
			rt->this_scene->this_obj->p_mat->emitted = v3_(0., 0., 0.);
		if (rt->this_scene->this_obj->p_mat->type_mat == MAT_DIELECT)
			rt->this_scene->this_obj->p_mat->t = 1.;
		else if (rt->this_scene->this_obj->p_mat->type_mat == MAT_METAL)
			rt->this_scene->this_obj->p_mat->t = 0.;
		re_render_win(rt);
	}
}

void		button_matmetal(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new metal reflection:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_double(strtok(&value[0], "\n"),
		&rt->this_scene->this_obj->p_mat->t)))
			ft_printf("%-40s", "Try a different metal reflection:");
		if (value[0] <= 32)
			exit(-1);
		re_render_win(rt);
	}
}

void		button_matdielect(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new dielect refraction:");
		while (fgets(value, 255, stdin) && (value[0] == '\n' ||
		!xml_to_double(strtok(&value[0], "\n"),
		&rt->this_scene->this_obj->p_mat->t)))
			ft_printf("%-40s", "Try a different dielect refraction:");
		if (value[0] <= 32)
			exit(-1);
		re_render_win(rt);
	}
}
