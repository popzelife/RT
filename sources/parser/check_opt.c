/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:38:04 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 19:45:36 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	check_opt_bis(UINT opt)
{
	if (opt == (BYTE_LAMBERT | BYTE_COLOR))
		return (E_TAB_LAMBERT);
	else if (opt == (BYTE_METAL | BYTE_COLOR))
		return (E_TAB_METAL);
	else if (opt == (BYTE_DIELECT | BYTE_PARAM))
		return (E_TAB_DIELECT);
	else if (opt == (BYTE_DIFFLIGHT | BYTE_COLOR))
		return (E_TAB_DIFFLIGHT);
	else if (opt == (BYTE_GRADIENT | BYTE_COLOR))
		return (E_TAB_GRADIENT);
	else if (opt == (BYTE_NONE))
		return (E_TAB_NONE);
	return (0);
}

int			check_opt(UINT opt)
{
	if (opt == (BYTE_CAM | BYTE_POS | BYTE_TARGET))
		return (E_TAB_CAM);
	else if (opt == (BYTE_SPHERE | BYTE_POS | BYTE_RADIUS))
		return (E_TAB_SPHERE);
	else if (opt == (BYTE_PLANE | BYTE_POS | BYTE_ROTATE))
		return (E_TAB_PLANE);
	else if (opt == (BYTE_CONE | BYTE_POS | BYTE_RADIUS | BYTE_ROTATE))
		return (E_TAB_CONE);
	else if (opt == (BYTE_CYLINDER | BYTE_POS | BYTE_RADIUS | BYTE_ROTATE))
		return (E_TAB_CYLINDER);
	else if (opt == (BYTE_ELLIPSOID | BYTE_POS | BYTE_RADIUS | BYTE_ROTATE |
				BYTE_HEIGHT))
		return (E_TAB_ELLIPSOID);
	else if (opt == (BYTE_PARABLOID | BYTE_POS | BYTE_ROTATE | BYTE_HEIGHT))
		return (E_TAB_PARABLOID);
	else if (opt == (BYTE_TRIANGLE | BYTE_POS))
		return (E_TAB_TRIANGLE);
	else
		return (check_opt_bis(opt));
}
