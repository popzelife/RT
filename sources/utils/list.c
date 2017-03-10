/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:46:53 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/10 00:16:14 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_iter		*lst_new_iter(t_iter **iter, int i, int x, int y)
{
	t_iter		*new;
	t_iter		*curs;

	new = NULL;
	new = (t_iter*)malloc(sizeof(t_iter));
	if (new == NULL)
		return (NULL);
	new->s = i;
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (*iter == NULL)
		return (new);
	else
	{
		curs = *iter;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new;
	}
	return (*iter);
}

t_thread	*lst_new_thread(t_thread **thread)
{
	t_thread		*new;
	t_thread		*curs;

	new = NULL;
	new = (t_thread*)malloc(sizeof(t_thread));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	if (*thread == NULL)
		return (new);
	else
	{
		curs = *thread;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new;
	}
	return (*thread);
}

t_surface	*lst_new_surface(t_surface **surface, t_surfparam param,
			SDL_Renderer *render, void (f)(SDL_Surface*, const SDL_Rect*,
			const int, void*))
{
	t_surface		*new;
	t_surface		*curs;

	new = NULL;
	new = (t_surface*)malloc(sizeof(t_surface));
	if (new == NULL)
		return (NULL);
	new->rect = esdl_copy_rect(*param.rect);
	new->surf = esdl_create_surface(new->rect->w, new->rect->h);
	f(new->surf, new->rect, param.color, param.param);
	new->text = SDL_CreateTextureFromSurface(render, new->surf);
	SDL_FreeSurface(new->surf);
	new->next = NULL;
	if (*surface == NULL)
		return (new);
	else
	{
		curs = *surface;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new;
	}
	return (*surface);
}

t_surface	*lst_new_image(t_surface **surface, t_surfparam param,
			SDL_Renderer *render, SDL_Texture *(f)(SDL_Renderer*, const char*,
			int*, int*))
{
	t_surface		*new;
	t_surface		*curs;
	t_imgparam		*p;

	p = (t_imgparam*)param.param;
	new = NULL;
	new = (t_surface*)malloc(sizeof(t_surface));
	if (new == NULL)
		return (NULL);
	new->rect = esdl_copy_rect(*param.rect);
	new->surf = NULL;
	new->text = f(render, p->path, &new->rect->w, &new->rect->h);
	new->next = NULL;
	if (*surface == NULL)
		return (new);
	else
	{
		curs = *surface;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new;
	}
	return (*surface);
}

t_string	*lst_new_string(t_string **string, t_strparam param,
			SDL_Renderer *render, t_text (f)(char*, t_font, int[2],
			SDL_Renderer*))
{
	t_string		*new;
	t_string		*curs;

	new = NULL;
	new = (t_string*)malloc(sizeof(t_string));
	if (new == NULL)
		return (NULL);
	new->text = f(param.string, param.font, param.xy, render);
	new->next = NULL;
	if (*string == NULL)
		return (new);
	else
	{
		curs = *string;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new;
	}
	return (*string);
}
