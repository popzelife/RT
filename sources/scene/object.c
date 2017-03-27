/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 00:30:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 14:19:51 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		*select_hit(const UCHAR t)
{
	void	*f;

	if (t == OBJ_SPHERE)
		f = (void*)&hit_sphere;
	else if (t == OBJ_PLANE)
		f = (void*)&hit_plane;
	else if (t == OBJ_CYLINDER)
		f = (void*)&hit_cylinder;
	else if (t == OBJ_CONE)
		f = (void*)&hit_cone;
	else if (t == OBJ_ELLIPSOID)
		f = (void*)&hit_ellispoid;
	else if (t == OBJ_PARABOLOID)
		f = (void*)&hit_parabloid;
	else if (t == OBJ_TRIANGLE)
		f = (void*)&hit_triangle;
	else
		f = (void*)&hit_sphere;
	return (f);
}

void		*select_scatter(const UCHAR t)
{
	void	*s;

	if (t == MAT_LAMBERT)
		s = (void*)&scatter_lambertian;
	else if (t == MAT_METAL)
		s = (void*)&scatter_metal;
	else if (t == MAT_DIELECT)
		s = (void*)&scatter_dielectric;
	else if (t == MAT_DIFF_LIGHT)
		s = (void*)&scatter_diffuse_light;
	else if (t == MAT_DIELECT)
		s = (void*)&scatter_dielectric;
	else
		s = (void*)&scatter_lambertian;
	return (s);
}

t_obj		new_object(void *obj, const UCHAR type_obj, t_mat *mat,
			const UCHAR type_mat)
{
	t_obj	o;

	o.type_obj = type_obj;
	o.p_obj = obj;
	o.hit = select_hit(type_obj);
	o.p_mat = mat;
	o.p_mat->type_mat = type_mat;
	o.p_mat->scatter = select_scatter(type_obj);
	if (type_mat == MAT_DIFF_LIGHT)
		o.p_mat->emitted = o.p_mat->albedo;
	else
		o.p_mat->emitted = v3_(0., 0., 0.);
	o.active = TRUE;
	o.visible = 1.;
	return (o);
}

static void	*select_obj(const UCHAR t)
{
	void	*o;

	if (t == OBJ_SPHERE)
		o = (void*)new_sphere(v3_(0., 0., 0.), .39);
	else if (t == OBJ_PLANE)
		o = (void*)new_plane(v3_(1., 0., 0.), v3_(0., 0., 0.), 0.);
	else if (t == OBJ_CYLINDER)
		o = (void*)new_cylinder(v3_(0., 1., 0.), v3_(0., -0.3, 0.), .3, .6);
	else if (t == OBJ_CONE)
		o = (void*)new_cone(v3_(0., 1., 0.), v3_(0., -0.2, 0.), .5, .6);
	else if (t == OBJ_TRIANGLE)
		o = (void*)new_triangle(v3_(0., -0.5, 0.6), v3_(0., 0.5, 0.6),
		v3_(0., 0, -0.4));
	else if (t == OBJ_ELLIPSOID)
		o = (void*)new_ellipsoid(v3_(0, 0., 60.), v3_(1., 0., 0.), 0.3, 0.5);
	else if (t == OBJ_PARABOLOID)
		o = (void*)new_paraboloid(v3_(0, 0., 60.), v3_(1., 0., 0.), 0.3);
	else
		o = (void*)new_sphere(v3_(0., 0., 0.), .39);
	return (o);
}

t_obj		copy_object(t_obj *obj)
{
	t_obj	o;

	o.type_obj = obj->type_obj;
	o.p_obj = select_obj(o.type_obj);
	o.hit = select_hit(o.type_obj);
	o.p_mat = new_material(obj->p_mat->albedo,
	obj->p_mat->t, obj->p_mat->m_text);
	o.p_mat->type_mat = obj->p_mat->type_mat;
	o.p_mat->scatter = select_scatter(o.type_obj);
	if (o.p_mat->type_mat == MAT_DIFF_LIGHT)
		o.p_mat->emitted = obj->p_mat->albedo;
	else
		o.p_mat->emitted = v3_(0., 0., 0.);
	return (o);
}
