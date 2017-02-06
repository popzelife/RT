/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 15:49:23 by qfremeau          #+#    #+#             */
/*   Updated: 2016/02/11 15:40:09 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr_src;

	i = 0;
	ptr_src = (unsigned char *)src;
	while (i != len)
	{
		ptr_src[i] = 0;
		i++;
	}
}
