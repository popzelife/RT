/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_rmouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:48:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 20:45:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		right_rmouse(t_rt *rt)
{
	*rt->this_scene->this_cam = set_camera(
			v3_(rt->this_scene->this_cam->param.look_from.x + cos(M_PI / 12),
				rt->this_scene->this_cam->param.look_from.y,
				rt->this_scene->this_cam->param.look_from.z + cos(M_PI / 12)),
		rt->this_scene->this_cam->param.look_at,
		rt->this_scene->this_cam->param.v_up, rt->this_scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		left_rmouse(t_rt *rt)
{
	*rt->this_scene->this_cam = set_camera(
			v3_(rt->this_scene->this_cam->param.look_from.x + .5,
				rt->this_scene->this_cam->param.look_from.y,
				rt->this_scene->this_cam->param.look_from.z - .5),
		rt->this_scene->this_cam->param.look_at,
		rt->this_scene->this_cam->param.v_up, rt->this_scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		up_rmouse(t_rt *rt)
{
	*rt->this_scene->this_cam = set_camera(
			v3_(rt->this_scene->this_cam->param.look_from.x,
				rt->this_scene->this_cam->param.look_from.y + 1.,
				rt->this_scene->this_cam->param.look_from.z),
		rt->this_scene->this_cam->param.look_at,
		rt->this_scene->this_cam->param.v_up, rt->this_scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		down_rmouse(t_rt *rt)
{
	*rt->this_scene->this_cam = set_camera(
			v3_(rt->this_scene->this_cam->param.look_from.x,
				rt->this_scene->this_cam->param.look_from.y - 1.,
				rt->this_scene->this_cam->param.look_from.z),
		rt->this_scene->this_cam->param.look_at,
		rt->this_scene->this_cam->param.v_up, rt->this_scene->this_cam->param);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}
