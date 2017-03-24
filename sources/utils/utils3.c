/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:25:16 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/01 18:38:47 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char		*ft_uitoa_32bit(UINT lvalue)
{
	int			x;
	char		*str;

	x = 31;
	str = ft_strdup("00000000000000000000000000000000");
	if (lvalue == 0)
		return (str);
	while (lvalue > 0)
	{
		if (lvalue % 2 >= 10)
			str[x] = lvalue % 2 - 10 + 'A';
		else
			str[x] = lvalue % 2 + '0';
		lvalue /= 2;
		--x;
	}
	return (str);
}

char		*ft_strtolower(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		++i;
	}
	return (s);
}

char		*ft_ltrim(char *s)
{
	while (ft_isspace(*s) != 0)
		s++;
	return (s);
}

char		*ft_rtrim(char *s)
{
	char	*back;

	back = s + ft_strlen(s);
	while (ft_isspace(*--back) != 0)
		*(back + 1) = '\0';
	return (s);
}

char		*ft_trim(char *s)
{
	return (ft_rtrim(ft_ltrim(s)));
}
