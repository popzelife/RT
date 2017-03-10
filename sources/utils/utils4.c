/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:16:20 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 22:05:50 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int			ft_isnumerical(char *s)
{
	int		c;
	int		m;
	int		d;
	int		i;

	i = 0;
	d = 0;
	c = 0;
	m = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '\t')
			++i;
		if (s[i] && (s[i] == '-' || s[i] == '+') && m < 1
			&& !d && !c)
			++m;
		else if (s[i] && s[i] == '.' && c < 1 && ft_isdigit(s[i + 1]) && d)
			++c;
		else if (s[i] && ft_isdigit(s[i]))
			++d;
		else
			return (0);
		++i;
	}
	return (d);
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

int			ft_strcmptab(char *line, char **tab, int size)
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
