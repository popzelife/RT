/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_skybox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:08:59 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/14 18:05:45 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	*select_skybox(const UCHAR t)
{
	void	*f;

	if (t == SKYBX_NONE)
		f = (void*)hit_none_skybox;
	else if (t == SKYBX_GRADIENT)
		f = (void*)&hit_gradient_skybox;
	else
		f = NULL;
	return (f);
}

t_skybox	*new_skybox(t_vec3 *color1, t_vec3 *color2, const UCHAR type)
{
	t_skybox		*s;

	s = (t_skybox*)malloc(sizeof(t_skybox));
	s->color1 = color1;
	s->color2 = color2;
	s->hit = select_skybox(type);
	return (s);
}

t_vec3		*hit_gradient_skybox(const t_skybox *box, const t_ray *ray)
{
	t_vec3		*ret;
	t_vec3		*unit_dir;
	t_vec3		*v1;
	t_vec3		*v2;
	double		t;

	unit_dir = v3_unit_vec(*ray->dir);
	t = 0.5 * (unit_dir->y + 1.0);
	v1 = v3_scale_vec(*(box->color1), 1.0 - t);
	v2 = v3_scale_vec(*(box->color2), t);
	ret = v3_add_vec(*v1, *v2);

	v3_free(unit_dir);
	v3_free(v1);
	v3_free(v2);
	return (ret);
}

t_vec3		*hit_none_skybox(const t_skybox *box, const t_ray *ray)
{
	(void)ray;
	(void)box;
	return (v3_new_vec(0.0, 0.0, 0.0));
}
