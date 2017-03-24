/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_rmouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:48:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/01 17:25:12 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		right_rmouse(t_rt *rt)
{
	*rt->scene->this_cam = set_camera(
			v3_(rt->scene->this_cam->param.look_from.x + cos(M_PI / 12),
				rt->scene->this_cam->param.look_from.y,
				rt->scene->this_cam->param.look_from.z + cos(M_PI / 12)),
			rt->scene->this_cam->param.look_at,
			rt->scene->this_cam->param.v_up, rt->scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		left_rmouse(t_rt *rt)
{
	*rt->scene->this_cam = set_camera(
			v3_(rt->scene->this_cam->param.look_from.x + .5,
				rt->scene->this_cam->param.look_from.y,
				rt->scene->this_cam->param.look_from.z - .5),
			rt->scene->this_cam->param.look_at,
			rt->scene->this_cam->param.v_up, rt->scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		up_rmouse(t_rt *rt)
{
	*rt->scene->this_cam = set_camera(
			v3_(rt->scene->this_cam->param.look_from.x,
				rt->scene->this_cam->param.look_from.y + 1.,
				rt->scene->this_cam->param.look_from.z),
			rt->scene->this_cam->param.look_at,
			rt->scene->this_cam->param.v_up, rt->scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		down_rmouse(t_rt *rt)
{
	*rt->scene->this_cam = set_camera(
			v3_(rt->scene->this_cam->param.look_from.x,
				rt->scene->this_cam->param.look_from.y - 1.,
				rt->scene->this_cam->param.look_from.z),
			rt->scene->this_cam->param.look_at,
			rt->scene->this_cam->param.v_up, rt->scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}
