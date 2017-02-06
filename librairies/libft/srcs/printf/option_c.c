/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:23:48 by qfremeau          #+#    #+#             */
/*   Updated: 2016/08/17 11:15:32 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_c(t_spec *spec, t_print *print)
{
	intmax_t	p;

	if (spec->hljz == E_L || spec->hljz == E_LL)
	{
		spec->conv = 'C';
		conv_lc(spec, print);
	}
	else
	{
		p = get_param(spec->hljz, print->ap);
		(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - 1) : 0;
		ft_addto(p, print);
		(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
	}
}
