/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:00:00 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 11:05:56 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	button_cursor_list(t_rt *rt, t_input *in)
{
	t_button		*button_curs;

	button_curs = rt->panel.lst_button;
	while (button_curs != NULL)
	{
		if (button_curs->enabled && in->m_x > button_curs->rect.x &&
			in->m_x < (button_curs->rect.x + button_curs->rect.w) &&
			in->m_y > button_curs->rect.y &&
			in->m_y < (button_curs->rect.y + button_curs->rect.h))
		{
			SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
			break ;
		}
		else
			SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
		button_curs = button_curs->next;
	}
	if (in->m_x < rt->r_view->w && in->m_y < rt->r_view->h + TILE_RY
		&& in->m_y > TILE_RY)
		SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR));
}

void		button_list(t_rt *rt, t_input *in)
{
	t_button		*button_curs;

	button_curs = rt->panel.lst_button;
	while (button_curs != NULL)
	{
		if (button_curs->enabled && in->m_x > button_curs->rect.x &&
			in->m_x < (button_curs->rect.x + button_curs->rect.w) &&
			in->m_y > button_curs->rect.y &&
			in->m_y < (button_curs->rect.y + button_curs->rect.h))
		{
			button_curs->hover = TRUE;
			if (in->button[SDL_BUTTON_LEFT])
			{
				button_curs->action(button_curs->param);
				SDL_Delay(300);
			}
		}
		else
			button_curs->hover = FALSE;
		button_curs = button_curs->next;
	}
	button_cursor_list(rt, in);
}

void		button_left(t_rt *rt, t_input *in)
{
	if (in->m_x < rt->r_view->w && in->m_y < rt->r_view->h + TILE_RY
		&& in->m_y > TILE_RY && !rt->grab)
	{
		set_viewparam(&rt->panel.viewparam, rt, in->m_x, in->m_y - TILE_RY);
		update_menu(rt);
	}
	else if (in->m_x < WIN_RX - 80 && in->m_y < TILE_RY)
	{
		SDL_CaptureMouse(SDL_TRUE);
		SDL_GetGlobalMouseState(&rt->g_mx, &rt->g_my);
		rt->grab = 1;
	}
}

void		rt_events_bis(t_rt *rt, t_input *in)
{
	if (rt->suspend == TRUE && in->key[SDL_SCANCODE_UP] &&
			!in->button[SDL_BUTTON_RIGHT])
		up_lmouse(rt);
	else if (rt->suspend == TRUE && in->key[SDL_SCANCODE_DOWN] &&
			!in->button[SDL_BUTTON_RIGHT])
		down_lmouse(rt);
	else if (rt->suspend == TRUE && in->key[SDL_SCANCODE_RIGHT] &&
			in->button[SDL_BUTTON_RIGHT])
		right_rmouse(rt);
	else if (rt->suspend == TRUE && in->key[SDL_SCANCODE_LEFT] &&
			in->button[SDL_BUTTON_RIGHT])
		left_rmouse(rt);
	else if (rt->suspend == TRUE && in->key[SDL_SCANCODE_UP] &&
			in->button[SDL_BUTTON_RIGHT])
		up_rmouse(rt);
	else if (rt->suspend == TRUE && in->key[SDL_SCANCODE_DOWN] &&
			in->button[SDL_BUTTON_RIGHT])
		down_rmouse(rt);
	else if (in->key[SDL_SCANCODE_P])
		SDL_SetWindowPosition(rt->esdl->eng.win, WIN_M, WIN_M);
	if (!in->button[SDL_BUTTON_LEFT])
	{
		SDL_CaptureMouse(SDL_FALSE);
		rt->grab = 0;
	}
}

void		rt_events(t_rt *rt, t_input *in)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (rt->grab)
	{
		SDL_GetGlobalMouseState(&x, &y);
		SDL_GetWindowPosition(rt->esdl->eng.win, &rt->mx, &rt->my);
		SDL_SetWindowPosition(rt->esdl->eng.win, rt->mx + (x - rt->g_mx),
		rt->my + (y - rt->g_my));
	}
	esdl_update_events(in, &rt->esdl->run);
	if (in->quit)
		pthread_join(rt->render_th, NULL);
	button_list(rt, in);
	if (in->button[SDL_BUTTON_LEFT])
		button_left(rt, in);
	else if (rt->suspend == TRUE && in->key[SDL_SCANCODE_RIGHT] &&
			!in->button[SDL_BUTTON_RIGHT])
		right_lmouse(rt);
	else if (rt->suspend == TRUE && in->key[SDL_SCANCODE_LEFT] &&
			!in->button[SDL_BUTTON_RIGHT])
		left_lmouse(rt);
	rt_events_bis(rt, in);
}
