/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_lmouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:42:21 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/01 15:47:38 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		right_lmouse(t_rt *rt)
{
	{
		*rt->scene->this_cam = set_camera(
				v3_(rt->scene->this_cam->param.look_from.x - 1.,
					rt->scene->this_cam->param.look_from.y,
					rt->scene->this_cam->param.look_from.z),
				v3_(rt->scene->this_cam->param.look_at.x - 1.,
					rt->scene->this_cam->param.look_at.y,
					rt->scene->this_cam->param.look_at.z),
				rt->scene->this_cam->param.v_up, rt->scene->this_cam->param);
		udpate_view(rt);
		while (rt->iter->s == 0)
			render_low(rt);
		esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
		param_view_high(rt);
		rt->render = TRUE;
	}
}

void		left_lmouse(t_rt *rt)
{
	*rt->scene->this_cam = set_camera(
			v3_(rt->scene->this_cam->param.look_from.x + 1.,
				rt->scene->this_cam->param.look_from.y,
				rt->scene->this_cam->param.look_from.z),
			v3_(rt->scene->this_cam->param.look_at.x + 1.,
				rt->scene->this_cam->param.look_at.y,
				rt->scene->this_cam->param.look_at.z),
			rt->scene->this_cam->param.v_up, rt->scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		up_lmouse(t_rt *rt)
{
	*rt->scene->this_cam = set_camera(
			v3_(rt->scene->this_cam->param.look_from.x,
				rt->scene->this_cam->param.look_from.y + 1.,
				rt->scene->this_cam->param.look_from.z),
			v3_(rt->scene->this_cam->param.look_at.x,
				rt->scene->this_cam->param.look_at.y + 1.,
				rt->scene->this_cam->param.look_at.z),
			rt->scene->this_cam->param.v_up, rt->scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		down_lmouse(t_rt *rt)
{
	*rt->scene->this_cam = set_camera(
			v3_(rt->scene->this_cam->param.look_from.x,
				rt->scene->this_cam->param.look_from.y - 1.,
				rt->scene->this_cam->param.look_from.z),
			v3_(rt->scene->this_cam->param.look_at.x,
				rt->scene->this_cam->param.look_at.y - 1.,
				rt->scene->this_cam->param.look_at.z),
			rt->scene->this_cam->param.v_up, rt->scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}
