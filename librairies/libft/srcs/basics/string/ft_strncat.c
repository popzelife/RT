/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:30:41 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/08 14:47:41 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t		len_dst;

	len_dst = ft_strlen(dst);
	ft_memcpy(dst + len_dst, src, len);
	dst[len_dst + len] = '\0';
	return (dst);
}
