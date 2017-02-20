/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:56:11 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/20 17:12:05 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		render_loop(t_rt *rt)
{
	while (rt->esdl->run)
	{
		if (!rt->suspend)
		{
			render(rt);
			rt->render = TRUE;
		}
	}
	pthread_exit(NULL);
}

void		display_rt(t_rt *rt)
{
	t_surface		*surf_curs;
	t_string		*string_curs;
	t_button		*button_curs;

	SDL_RenderClear(rt->esdl->eng.render);
	if (rt->render)
	{
		rt->t_view = SDL_CreateTextureFromSurface(rt->esdl->eng.render, \
			rt->s_view);
		rt->t_process = SDL_CreateTextureFromSurface(rt->esdl->eng.render, \
			rt->s_process);
		rt->render = FALSE;
	}
	SDL_RenderCopy(rt->esdl->eng.render, rt->t_view, NULL, rt->r_view);
	SDL_RenderCopy(rt->esdl->eng.render, rt->t_process, NULL, rt->r_view);
	surf_curs = rt->panel.lst_surf;
	while (surf_curs != NULL)
	{
		SDL_RenderCopy(rt->esdl->eng.render, surf_curs->text, NULL, \
			surf_curs->rect);
		surf_curs = surf_curs->next;
	}
	string_curs = rt->panel.lst_string;
	while (string_curs != NULL)
	{
		SDL_RenderCopy(rt->esdl->eng.render, string_curs->text.text, NULL, \
			string_curs->text.rect);
		string_curs = string_curs->next;
	}
	button_curs = rt->panel.lst_button;
	while (button_curs != NULL)
	{
		if (button_curs->hover)
			SDL_RenderCopy(rt->esdl->eng.render, button_curs->surface->text, \
				NULL, button_curs->surface->rect);
		SDL_RenderCopy(rt->esdl->eng.render, button_curs->surface->next->text,\
			NULL, button_curs->surface->next->rect);
		SDL_RenderCopy(rt->esdl->eng.render, button_curs->string->text.text, \
			NULL, button_curs->string->text.rect);
		button_curs = button_curs->next;
	}
	SDL_RenderPresent(rt->esdl->eng.render);
}
