/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:04:06 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 22:42:18 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		quit_rt(t_rt *rt)
{
	SDL_FreeSurface(rt->sr_view);
	SDL_FreeSurface(rt->sr_menu);
	SDL_DestroyTexture(rt->tx_view);
	SDL_DestroyTexture(rt->tx_menu);
	esdl_exit(rt->esdl);
}
