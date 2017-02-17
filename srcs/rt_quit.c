/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:04:06 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/16 14:05:02 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		quit_rt(t_rt *rt)
{
	SDL_FreeSurface(rt->s_view);
	SDL_FreeSurface(rt->s_menu);
	SDL_DestroyTexture(rt->t_view);
	SDL_DestroyTexture(rt->t_menu);

	esdl_exit(rt->esdl);
}
