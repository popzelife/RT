/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:19:31 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/01 00:14:38 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define GNL_BUFFSIZE 128

int		get_next_line(int const fd, char **line);

#endif
