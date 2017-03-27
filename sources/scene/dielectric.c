/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:07:54 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 14:09:56 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		help_norme(t_dielec *d, const t_ray ray, const t_hit param)
{
	d->outw_normal = v3_negative_(param.normal);
	d->ni = param.material->t;
	d->cosine = v3_dot_double_(ray.dir, param.normal) / v3_length(ray.dir);
	d->cosine = sqrt(1.0 - d->ni * d->ni * (1.0 - d->cosine * d->cosine));
}

static double	f_schlick(double cosine, double ref_idx)
{
	double		r0;

	r0 = (1.0 - ref_idx) / (1.0 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1.0 - r0) * pow((1.0 - cosine), 5.0));
}

BOOL			refract(const t_vec3 v, const t_vec3 n, double ni_over_nt,
				t_vec3 *refracted)
{
	t_vec3		uv;
	double		discriminant;
	double		dt;

	uv = v3_unit_vec_(v);
	dt = v3_dot_double_(uv, n);
	discriminant = 1.0 - ni_over_nt * ni_over_nt * (1.0 - dt * dt);
	if (discriminant > 0.0)
	{
		*refracted = v3_sub_vec_(v3_scale_vec_(v3_sub_vec_(uv, v3_scale_vec_(n,
		dt)), ni_over_nt), v3_scale_vec_(n, sqrt(discriminant)));
		return (TRUE);
	}
	else
		return (FALSE);
}

BOOL			scatter_dielectric(const t_ray ray, const t_hit param,
				t_vec3 *attenuation, t_ray *scattered)
{
	t_dielec	d;

	d.reflected = reflect(ray.dir, param.normal);
	texture_it(param, attenuation);
	if (v3_dot_double_(ray.dir, param.normal) > 0.0)
	{
		help_norme(&d, ray, param);
	}
	else
	{
		d.outw_normal = param.normal;
		d.ni = 1.0 / param.material->t;
		d.cosine = -v3_dot_double_(ray.dir, param.normal) / v3_length(ray.dir);
	}
	if (refract(ray.dir, d.outw_normal, d.ni, &d.refracted))
		d.prob = f_schlick(d.cosine, param.material->t);
	else
		d.prob = 1.0;
	if (f_rand() < d.prob)
		*scattered = new_ray(param.pos, d.reflected);
	else
		*scattered = new_ray(param.pos, d.refracted);
	return (TRUE);
}
