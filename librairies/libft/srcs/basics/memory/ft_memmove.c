/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:45:19 by qfremeau          #+#    #+#             */
/*   Updated: 2016/08/17 12:53:40 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_src > ptr_dst)
	{
		while (len > 0)
		{
			*ptr_dst++ = *ptr_src++;
			len--;
		}
	}
	else
	{
		ptr_src = ptr_src + len - 1;
		ptr_dst = ptr_dst + len - 1;
		while (len > 0)
		{
			*ptr_dst-- = *ptr_src--;
			len--;
		}
	}
	return (dst);
}
