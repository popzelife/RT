/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:45:14 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 14:45:24 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_sitoa(intmax_t p, t_print *print, int l)
{
	char	c[l + 1];

	c[l] = 0;
	p = ft_abs(p);
	while (l--)
	{
		c[l] = p % 10 + '0';
		p /= 10;
	}
	l = 0;
	while (c[l])
	{
		ft_addto(c[l], print);
		++l;
	}
}

void			ft_uitoabase(uintmax_t p, char *base, t_print *print, int l)
{
	char	c[l + 1];
	char	baselen;

	baselen = ft_strlen(base);
	c[l] = 0;
	while (l--)
	{
		c[l] = base[p % baselen];
		p /= baselen;
	}
	l = 0;
	while (c[l])
	{
		ft_addto(c[l], print);
		++l;
	}
}
