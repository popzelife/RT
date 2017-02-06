/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:37:16 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/02 14:40:22 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char const	*ptr_str;

	if (str == NULL)
		return (NULL);
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '\0')
		return (ft_strnew(0));
	ptr_str = str + ft_strlen(str) - 1;
	while (ft_isspace(*ptr_str) == 1)
		ptr_str--;
	return (ft_strsub(str, 0, ptr_str - str + 1));
}
