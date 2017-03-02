/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:22:20 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 22:42:17 by qfremeau         ###   ########.fr       */
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

void		button_snap(void *param)
{
	static int	i = 0;
	char		name[32];
	t_rt		*rt;

	rt = (t_rt*)param;
	if (rt->suspend)
	{
		flash_snap(rt, 0);
		sprintf(name, "%s_snapshot%0.2d" ".BMP", rt->seed, i++);
		SDL_SaveBMP(rt->sr_view, name);
		flash_snap(rt, 1);
	}
}
