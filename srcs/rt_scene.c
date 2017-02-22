/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:26:38 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/22 14:12:55 by nkhouide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene		init_scene(t_rt *rt)
{
	t_scene		scene;

	scene.sizeof_cam = 1;
	scene.cam = (t_cam*)malloc(scene.sizeof_cam * sizeof(t_cam));
	scene.cam[0] = set_camera(v3_(13., 2., 3.), v3_(0., 0., 0.),
	v3_(0., -1., 0.), camparam(60., (double)rt->r_view->w / (double)
	rt->r_view->h, 0., v3_lenght_double_(v3_sub_vec_(v3_(13., 2., 3.),
	v3_(0., 0., 0.)))));
	scene.this_cam = &scene.cam[0];

	scene.sizeof_obj = 3;
	scene.obj = (t_obj*)malloc(scene.sizeof_obj * sizeof(t_obj));
	
	scene.obj[0] = new_object((void*)new_plane(v3_(0., 1., 0.), v3_(0., 0., 0.)),
	OBJ_PLANE, new_material(v3_(1., .2, .2), 0.), MAT_LAMBERT);

//	scene.obj[1] = new_object((void*)new_sphere(v3_(0., 2., .8), 2.),
//	OBJ_SPHERE, new_material(v3_(.1, .8, 1.), .2), MAT_LAMBERT);

	scene.obj[1] = new_object((void*)new_cylindre(v3_(0., 1., .5), v3_(0., 1., -1.), .8),
	OBJ_CYLINDRE, new_material(v3_(.1, .8, 1.), .2), MAT_LAMBERT);

//	scene.obj[2] = new_object((void*)new_sphere(v3_(2., 2., 0.), 2.),
//	OBJ_SPHERE, new_material(v3_(.1, .8, 1.), .2), MAT_LAMBERT);

	scene.obj[2] = new_object((void*)new_sphere(v3_(-1., 7., -1.), 2.),
	OBJ_SPHERE, new_material(v3_(4., 4., 4.), NULL_PARAM), MAT_DIFF_LIGHT);

	scene.this_obj = &scene.obj[1];

	scene.sizeof_skb = 1;
	scene.skybox = (t_skybox*)malloc(scene.sizeof_skb * sizeof(t_skybox));
	scene.skybox[0] = new_skybox(v3_(.5, .4, .1), v3_(.6, 1., 1.),
	SKYBX_GRADIENT);
	scene.this_skb = &scene.skybox[0];

	return (scene);
}
