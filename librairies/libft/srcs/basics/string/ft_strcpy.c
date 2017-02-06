/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:40:21 by qfremeau          #+#    #+#             */
/*   Updated: 2016/08/17 13:02:33 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	len_src;
	size_t	i;

	if (!src || !dst)
		return (NULL);
	len_src = ft_strlen(src);
	i = 0;
	while (i <= len_src && src[i] != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
