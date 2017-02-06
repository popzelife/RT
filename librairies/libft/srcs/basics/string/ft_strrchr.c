/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:21:04 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/02 14:58:39 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		len_str;
	size_t		i;
	char		*ptr_str;

	len_str = ft_strlen(str);
	while (str[len_str] != c)
	{
		if (len_str == 0)
			return (NULL);
		len_str--;
	}
	i = 0;
	while (i != len_str)
	{
		str++;
		i++;
	}
	ptr_str = (char *)str;
	return (ptr_str);
}
