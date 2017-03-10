/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:37:29 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/10 01:05:17 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_imgparam		new_imgparam(char *name)
{
	t_imgparam		p;

	p.path = name;
	return (p);
}

void			set_imgparam(t_imgparam *param, char *name)
{
	param->path = name;
}

t_viewparam		new_viewparam(t_scene *scene)
{
	t_viewparam		p;

	p.scene.sizeof_cam = 1;
	p.scene.cam = (t_cam*)malloc(p.scene.sizeof_cam * sizeof(t_cam));
	p.scene.cam[0] = set_camera(v3_(-.6, .0, -.6), v3_(0., 0., 0.),
	v3_(0., -1., 0.), camparam(60., 1., 0., .5));
	p.scene.this_cam = &p.scene.cam[0];
	p.scene.sizeof_obj = 2;
	p.scene.obj = (t_obj*)malloc(p.scene.sizeof_obj * sizeof(t_obj));
	p.scene.obj[0] = copy_object(scene->this_obj);
	p.scene.obj[1] = new_object((void*)new_sphere(v3_(0., 1.5, 0.), .5),
	OBJ_SPHERE, new_material(v3_(1., 1., 1.), NULL_PARAM),
	MAT_DIFF_LIGHT);
	p.scene.this_obj = scene->this_obj;
	p.scene.sizeof_skb = 1;
	p.scene.skybox = (t_skybox*)malloc(p.scene.sizeof_skb * sizeof(t_skybox));
	p.scene.skybox[0] = new_skybox(v3_(.4, .4, .4), v3_(.9, .9, .9),
	SKYBX_GRADIENT);
	p.scene.this_skb = &p.scene.skybox[0];
	return (p);
}

void			set_viewparam(t_viewparam *p, t_rt *rt, int x, int y)
{
	t_hit		param;
	t_ray		ray;
	double		u;
	double		v;
	double		t[2];

	t[0] = .001;
	t[1] = FLT_MAX;
	u = (double)x / (double)rt->r_view->w;
	v = (double)y / (double)rt->r_view->h;
	ray = ray_from_cam(rt->scene->this_cam, u, v);
	param.pos = v3_(0., 0., 0.);
	param.normal = v3_(0., 0., 0.);
	if (hit_list(rt->scene, ray, t, &param))
	{
		free(p->scene.obj[0].p_obj);
		free(p->scene.obj[0].p_mat);
		p->scene.obj[0] = copy_object(&rt->scene->obj[param.i_lst]);
		p->scene.this_obj = &rt->scene->obj[param.i_lst];
	}
}

t_action		actionparam(void *param, void (f)(void*))
{
	t_action		p;

	p.param = param;
	p.f = f;
	return (p);
}
