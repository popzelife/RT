/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 14:16:04 by qfremeau          #+#    #+#             */
/*   Updated: 2016/08/07 16:42:24 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addto(char c, t_print *print)
{
	if (print->pos == BUFFSIZE)
	{
		write(print->fd, print->buf, BUFFSIZE);
		print->pos = 0;
	}
	print->buf[print->pos] = c;
	++(print->pos);
	++(print->ret);
	--(print->spec->mfw);
}
