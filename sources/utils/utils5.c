/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 01:07:19 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 23:35:34 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		settab2(int *xy, const int x, const int y)
{
	xy[0] = x;
	xy[1] = y;
}

UCHAR		ft_choose_texture(char *line)
{
	if (ft_strcmp(line, "checkboard") == 0)
		return (TEXT_CHCKBOARD);
	if (ft_strcmp(line, "liney") == 0)
		return (TEXT_LINEY);
	if (ft_strcmp(line, "linex") == 0)
		return (TEXT_LINEX);
	if (ft_strcmp(line, "rainbow") == 0)
		return (TEXT_RAINBOW);
	if (ft_strcmp(line, "image") == 0)
		return (TEXT_IMAGE);
	return (0);
}

int			ft_check_filename(char *line)
{
	int		fd;

	fd = open(line, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

void		free_matrice(t_matrixf *t)
{
	free(t->matrice);
	free(t);
}

void		reset_view(t_rt *rt)
{
	rt->this_scene->this_obj = rt->this_scene->this_obj;
	free(rt->panel.viewparam.scene.obj[0].p_obj);
	free(rt->panel.viewparam.scene.obj[0].p_mat);
	rt->panel.viewparam.scene.obj[0] = copy_object(rt->this_scene->this_obj);
	rt->panel.viewparam.scene.this_obj = rt->this_scene->this_obj;
	update_menu(rt);
}
