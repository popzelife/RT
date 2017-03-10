/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:38:19 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/10 01:04:58 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		lst_set_surface(t_surface **surface, t_surfparam param,
			SDL_Renderer *render, void (f)(SDL_Surface*, const SDL_Rect*,
			const int, void*))
{
	t_surface		*curs;
	int				i;

	curs = *surface;
	i = 0;
	while (i++ < param.i_lst)
		curs = curs->next;
	if (param.rect != NULL)
	{
		free(curs->rect);
		curs->rect = esdl_copy_rect(*(param.rect));
	}
	curs->surf = esdl_create_surface(curs->rect->w, curs->rect->h);
	f(curs->surf, curs->rect, param.color, param.param);
	curs->text = SDL_CreateTextureFromSurface(render, curs->surf);
	SDL_FreeSurface(curs->surf);
}

void		lst_set_string(t_string **string, t_strparam param,
			SDL_Renderer *render, t_text (f)(char*, t_font, int[2],
			SDL_Renderer*))
{
	t_string		*curs;
	int				i;

	curs = *string;
	i = 0;
	while (i++ < param.i_lst)
		curs = curs->next;
	curs->text = f(param.string, param.font, param.xy, render);
}

t_button	*init_button(t_button *new)
{
	new = (t_button*)malloc(sizeof(t_button));
	if (new == NULL)
		return (NULL);
	new->surface = NULL;
	return (new);
}

t_button	*lst_new_button(t_button **button, t_butnparam param,
			SDL_Renderer *render, t_action action)
{
	t_button		*new;
	t_button		*curs;

	new = NULL;
	new = init_button(new);
	new->rect = *param.rect;
	new->surface = lst_new_surface(&new->surface, surfparam(&new->rect,
	0x88888888, NULL, 0), render, esdl_clear_surface);
	new->surface->next = param.surface;
	new->string = param.string;
	new->hover = FALSE;
	new->param = action.param;
	new->action = action.f;
	new->next = NULL;
	if (*button == NULL)
		return (new);
	else
	{
		curs = *button;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new;
	}
	return (*button);
}
