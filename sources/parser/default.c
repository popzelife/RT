/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:19:12 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 22:30:01 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		default_obj(t_scene *scene)
{
	scene->obj[0] = new_object((void*)new_plane(v3_(0., 1., 0.), v3_(0., 0.,
	0.)), OBJ_PLANE, new_material(v3_(1., .2, .2), 0.), MAT_LAMBERT);
	scene->obj[1] = new_object(new_cylinder(v3_(0., 1., 0.), v3_(0., 0., 0.),
	1., 1.), OBJ_CYLINDER, new_material(v3_(1., 1., 1.), 0.), MAT_DIFF_LIGHT);
	scene->obj[2] = new_object((void*)new_sphere(v3_(-4., 2., 0.), 1.),
	OBJ_SPHERE, new_material(v3_(.1, 1., 1.), .1), MAT_LAMBERT);
	scene->obj[3] = new_object((void*)new_sphere(v3_(0., 1., 4.), 1.),
	OBJ_SPHERE, new_material(v3_(1., .2, 1.), 0.), MAT_LAMBERT);
	scene->obj[4] = new_object((void*)new_sphere(v3_(-1., .5, -1.), .5),
	OBJ_SPHERE, new_material(v3_(1., 1., .2), 0.), MAT_LAMBERT);
	scene->obj[5] = new_object((void*)new_cone(v3_(0., 1., 0.), v3_(5., 1.,
	-2.), .2, 4.), OBJ_CONE, new_material(v3_(.3, .5, .1), 0.), MAT_METAL);
	scene->this_obj = &scene->obj[2];
}

void		default_cam(t_rt *rt, t_scene *scene)
{
	scene->sizeof_cam = 1;
	rt->parser.lim_cam = 1;
	scene->cam = (t_cam*)malloc(scene->sizeof_cam * sizeof(t_cam));
	scene->cam[0] = set_camera(v3_(-5., 1., -10.), v3_(0., 0., 0.), v3_(0., -1.,
	0.), camparam(60., (double)rt->r_view->w / (double)rt->r_view->h, .0,
	v3_lenght_double_(v3_sub_vec_(v3_(13., 2., 3.), v3_(0., 0., 0.)))));
	scene->this_cam = &scene->cam[0];
}

void		default_skybox(t_rt *rt, t_scene *scene)
{
	scene->sizeof_skb = 1;
	rt->parser.lim_skb = 1;
	scene->skybox = (t_skybox*)malloc(scene->sizeof_skb * sizeof(t_skybox));
	scene->skybox[0] = new_skybox(v3_(0., 0., 0.), v3_(0., 0., 0.),
	SKYBX_NONE);
	scene->this_skb = &scene->skybox[0];
}
