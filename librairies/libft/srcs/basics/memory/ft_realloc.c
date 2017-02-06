/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:00:11 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/21 13:56:29 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	ret = ft_memalloc(size);
	if (ptr && ret)
	{
		ft_memcpy(ret, ptr, size);
		free(ptr);
	}
	return (ret);
}
