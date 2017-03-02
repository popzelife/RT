/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_thread_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:03:24 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/02 14:39:55 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		thread_render(t_tharg *arg)
{
	if (*(arg->s) == 0)
		render_lowres(arg);
	else
	{
		render_highres(arg);
		multisampling(arg);
	}
	set_thread_pos(arg);
	pthread_exit(NULL);
}

void		thread_render_low(t_tharg *arg)
{
	if (*(arg->s) == 0)
		render_lowres(arg);
	set_thread_pos(arg);
	pthread_exit(NULL);
}

void		set_thread_pos(t_tharg *arg)
{
	*(arg->i) += RT_SUBXY * arg->rt->m_thread;
	if (*(arg->i) > arg->rt->r_view->w * MSAMP)
	{
		*(arg->i) -= arg->rt->r_view->w * MSAMP;
		*(arg->i) -= (*(arg->i) % RT_SUBXY);
		*(arg->j) += RT_SUBXY;
	}
	if (*(arg->j) > arg->rt->r_view->h * MSAMP)
	{
		++(*(arg->s));
		*(arg->j) -= arg->rt->r_view->h * MSAMP;
		*(arg->j) -= (*(arg->j) % RT_SUBXY);
		*(arg->j) -= RT_SUBXY;
	}
}

void		end_thread(t_tharg *arg)
{
	arg->rt->suspend = TRUE;
}
