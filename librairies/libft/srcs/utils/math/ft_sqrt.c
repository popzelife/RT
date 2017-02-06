/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:35:03 by qfremeau          #+#    #+#             */
/*   Updated: 2016/06/24 10:47:43 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Quake 3's Fast Inverse Square Root
*/

#include "libft.h"

double		ft_invsqrt(double x)
{
	int		i;
	double	xhalf;

	xhalf = 0.5f * x;
	i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(double*)&i;
	x = x * (1.5f - xhalf * x * x);
	x = x * (1.5f - (xhalf * x * x));
	return (x);
}

double		ft_sqrt(double x)
{
	return (1.0 / ft_invsqrt(x));
}
