/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:14:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/27 16:13:19 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		read_xml(t_rt *rt, t_scene *scene)
{
	int		fd;
	char	*line;
	
	if ((fd = open(rt->filename, O_RDONLY) == -1))
		exit(-1);
	if (!get_next_line(fd, &line) || ft_strcmp(line, FILE_DEF));
		exit(-1);
	while (get_next_line(fd, &line));
	{
		if ()
	}
}