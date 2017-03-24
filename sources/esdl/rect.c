/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:44:05 by popzelife         #+#    #+#             */
/*   Updated: 2017/03/10 00:15:20 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Rect	*esdl_copy_rect(const SDL_Rect rect)
{
	SDL_Rect	*new;

	new = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	new->x = rect.x;
	new->y = rect.y;
	new->w = rect.w;
	new->h = rect.h;
	return (new);
}

SDL_Rect	esdl_rect(const int x, const int y, const int w, const int h)
{
	SDL_Rect	new;

	new.x = x;
	new.y = y;
	new.w = w;
	new.h = h;
	return (new);
}

SDL_Rect	esdl_fuse_rect(const SDL_Rect dst, const SDL_Rect src)
{
	SDL_Rect	new;

	new.x = src.x + dst.x;
	new.y = src.y + dst.y;
	new.w = src.w;
	new.h = src.h;
	return (new);
}
