/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:10:22 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/02 14:44:50 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atoi(const char *str)
{
	int			sign;
	char		*ptr_str;
	long		result;

	result = 0;
	ptr_str = (char *)str;
	while (ft_isspace((int)*ptr_str) != 0)
		ptr_str++;
	sign = (*ptr_str == '-') ? -1 : 1;
	ptr_str = (*ptr_str == '+' || *ptr_str == '-') ? ptr_str + 1 : ptr_str;
	while (*ptr_str >= '0' && *ptr_str <= '9')
	{
		result = result * 10 + *ptr_str - 48;
		ptr_str++;
	}
	result *= sign;
	return (result);
}
