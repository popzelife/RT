/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:15:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/08 17:27:03 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			xml_to_vec(char *line, t_vec3 *v)
{
	printf("%s\n", __FUNCTION__);
	int			i;
	int			j;
	char		*tmp;
	double		f;

	i = 0;
	j = 0;
	printf("%s\n", line);
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
	printf("%s\n", __FUNCTION__);
	if (!ft_isnumerical(line))
	{
		ft_printf("XML ERROR - This value: %s is not numerical\n", line);
		return (0);
	}
	*i = ft_atoi(line);
	printf("%d\n", *i);
	return (1);
}

int			xml_to_double(char *line, double *i)
{
	printf("%s\n", __FUNCTION__);
	if (!ft_isnumerical(line))
	{
		ft_printf("XML ERROR - This value: %s is not numerical\n", line);
		return (0);
	}
	*i = ft_atof(line);
	printf("%f\n", *i);
	return (1);
}

int			xml_get_value(char *line, char **value)
{
	*value = ft_strccstr(*value, line, '>', '<');
	if (!*value[0])
		return (0);
	return (1);
}
