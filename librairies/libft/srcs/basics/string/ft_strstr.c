/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 22:21:25 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/02 14:44:25 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		len_s2;
	char		*ptr_s1;

	len_s2 = ft_strlen(s2);
	if (len_s2 == 0)
	{
		ptr_s1 = (char *)s1;
		return (ptr_s1);
	}
	while (*s1)
	{
		if (ft_strncmp(s1, s2, 1) == 0)
		{
			if (ft_strncmp(s1, s2, len_s2) == 0)
			{
				ptr_s1 = (char *)s1;
				return (ptr_s1);
			}
		}
		s1++;
	}
	return (NULL);
}
