/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:25:15 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 23:07:12 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_scene_sphere(t_rt *rt, t_scene *scene)
{
	scene->sizeof_cam = 1;
	rt->parser.lim_cam = 1;
	scene->cam = (t_cam*)malloc(scene->sizeof_cam * sizeof(t_cam));
	scene->cam[0] = set_camera(v3_(13., 2., 3.), v3_(0., 0., 0.), v3_(0., -1.,
	0.), camparam(20., (double)rt->r_view->w / (double)rt->r_view->h, .1,
	v3_length_double_(v3_sub_vec_(v3_(13., 2., 3.), v3_(0., 0., 0.)))));
	scene->this_cam = &scene->cam[0];
	scene->sizeof_skb = 1;
	rt->parser.lim_skb = 1;
	scene->skybox = (t_skybox*)malloc(scene->sizeof_skb * sizeof(t_skybox));
	scene->skybox[0] = new_skybox(v3_(1., 1., 1.), v3_(.5, .7, 1.),
	SKYBX_GRADIENT);
	scene->this_skb = &scene->skybox[0];
	scene->sizeof_obj = 486;
	rt->parser.lim_obj = 500;
	scene->obj = (t_obj*)malloc(scene->sizeof_obj * sizeof(t_obj));
	scene->obj[0] = new_object((void*)new_sphere(v3_(0., -1000., 0.), 1000.),
	OBJ_SPHERE, new_material(v3_(.5, .5, .5), 0., NULL), MAT_LAMBERT);
}

static void	add_last_sphere(t_scene *scene, int *i)
{
	scene->obj[*i] = new_object((void*)new_sphere(v3_(0., 1., 0.), 1.),
	OBJ_SPHERE, new_material(v3_(1., 1., 1.), 1.5, NULL), MAT_DIELECT);
	*i += 1;
	scene->obj[*i] = new_object((void*)new_sphere(v3_(-4., 1., 0.), 1.),
	OBJ_SPHERE, new_material(v3_(.4, .2, .1), 0., new_texture(TEXT_LINEY, NULL))
	, MAT_LAMBERT);
	*i += 1;
	scene->obj[*i] = new_object((void*)new_sphere(v3_(4., 1., 0.), 1.),
	OBJ_SPHERE, new_material(v3_(.7, .6, .5), 0., NULL), MAT_METAL);
	scene->this_obj = &scene->obj[*i];
}

static void	random_sphere(t_scene *scene, int a, int b, int *i)
{
	double		choose_mat;
	t_vec3		center;

	choose_mat = f_rand();
	center = v3_(a + .9 * f_rand(), .2, b + .9 * f_rand());
	if (v3_length(v3_sub_vec_(center, v3_(4., .2, 0.))) > .9)
	{
		if (choose_mat < .8)
			scene->obj[*i] = new_object((void*)new_sphere(center, .2),
			OBJ_SPHERE, new_material(v3_(f_rand() * f_rand(), f_rand() *
			f_rand(), f_rand() * f_rand()), 0., NULL), MAT_LAMBERT);
		else if (choose_mat < .95)
			scene->obj[*i] = new_object((void*)new_sphere(center, .2),
			OBJ_SPHERE, new_material(v3_(.5 * (1 + f_rand()), .5 * (1 +
			f_rand()), .5 * (1 + f_rand())), .5 * f_rand(), NULL),
			MAT_METAL);
		else
			scene->obj[*i] = new_object((void*)new_sphere(center, .2),
			OBJ_SPHERE, new_material(v3_(1., 1., 1.), 1.5, NULL),
			MAT_DIELECT);
		*i += 1;
	}
}

t_scene		random_scene_sphere(t_rt *rt)
{
	t_scene		scene;
	int			i;
	int			a;
	int			b;

	init_scene_sphere(rt, &scene);
	i = 1;
	a = -11;
	while (a < 11)
	{
		b = -11;
		while (b < 11)
		{
			random_sphere(&scene, a, b, &i);
			++b;
		}
		++a;
	}
	add_last_sphere(&scene, &i);
	rt->parser.i_obj = i;
	rt->parser.i_cam = 1;
	rt->parser.i_skb = 1;
	ft_printf("-- Initiated ''Randomized Spheres'' scene --\n");
	return (scene);
}
