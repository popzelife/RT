/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:43:22 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/18 12:22:16 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnchr(char c, char *ptr, int n)
{
	int		i;

	i = 0;
	while (n--)
	{
		if ((char)ptr[i] == c)
			return (i);
		++i;
	}
	return (-1);
}
