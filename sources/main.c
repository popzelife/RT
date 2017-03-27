/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:40:50 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 16:58:08 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	loop_hook(t_rt *rt)
{
	int			ret;

	pthread_mutex_init(&rt->mutex, NULL);
	pthread_cond_init(&rt->display_cond, NULL);
	if ((ret = pthread_create(&rt->render_th, NULL, (void*)render_loop,
		(void*)rt)) != 0)
	{
		ft_dprintf(2, "RT error %d - pthread_create failed at %s\n", ret,
		__FUNCTION__);
		exit(-1);
	}
	rt->suspend = TRUE;
	rt->esdl->eng.input->quit = 0;
	while (rt->esdl->run)
	{
		rt_events(rt, rt->esdl->eng.input);
		display_rt(rt);
		esdl_fps_limit(rt->esdl);
		esdl_fps_counter(rt->esdl);
	}
}

static void	init_firstrender(t_rt *rt)
{
	while (rt->iter->s <= 1)
	{
		progress_load(rt, 2);
		render_load(rt);
		render(rt);
	}
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	SDL_SetWindowOpacity(rt->esdl->eng.win, 0.);
	SDL_SetWindowSize(rt->esdl->eng.win, WIN_RX, WIN_RY);
	SDL_SetWindowPosition(rt->esdl->eng.win, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED);
	SDL_SetWindowMinimumSize(rt->esdl->eng.win, WIN_RX - 400, WIN_RY - 300);
	SDL_SetWindowOpacity(rt->esdl->eng.win, 1.);
	SDL_FreeSurface(rt->sr_bar);
	SDL_FreeSurface(rt->sr_progress);
	SDL_DestroyTexture(rt->tx_bar);
	SDL_DestroyTexture(rt->tx_progress);
	SDL_DestroyTexture(rt->tx_load);
	SDL_Delay(100);
	rt->tx_view = SDL_CreateTextureFromSurface(rt->esdl->eng.render,
	rt->sr_view);
	display_rt(rt);
}

static void	init_flag(t_rt *rt, int ac, char **av)
{
	rt->filename = NULL;
	if (ac > 1)
		rt->filename = ft_strdup(av[1]);
	rt->rx = MINWIN_RX;
	rt->ry = MINWIN_RY + TILE_RY;
	if (ac > 2)
	{
		rt->rx = MAXWIN_RX;
		rt->ry = MAXWIN_RY + TILE_RY;
	}
	rt->grab = 0;
}

int			main(int ac, char **av)
{
	t_rt		p_rt;
	t_rt		*rt;

	kernel_isopencl();
	rt = &p_rt;
	ft_printf("-- Initiating RT configuration --\n");
	init_flag(rt, ac, av);
	init_rt(rt);
	init_xml(rt);
	loading(rt);
	init_rand(rt);
	init_screen_buffer(rt);
	init_multithread(rt);
	ft_printf("-- Rendering first preview --\n\n");
	init_firstrender(rt);
	loop_hook(rt);
	quit_rt(rt);
	return (0);
}
