/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:23:48 by qfremeau          #+#    #+#             */
/*   Updated: 2016/08/17 11:10:54 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_s(t_spec *spec, t_print *print)
{
	int		i;
	int		neg;
	char	*s;

	if (spec->hljz == E_L || spec->hljz == E_LL)
	{
		spec->conv = 'S';
		conv_ls(spec, print);
	}
	else
	{
		i = 0;
		s = (char *)get_uni_param(E_LONG, print->ap);
		if (!s)
			s = "(null)";
		neg = (spec->prec > -1 ? (unsigned)ft_min(spec->prec, ft_strlen(s)) :
				ft_strlen(s));
		(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - neg) : 0;
		while (s[i] && (spec->prec--))
			ft_addto(s[i++], print);
		(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
	}
}
