/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:54:32 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/18 18:22:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double				f_random()
{
	return ((double)rand() / (double)RAND_MAX);
}

t_vec3				random_in_unit_sphere()
{
	t_vec3		p;

	p = v3_(2.0 * f_random() - 1.0, 2.0 * f_random() - 1.0,
			2.0 * f_random() - 1.0);
	while (v3_dot_double_(p, p) >= 1.0)
	{
		p = v3_(2.0 * f_random() - 1.0, 2.0 * f_random() - 1.0,
			2.0 * f_random() - 1.0);
	}
	return (p);
}

t_vec3				random_in_unit_disk()
{
	t_vec3		p;

	p = v3_(2.0 * f_random() - 1.0, 2.0 * f_random() - 1.0, 0);
	while (v3_dot_double_(p, p) >= 1.0)
	{
		p = v3_(2.0 * f_random() - 1.0, 2.0 * f_random() - 1.0, 0);
	}
	return (p);
}
