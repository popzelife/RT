/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:56:11 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/03 14:33:26 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	display_surf_string(t_rt *rt)
{
	t_surface		*surf_curs;
	t_string		*string_curs;

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
}

static void	display_button(t_rt *rt)
{
	t_button		*button_curs;

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
}

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
	SDL_RenderClear(rt->esdl->eng.render);
	if (rt->render)
	{
		rt->tx_view = SDL_CreateTextureFromSurface(rt->esdl->eng.render,
		rt->sr_view);
		rt->tx_process = SDL_CreateTextureFromSurface(rt->esdl->eng.render,
		rt->s_process);
		rt->render = FALSE;
	}
	SDL_RenderCopy(rt->esdl->eng.render, rt->tx_view, NULL, rt->r_view);
	SDL_RenderCopy(rt->esdl->eng.render, rt->tx_process, NULL, rt->r_view);
	display_surf_string(rt);
	display_button(rt);
	SDL_RenderPresent(rt->esdl->eng.render);
}
