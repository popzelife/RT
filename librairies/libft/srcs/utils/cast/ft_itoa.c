/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:09:11 by qfremeau          #+#    #+#             */
/*   Updated: 2016/02/11 15:44:20 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		digits(int n, size_t *len, int *weight)
{
	*len = 2;
	if (n >= 0)
	{
		*len = 1;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		i;
	size_t		len;
	int			weight;
	char		*str;

	digits(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[i++] = -(n / weight % 10) + '0';
		weight /= 10;
	}
	str[i] = '\0';
	return (str);
}
