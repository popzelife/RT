/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:16:20 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/08 17:39:51 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int			ft_isnumerical(char *s)
{
	int		coma;
	int		minus;
	int		digit;
	int		i;

	i = 0;
	digit = 0;
	coma = 0;
	minus = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '\t')
			++i;
		if (s[i] && (s[i] == '-' || s[i] == '+') && minus < 1
			&& !digit && !coma)
			++minus;
		else if (s[i] && s[i] == '.' && coma < 1)
			++coma;
		else if (s[i] && ft_isdigit(s[i]))
			++digit;
		else
			return (0);
		++i;
	}
	return (digit);
}

char		*ft_strccstr(char *dst, char *src, char start, char end)
{
	int			i;

	while (*src != start && *src)
		src++;
	if (*src == start)
		src++;
	i = 0;
	while (src[i] != end && src[i])
		++i;
	dst = ft_memalloc(i + 1);
	dst = ft_strncpy(dst, src, i);
	return (dst);
}

char		*ft_strcstr(char *dst, char *src, char end)
{
	int			i;

	i = 0;
	while (src[i] != end && src[i])
		++i;
	dst = ft_memalloc(i + 1);
	dst = ft_strncpy(dst, src, i);
	return (dst);
}

int			ft_strloopstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	size_t		len;

	len = ft_strlen(s2);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] != s2[j] && s1[i])
			++i;
		while (s1[i] == s2[j] && s1[i] && s2[j])
		{
			++i;
			++j;
			if (j == len)
				return (0);
		}
	}
	return (-1);
}

int			ft_strcmptab(char *line, char**tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if ((ft_strloopstr(line, tab[i])) == 0)
			return (i);
		++i;
	}
	return (-1);
}
