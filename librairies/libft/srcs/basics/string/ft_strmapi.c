/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:48:26 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/02 14:59:40 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char		*new_str;
	size_t		i;

	if (str == NULL)
		return (NULL);
	new_str = ft_strdup((const char *)str);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (new_str[i] != '\0')
	{
		new_str[i] = f((unsigned int)i, new_str[i]);
		i++;
	}
	return (new_str);
}
