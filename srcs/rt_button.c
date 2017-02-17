/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:22:20 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/21 17:23:58 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	button_render(void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
	if (!rt->suspend)
		rt->suspend = TRUE;
	else
		rt->suspend = FALSE;
}
