/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:47:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/27 11:49:35 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_button	*init_button(t_button *new)
{
	new = (t_button*)malloc(sizeof(t_button));
	if (new == NULL)
		return (NULL);
	new->surface = NULL;
	new->enabled = TRUE;
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
	new->i_lst = param.i_lst;
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
