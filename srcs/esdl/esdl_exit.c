/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:29:11 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/06 12:31:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				esdl_exit(t_esdl *esdl)
{
	SDL_DestroyRenderer(esdl->eng.render);
	SDL_DestroyWindow(esdl->eng.win);
	if (esdl->ttf)
		TTF_Quit();
	SDL_Quit();
}
