/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:40:04 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/02 14:59:49 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
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
		new_str[i] = f(new_str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
