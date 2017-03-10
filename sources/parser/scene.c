/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:18:42 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 22:36:18 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_scene	default_scene(t_rt *rt)
{
	t_scene		scene;

	scene.sizeof_obj = 6;
	rt->parser.lim_obj = 6;
	scene.obj = (t_obj*)malloc(scene.sizeof_obj * sizeof(t_obj));
	default_obj(&scene);
	default_cam(rt, &scene);
	default_skybox(rt, &scene);
	return (scene);
}

t_scene			init_scene(t_rt *rt)
{
	t_scene		scene;

	if (rt->filename != NULL)
	{
		scene.sizeof_cam = 0;
		rt->parser.lim_cam = 0;
		scene.cam = (t_cam*)malloc(scene.sizeof_cam * sizeof(t_cam));
		scene.sizeof_skb = 0;
		rt->parser.lim_skb = 0;
		scene.skybox = (t_skybox*)malloc(scene.sizeof_skb * sizeof(t_skybox));
		scene.sizeof_obj = 0;
		rt->parser.lim_obj = 0;
		scene.obj = (t_obj*)malloc(scene.sizeof_obj * sizeof(t_obj));
		read_xml(rt, &scene);
		if (scene.sizeof_cam == 0)
			default_cam(rt, &scene);
		if (scene.sizeof_skb == 0)
			default_skybox(rt, &scene);
	}
	else
		return (default_scene(rt));
	return (scene);
}
