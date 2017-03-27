/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:22:20 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 21:37:43 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	flash_snap(t_rt *rt, int flag)
{
	static int	hex = 0x00ffffff;
	int			i;

	i = 0;
	while (i++ < 3)
	{
		if (flag == 0)
			hex += 0x22000000;
		else
			hex -= 0x22000000;
		esdl_clear_surface(rt->s_process, NULL, hex, NULL);
		rt->render = TRUE;
		display_rt(rt);
	}
}

void		button_render(void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
	if (!rt->suspend)
	{
		rt->limit_iter = rt->iter->s + 1;
		rt->suspend = TRUE;
	}
	else
		rt->suspend = FALSE;
}

void		button_filter(void *param)
{
	t_rt			*rt;
	t_filtervalue	f;
	t_matrixf		*t;
	static	int		reset = 0;

	rt = (void*)param;
	rt->suspend = TRUE;
	if (reset >= 8)
		reset = 0;
	if (reset == 0)
		filter_sepia(rt, &f);
	else if (reset == 1)
		filter_greyscale(rt, &f);
	else if (reset == 2)
		filter_negative(rt, &f);
	else if (reset >= 3 && reset <= 7)
	{
		t = malloc(sizeof(t_matrixf));
		choose_matrice(t);
		filter_matrice(rt, &f, *t);
		free_matrice(t);
	}
	reset++;
	rt->render = TRUE;
	display_rt(rt);
}

void		button_snap(void *param)
{
	static int	i = 0;
	char		name[32];
	t_rt		*rt;

	rt = (t_rt*)param;
	if (rt->suspend)
	{
		flash_snap(rt, 0);
		sprintf(name, "snapshot-" "%s" "_%0.2d" ".BMP", rt->seed, i++);
		SDL_SaveBMP(rt->sr_view, name);
		flash_snap(rt, 1);
	}
}

void		re_render_win(t_rt *rt)
{
	SDL_RaiseWindow(rt->esdl->eng.win);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	reset_view(rt);
	rt->render = TRUE;
}
