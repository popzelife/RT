/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:16:09 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/02 14:56:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*ptr_src;

	ptr_src = (unsigned char *)src;
	while (len > 0)
	{
		if (*ptr_src == (unsigned char)c)
			return (ptr_src);
		ptr_src++;
		len--;
	}
	return (NULL);
}
