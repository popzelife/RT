/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:22:46 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/01 12:13:41 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		add_new_line(char **line, char *archive)
{
	char	*new_line;

	new_line = ft_strchr(archive, '\n');
	if (new_line)
	{
		*new_line = '\0';
		*line = ft_strdup(archive);
		new_line++;
		ft_memmove(archive, new_line, ft_strlen(new_line) + 1);
		return (1);
	}
	if (ft_strlen(archive) > 0)
	{
		*line = ft_strdup(archive);
		*archive = '\0';
		return (1);
	}
	return (0);
}

static t_list	*search_fd(t_list **archive, int fd)
{
	t_list		*node;

	node = *archive;
	if (node)
	{
		while (node)
		{
			if (fd == (int)node->content_size)
				return (node);
			node = node->next;
		}
	}
	node = ft_lstnew("\0", 1);
	node->content_size = fd;
	ft_lstadd(archive, node);
	return (node);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*archive;
	t_list			*node;
	char			buff[GNL_BUFFSIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	node = search_fd(&archive, fd);
	while (!ft_strchr((char*)node->content, '\n'))
	{
		ret = read(fd, buff, GNL_BUFFSIZE);
		if (ret == -1)
			return (ret);
		if (ret == 0)
			return (add_new_line(line, (char*)node->content));
		buff[ret] = '\0';
		tmp = ft_strjoin((char const*)node->content, buff);
		ft_strdel((char**)&(node->content));
		node->content = tmp;
	}
	return (add_new_line(line, (char*)node->content));
}
