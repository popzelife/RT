/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:57:46 by qfremeau          #+#    #+#             */
/*   Updated: 2016/08/23 15:00:00 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_abs(intmax_t nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int			ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int			ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
