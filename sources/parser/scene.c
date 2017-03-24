/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:18:42 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/23 19:23:01 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene	default_scene(t_rt *rt)
{
	t_scene		scene;

	scene.sizeof_obj = 7;
	rt->parser.lim_obj = 7;
	scene.obj = (t_obj*)malloc(scene.sizeof_obj * sizeof(t_obj));
	default_obj(&scene);
	default_cam(rt, &scene);
	default_skybox(rt, &scene);
	ft_printf("-- Initiated ''Default Simple'' scene --\n");
	return (scene);
}

t_scene			init_scene(t_rt *rt)
{
	t_scene		scene;

	if (rt->filename != NULL)
	{
		ft_printf("-- Parsing XML file ''%s'' --\n", rt->filename);
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
		//return (random_scene_sphere(rt));
		return (default_scene(rt));
	return (scene);
}
