/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:15:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/24 18:24:26 by qfremeau         ###   ########.fr       */
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
		ft_printf("PARSE ERROR - This value: %s is not numerical\n", line);
		return (0);
	}
	*i = ft_atoi(line);
	return (1);
}

int			xml_to_double(char *line, double *i)
{
	if (!ft_isnumerical(line))
	{
		ft_printf("PARSE ERROR - This value: %s is not numerical\n", line);
		return (0);
	}
	*i = atof(line);
	return (1);
}

int			xml_get_value(char *line, char **value)
{
	*value = ft_strccstr(*value, line, '>', '<');
	if (!*value[0])
		return (0);
	return (1);
}

int			xml_to_texture(char *line, UCHAR *i)
{
	 if (!ft_choose_texture(line))
	{
		ft_printf("XML ERROR - This value: %s is not a texture\n", line);
		return (0);
	}
	*i = ft_choose_texture(line);
	return(1);
}

int			xml_to_path(char *line, char **path)
{
	if (!ft_check_filename(line))
	{
		ft_printf("XML ERROR - This value: %s is not a valid path\n", line);
		return (0);
	}
	*path = strdup(line);
	return (1);
}


UCHAR		choose_material(char *line)
{
	if (ft_strcmp(line, "lambert") == 0)
		return (MAT_LAMBERT);
	if (ft_strcmp(line, "metal") == 0)
		return (MAT_METAL);
	if (ft_strcmp(line, "dielectric") == 0)
		return (MAT_DIELECT);
	if (ft_strcmp(line, "diffuse light") == 0)
		return (MAT_DIFF_LIGHT);
	return (0);
}

int			xml_to_material(char *line, UCHAR *i)
{
	if (!choose_material(line))
	{
		ft_printf("XML ERROR - This value: %s is not a texture\n", line);
		return (0);
	}
	*i = choose_material(line);
	return(1);
}

