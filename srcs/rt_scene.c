/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:26:38 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/07 16:53:07 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene		*new_scene(t_cam *cam, t_obj **obj, t_skybox *skybox)
{
	t_scene		*s;

	s = malloc(sizeof(t_scene));
	s->cam = cam;
	s->obj = obj;
	s->skybox = skybox;
	return (s);
}

t_scene		*init_scene(t_rt *rt)
{
	t_scene		*scene;
	t_obj		**obj;
	t_skybox	*skybox;
	t_cam		*cam;
	t_vec3		*temp;
	t_vec3		*cam_lookfrom;
	t_vec3		*cam_lookat;
	t_vec3		*cam_vup;
	double		focus;
	double		aperture;
	int			obj_nb;

	cam_lookfrom = v3_new_vec(13.0, 2.0, 3.0);
	cam_lookat = v3_new_vec(0.0, 0.0, 0.0);
	cam_vup = v3_new_vec(0.0, -1.0, 0.0);
	temp = v3_sub_vec(*cam_lookfrom, *cam_lookat);
	focus = v3_lenght_double(*temp);
	aperture = 0.0;
	v3_free(temp);
	cam = init_camera(cam_lookfrom, cam_lookat, cam_vup, 60.0, \
		(double)rt->r_view->w / (double)rt->r_view->h, aperture, focus);

	obj_nb = 3;
	obj = (t_obj**)malloc(obj_nb * sizeof(t_obj*));
	obj[0] = new_object((void*)new_sphere(v3_new_vec(0, -1000, 0), 1000), \
		OBJ_SPHERE, new_material(v3_new_vec(0.9, 0.0, 0.0), 0.0), \
		MAT_LAMBERT);
	obj[1] = new_object((void*)new_sphere(v3_new_vec(0, 2, 0), 2), \
		OBJ_SPHERE, new_material(v3_new_vec(0.1, 0.8, 1.0), 0.2), \
		MAT_LAMBERT);
	//obj[1] = new_object((void*)new_sphere(v3_new_vec(2, 2, 0), 2), \
		OBJ_PLANE_XY, new_material(v3_new_vec(0.5, 0.5, 1.0), 0.0), \
		MAT_LAMBERT);
	obj[2] = new_object((void*)new_sphere(v3_new_vec(-1, 7, -1), 2), \
		OBJ_SPHERE, new_material(v3_new_vec(4, 4, 4), NULL_PARAM), \
		MAT_DIFF_LIGHT);
	/*obj[0] = new_object(v3_new_vec(0.0, 0.0, 0.0), 0.2, OBJ_SPHERE, \
		v3_new_vec(1.0, 0.1, 0.1), MAT_LAMBERT, NULL_PARAM);
	obj[1] = new_object(v3_new_vec(0.0, -100.5, -1.0), 100.0, OBJ_SPHERE, \
		v3_new_vec(0.9, 0.9, 0.9), MAT_LAMBERT, NULL_PARAM);
	obj[2] = new_object(v3_new_vec(1.0, 0.0, -1.0), 0.5, OBJ_SPHERE, \
		v3_new_vec(0.7, 0.7, 0.7), MAT_METAL, 0.0);
	obj[3] = new_object(v3_new_vec(-1.0, 0.0, -1.0), 0.5, OBJ_SPHERE, \
		v3_new_vec(0.8, 0.8, 0.2), MAT_METAL, 0.5);
	obj[4] = new_object(v3_new_vec(0.0, 0.0, 1.0), 0.5, OBJ_SPHERE, \
		v3_new_vec(0.1, 0.1, 0.8), MAT_LAMBERT, NULL_PARAM);
	obj[5] = new_object(v3_new_vec(0.0, 0.0, -3.0), 2.0, OBJ_SPHERE, \
		v3_new_vec(0.1, 0.1, 0.1), MAT_LAMBERT, NULL_PARAM);
	obj[6] = new_object(v3_new_vec(150.0, 120.0, 150.0), 100.0, OBJ_SPHERE, \
		v3_new_vec(0.9, 0.5, 0.3), MAT_DIFF_LIGHT, NULL_PARAM);
	obj[6] = new_object(v3_new_vec(0.0, 1.5, 0.0), 0.5, OBJ_SPHERE, \
		v3_new_vec(0.8, 0.8, 0.8), MAT_DIFF_LIGHT, NULL_PARAM);*/

	skybox = new_skybox(v3_new_vec(0.5, 0.4, 0.1), \
		v3_new_vec(0.6, 1.0, 1.0), SKYBX_GRADIENT);

	scene = new_scene(cam, obj, skybox);
	scene->obj_nb = obj_nb;
	return (scene);
}
