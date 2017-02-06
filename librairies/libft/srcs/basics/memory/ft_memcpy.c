/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:36:35 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/05 15:46:10 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (len > 0)
	{
		*ptr_dst++ = *ptr_src++;
		len--;
	}
	return (dst);
}
