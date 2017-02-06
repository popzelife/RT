/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:59:31 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/05 12:23:46 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*ret;
	char		*ptr_ret;
	size_t		i;

	ret = (void *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	ptr_ret = (char *)ret;
	i = 0;
	while (i != size)
	{
		ptr_ret[i] = (char)0;
		i++;
	}
	return (ret);
}
