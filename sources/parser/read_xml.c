/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_xml.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:38:43 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/09 22:02:55 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_parser(t_rt *rt)
{
	rt->parser.i_obj = -1;
	rt->parser.i_cam = -1;
	rt->parser.i_skb = -1;
	rt->parser.flag = 0;
	rt->parser.opt = 0;
	rt->parser.opt_m = 0;
	rt->parser.f = &bo_void;
	rt->parser.ratio = (double)rt->r_view->w / (double)rt->r_view->h;
	rt->parser.l = 1;
	rt->parser.obj = -1;
	rt->parser.mat = false;
	rt->parser.same = 1;
}

UINT			xml_to_flag(t_scene *scene, t_parser *parser, char *line)
{
	int		pos;

	if (!line)
		return (0);
	if ((pos = ft_strcmptab(line, parser->bo, parser->nb_balise)) != -1)
	{
		parser->is_close = 0;
		parser->flag |= parser->byte[pos];
		check_bo(parser, parser->byte[pos]);
		parser->f(scene, parser, line);
		check_flag(parser, parser->flag);
	}
	parser->f(scene, parser, line);
	if ((pos = ft_strcmptab(line, parser->bc, parser->nb_balise)) != -1)
	{
		parser->is_close = 1;
		parser->flag ^= parser->byte[pos];
		check_bc(parser, parser->byte[pos]);
		parser->f(scene, parser, line);
	}
	return (0);
}

void			read_xml(t_rt *rt, t_scene *scene)
{
	char	*line;
	int		fd;

	init_parser(rt);
	if ((fd = open(rt->filename, O_RDONLY)) == -1)
	{
		ft_printf("XML Parse ERROR - No such a file '%s'\n", rt->filename);
		exit(-1);
	}
	get_next_line(fd, &line);
	if (ft_strcmp(ft_trim(line), FILE_DEF) != 0)
	{
		ft_printf("XML Parse ERROR - '%s' is not a valid file\n", rt->filename);
		exit(-1);
	}
	free(line);
	while (get_next_line(fd, &line))
	{
		xml_to_flag(scene, &rt->parser, ft_strtolower(ft_trim(line)));
		free(line);
		rt->parser.l++;
	}
}
