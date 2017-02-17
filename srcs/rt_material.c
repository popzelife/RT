/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:46:01 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/06 15:40:43 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
  Function pointers for scatter type not well working for now
*/

t_vec3		*reflect(const t_vec3 v, const t_vec3 n)
{
	t_vec3		*v1;
	t_vec3		*ret;

	v1 = v3_scale_vec(n, 2.0 * v3_dot_double(v, n));
	ret = v3_sub_vec(v, *v1);
	v3_free(v1);
	return (ret);
}

BOOL		refract(const t_vec3 v, const t_vec3 n, double ni_over_nt, \
	t_vec3 *refracted)
{
	t_vec3		*uv;
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*sum;
	double		discriminant;
	double		dt;

	uv = v3_unit_vec(v);
	dt = v3_dot_double(*uv, n);
	discriminant = 1.0 - ni_over_nt * ni_over_nt * (1.0 - dt * dt);
	if (discriminant > 0)
	{
		v1 = v3_scale_vec(n, dt);
		v2 = v3_sub_vec(*uv, *v1);
		v3_free(v1);
		v1 = v3_scale_vec(n, sqrt(discriminant));
		sum = v3_scale_vec(*v2 , ni_over_nt);
		v3_free(v2);
		v2 = v3_sub_vec(*sum, *v1);
		v3_free(v1);
		v3_free(sum);
		
		v3_set(refracted, sum->x, sum->y, sum->z);
		return (TRUE);
	}
	else
		return (FALSE);
}

t_mat		*new_material(t_vec3 *albedo, double t)
{
	t_mat		*m;

	m = malloc(sizeof(t_mat));
	m->albedo = albedo;
	m->t = t;
	return (m);
}

BOOL		scatter_lambertian(const t_ray *ray, const t_hit param, \
	t_vec3 *attenuation, t_ray *scattered)
{
	(void)		ray;
	t_vec3		*target;
	t_vec3		*v1;
	t_vec3		*v2;

	v1 = v3_add_vec(*(param.pos), *(param.normal));
	v2 = random_in_unit_sphere();
	target = v3_add_vec(*v1, *v2);
	v3_free(v1);
	v3_free(v2);
	scattered = new_ray(v3_copy_vec(*param.pos), \
		v3_sub_vec(*target, *(param.pos)));
	v3_free(target);
	attenuation = param.material->albedo;
	return (TRUE);
}

BOOL		scatter_metal(const t_ray *ray, const t_hit param, \
	t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*reflected;

	v1 = v3_unit_vec(*(ray->dir));
	reflected = reflect(*v1, *(param.normal));
	v3_free(v1);

	v1 = random_in_unit_sphere();
	v2 = v3_scale_vec(*v1, param.material->t);
	v3_free(v1);
	v1 =  v3_add_vec(*reflected, *v2);
	v3_free(v2);
	v3_free(reflected);

	scattered = new_ray(v3_copy_vec(*param.pos), v1);
	attenuation = param.material->albedo;

	return ((v3_dot_double(*(scattered->dir), *(param.normal)) > 0) ? 1 : 0);
}

BOOL		scatter_dielectric(const t_ray *ray, const t_hit param, \
	t_vec3 *attenuation, t_ray *scattered)
{

	return (FALSE);
}
