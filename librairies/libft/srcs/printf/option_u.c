/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 10:36:08 by qfremeau          #+#    #+#             */
/*   Updated: 2016/08/23 15:06:21 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_u(t_spec *spec, t_print *print)
{
	uintmax_t	p;

	p = get_uni_param(spec->hljz, print->ap);
	if (!(!p && !spec->prec))
	{
		(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw -
			(ft_max(spec->prec, ft_nbrlenbase(p, 10)))) : 0;
		apply_numprec(print, spec, ft_nbrlenbase(p, 10));
		ft_uitoabase(p, "0123456789", print, ft_nbrlenbase(p, 10));
		(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
	}
}

void	conv_lu(t_spec *spec, t_print *print)
{
	spec->hljz = ((spec->flags == E_L) ? E_LL : E_L);
	spec->conv = 'u';
	conv_u(spec, print);
}
