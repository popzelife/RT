/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:18:42 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 22:55:28 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene			default_scene(t_rt *rt)
{
	t_scene		scene;

	scene.sizeof_obj = 7;
	rt->parser.lim_obj = 7;
	scene.obj = (t_obj*)malloc(scene.sizeof_obj * sizeof(t_obj));
	default_obj(&scene);
	default_cam(rt, &scene);
	default_skybox(rt, &scene);
	ft_printf("-- Initiated \"Default Simple\" scene --\n");
	return (scene);
}

static void		check_scene(t_rt *rt, t_scene *scene)
{
	if (scene->sizeof_cam == 0)
	{
		scene->sizeof_cam = 1;
		rt->parser.lim_cam = 1;
		if ((scene->cam = (t_cam*)realloc(scene->cam, scene->sizeof_cam
			* sizeof(t_cam))) == NULL)
			exit(-1);
		scene->cam[0] = set_camera(v3_(-5., 1., -10.), v3_(0., 0., 0.), v3_(0.,
		-1., 0.), camparam(60., (double)rt->r_view->w / (double)rt->r_view->h,
		.0, v3_length_double_(v3_sub_vec_(v3_(13., 2., 3.), v3_(0., 0., 0.)))));
		scene->this_cam = &scene->cam[0];
	}
	if (scene->sizeof_skb == 0)
	{
		scene->sizeof_skb = 1;
		rt->parser.lim_skb = 1;
		if ((scene->skybox = (t_skybox*)realloc(scene->skybox, scene->sizeof_skb
			* sizeof(t_skybox))) == NULL)
			exit(-1);
		scene->skybox[0] = new_skybox(v3_(0., 0., 0.), v3_(0., 0., 0.),
		SKYBX_NONE);
		scene->this_skb = &scene->skybox[0];
	}
}

t_scene			init_scene(t_rt *rt)
{
	t_scene		scene;

	if (rt->filename != NULL)
	{
		ft_printf("-- Parsing XML file \"%s\" --\n", rt->filename);
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
		check_scene(rt, &scene);
	}
	else
		return (random_scene_sphere(rt));
	return (scene);
}
