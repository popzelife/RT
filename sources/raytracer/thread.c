/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:05:44 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/01 19:17:11 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Need sufficient malloc on each pthread #pthread_attr_getstack()
** Need also a pthread_mutex handling as rt->tab is shared between threads
*/

static void		join_render(t_rt *rt)
{
	t_thread	*th_curs;
	int			i;

	i = 0;
	th_curs = rt->t;
	while (i++ < rt->m_thread)
	{
		join_thread(th_curs);
		th_curs = th_curs->next;
	}
	i = 0;
	th_curs = rt->t;
	while (i++ < rt->m_thread)
	{
		destroy_thread_attr(th_curs);
		th_curs = th_curs->next;
	}
	ft_printf("Render pass # %3d/%3d %20s\r", (rt->iter->s == 1 ? rt->iter->s :
	rt->iter->s - 1), ALIASING, " ");
}

void			render(t_rt *rt)
{
	t_thread	*th_curs;
	t_iter		*it_curs;
	int			*tab[2];
	int			i;

	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	i = 0;
	th_curs = rt->t;
	it_curs = rt->iter;
	while (i++ < rt->m_thread)
	{
		tab[0] = &(it_curs->x);
		tab[1] = &(it_curs->y);
		set_thread(th_curs, rt, tab, &(it_curs->s));
		th_curs = th_curs->next;
		it_curs = it_curs->next;
	}
	join_render(rt);
}

void			render_low(t_rt *rt)
{
	t_thread	*th_curs;
	t_iter		*it_curs;
	int			*tab[2];
	int			i;

	i = 0;
	th_curs = rt->t;
	it_curs = rt->iter;
	while (i++ < rt->m_thread)
	{
		tab[0] = &(it_curs->x);
		tab[1] = &(it_curs->y);
		set_thread(th_curs, rt, tab, &(it_curs->s));
		th_curs = th_curs->next;
		it_curs = it_curs->next;
	}
	join_render(rt);
}
