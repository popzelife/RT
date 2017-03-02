/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:36:47 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 15:44:44 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Function pointers for scatter type not well working for now
*/

t_vec3		reflect(const t_vec3 v, const t_vec3 n)
{
	return (v3_sub_vec_(v, v3_scale_vec_(n, 2. * v3_dot_double_(v, n))));
}

BOOL		refract(const t_vec3 v, const t_vec3 n, double ni_over_nt,
			t_vec3 *refracted)
{
	t_vec3		uv;
	double		discriminant;
	double		dt;

	uv = v3_unit_vec_(v);
	dt = v3_dot_double_(uv, n);
	discriminant = 1. - ni_over_nt * ni_over_nt * (1. - dt * dt);
	if (discriminant > 0.)
	{
		*refracted = v3_sub_vec_(v3_scale_vec_(v3_sub_vec_(uv, v3_scale_vec_(
		n, dt)), ni_over_nt), v3_scale_vec_(n, sqrt(discriminant)));
		return (TRUE);
	}
	else
		return (FALSE);
}

BOOL		scatter_lambertian(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3		target;

	(void)ray;
	target = v3_add_vec_(v3_add_vec_(param.pos, param.normal),
	random_in_unit_sphere());
	*scattered = new_ray(param.pos, v3_sub_vec_(target, param.pos));
	*attenuation = param.material->albedo;
	return (TRUE);
}

BOOL		scatter_metal(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3		reflected;

	reflected = reflect(v3_unit_vec_(ray.dir), param.normal);
	*scattered = new_ray(param.pos, v3_add_vec_(reflected, v3_scale_vec_(
	random_in_unit_sphere(), param.material->t)));
	*attenuation = param.material->albedo;
	return ((v3_dot_double_(scattered->dir, param.normal) > 0) ? TRUE : FALSE);
}

BOOL		scatter_dielectric(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered)
{
	(void)ray;
	(void)param;
	(void)attenuation;
	(void)scattered;
	return (FALSE);
}
