/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:15:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 20:30:07 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			xml_to_vec(char *line, t_vec3 *v)
{
	int			i;
	int			j;
	char		*tmp;
	double		f;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			++i;
		tmp = ft_strcstr(tmp, &line[i], ' ');
		if (!xml_to_double(tmp, &f))
			return (0);
		v3_access_(v, j++, f);
		i += ft_strlen(tmp);
		free(tmp);
	}
	return (j == 3 ? 1 : 0);
}

int			xml_to_int(char *line, int *i)
{
	if (!ft_isnumerical(line))
	{
		ft_printf("XML ERROR - This value: %s is not numerical\n", line);
		return (0);
	}
	*i = ft_atoi(line);
	return (1);
}

int			xml_to_double(char *line, double *i)
{
	if (!ft_isnumerical(line))
	{
		ft_printf("XML ERROR - This value: %s is not numerical\n", line);
		return (0);
	}
	*i = ft_atof(line);
	return (1);
}

int			xml_get_value(char *line, char **value)
{
	*value = ft_strccstr(*value, line, '>', '<');
	if (!*value[0])
		return (0);
	return (1);
}
