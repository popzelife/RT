/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:25:16 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/28 23:28:02 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*double		ft_atof(char *s)
{
	double		power;
	double		val;
	int			sign;
	int			i;

	i = 0;
	while (ft_isspace(s[i]))
		++i;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;
	val = 0.0;
	while (ft_isdigit(s[i]))
		val *= 10.0 + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	power = 1.0;
	while (ft_isdigit(s[i]))
	{
		val *= 10.0 + (s[i++] - '0');
		power *= 10.0;
	}
	return (sign * val / power);
}*/

char*		ft_strtolower(char *s)
{
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	return (s);
}

char*		ft_ltrim(char *s)
{
	while(ft_isspace(*s) != 0)
		s++;
	return (s);
}

char*		ft_rtrim(char *s)
{
	char	*back;

	back = s + ft_strlen(s);
	while(ft_isspace(*--back) != 0)
		*(back + 1) = '\0';
	return (s);
}

char*		ft_trim(char *s)
{
	return (ft_rtrim(ft_ltrim(s)));
}
