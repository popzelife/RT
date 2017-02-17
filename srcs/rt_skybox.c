/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_skybox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:08:59 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/17 18:58:28 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	*select_skybox(const UCHAR t)
{
	void	*f;

	if (t == SKYBX_NONE)
		f = (void*)&hit_none_skybox;
	else if (t == SKYBX_GRADIENT)
		f = (void*)&hit_gradient_skybox;
	else
		f = NULL;
	return (f);
}

t_skybox	new_skybox(t_vec3 color1, t_vec3 color2, const UCHAR type)
{
	t_skybox		s;

	s.color1 = color1;
	s.color2 = color2;
	s.hit = select_skybox(type);
	return (s);
}

t_vec3		hit_gradient_skybox(const t_skybox *box, const t_ray ray)
{
	t_vec3		unit_dir;
	double		t;

	unit_dir = v3_unit_vec_(ray.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	return (v3_add_vec_(v3_scale_vec_(box->color1, 1.0 - t),
	v3_scale_vec_(box->color2, t)));
}

t_vec3		hit_none_skybox(const t_skybox *box, const t_ray ray)
{
	(void)ray;
	(void)box;
	return (v3_(0.0, 0.0, 0.0));
}
