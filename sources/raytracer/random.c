/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:54:32 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/01 19:27:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			f_rand(void)
{
	return ((double)rand() / (double)RAND_MAX);
}

t_vec3			random_in_unit_sphere(void)
{
	t_vec3		p;

	p = v3_(2.0 * f_rand() - 1.0, 2.0 * f_rand() - 1.0,
			2.0 * f_rand() - 1.0);
	while (v3_dot_double_(p, p) >= 1.0)
	{
		p = v3_(2.0 * f_rand() - 1.0, 2.0 * f_rand() - 1.0,
			2.0 * f_rand() - 1.0);
	}
	return (p);
}

t_vec3			random_in_unit_disk(void)
{
	t_vec3		p;

	p = v3_(2.0 * f_rand() - 1.0, 2.0 * f_rand() - 1.0, 0);
	while (v3_dot_double_(p, p) >= 1.0)
	{
		p = v3_(2.0 * f_rand() - 1.0, 2.0 * f_rand() - 1.0, 0);
	}
	return (p);
}

void			random_seed(char *s, const int len)
{
	static const char	alphanum[] = SEED;
	int					i;

	i = 0;
	while (i < len)
	{
		s[i] = alphanum[rand() % 62];
		++i;
	}
	s[len] = '\0';
}
