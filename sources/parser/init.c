/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:54:16 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/25 19:54:07 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_xmlbo_bis(t_rt *rt, int i)
{
	rt->parser.bo[i++] = ft_strdup(BO_GRADIENT);
	rt->parser.bo[i++] = ft_strdup(BO_TEXTURE);
	rt->parser.bo[i++] = ft_strdup(BO_PATH);
	rt->parser.bo[i++] = ft_strdup(BO_NONE);
	rt->parser.nb_balise = i;
}

static void		init_xmlbo(t_rt *rt, int i)
{
	rt->parser.bo[i++] = ft_strdup("\0");
	rt->parser.bo[i++] = ft_strdup(BO_CAM);
	rt->parser.bo[i++] = ft_strdup(BO_OBJ);
	rt->parser.bo[i++] = ft_strdup(BO_SKYBOX);
	rt->parser.bo[i++] = ft_strdup(BO_FOV);
	rt->parser.bo[i++] = ft_strdup(BO_TARGET);
	rt->parser.bo[i++] = ft_strdup(BO_APERT);
	rt->parser.bo[i++] = ft_strdup(BO_SPHERE);
	rt->parser.bo[i++] = ft_strdup(BO_PLANE);
	rt->parser.bo[i++] = ft_strdup(BO_CYLINDER);
	rt->parser.bo[i++] = ft_strdup(BO_CONE);
	rt->parser.bo[i++] = ft_strdup(BO_ELLIPSOID);
	rt->parser.bo[i++] = ft_strdup(BO_PARABLOID);
	rt->parser.bo[i++] = ft_strdup(BO_TRIANGLE);
	rt->parser.bo[i++] = ft_strdup(BO_RADIUS);
	rt->parser.bo[i++] = ft_strdup(BO_POS);
	rt->parser.bo[i++] = ft_strdup(BO_ROTATE);
	rt->parser.bo[i++] = ft_strdup(BO_HEIGHT);
	rt->parser.bo[i++] = ft_strdup(BO_LAMBERT);
	rt->parser.bo[i++] = ft_strdup(BO_METAL);
	rt->parser.bo[i++] = ft_strdup(BO_DIELECT);
	rt->parser.bo[i++] = ft_strdup(BO_DIFFLIGHT);
	rt->parser.bo[i++] = ft_strdup(BO_COLOR);
	rt->parser.bo[i++] = ft_strdup(BO_PARAM);
	init_xmlbo_bis(rt, i);
}

static void		init_xmlbc_bis(t_rt *rt, int i)
{
	rt->parser.bc[i++] = ft_strdup(BC_GRADIENT);
	rt->parser.bc[i++] = ft_strdup(BC_TEXTURE);
	rt->parser.bc[i++] = ft_strdup(BC_PATH);
	rt->parser.bc[i++] = ft_strdup(BC_NONE);
	if (i != rt->parser.nb_balise)
		ft_printf("!WARNING! - Number of BO and BC balises are not equal\n");
}

static void		init_xmlbc(t_rt *rt, int i)
{
	rt->parser.bc[i++] = ft_strdup("\0");
	rt->parser.bc[i++] = ft_strdup(BC_CAM);
	rt->parser.bc[i++] = ft_strdup(BC_OBJ);
	rt->parser.bc[i++] = ft_strdup(BC_SKYBOX);
	rt->parser.bc[i++] = ft_strdup(BC_FOV);
	rt->parser.bc[i++] = ft_strdup(BC_TARGET);
	rt->parser.bc[i++] = ft_strdup(BC_APERT);
	rt->parser.bc[i++] = ft_strdup(BC_SPHERE);
	rt->parser.bc[i++] = ft_strdup(BC_PLANE);
	rt->parser.bc[i++] = ft_strdup(BC_CYLINDER);
	rt->parser.bc[i++] = ft_strdup(BC_CONE);
	rt->parser.bc[i++] = ft_strdup(BC_ELLIPSOID);
	rt->parser.bc[i++] = ft_strdup(BC_PARABLOID);
	rt->parser.bc[i++] = ft_strdup(BC_TRIANGLE);
	rt->parser.bc[i++] = ft_strdup(BC_RADIUS);
	rt->parser.bc[i++] = ft_strdup(BC_POS);
	rt->parser.bc[i++] = ft_strdup(BC_ROTATE);
	rt->parser.bc[i++] = ft_strdup(BC_HEIGHT);
	rt->parser.bc[i++] = ft_strdup(BC_LAMBERT);
	rt->parser.bc[i++] = ft_strdup(BC_METAL);
	rt->parser.bc[i++] = ft_strdup(BC_DIELECT);
	rt->parser.bc[i++] = ft_strdup(BC_DIFFLIGHT);
	rt->parser.bc[i++] = ft_strdup(BC_COLOR);
	rt->parser.bc[i++] = ft_strdup(BC_PARAM);
	init_xmlbc_bis(rt, i);
}

void			init_xml(t_rt *rt)
{
	register int		i;

	rt->parser.byte = (UINT*)malloc(sizeof(UINT) * (E_TAB_LAST));
	rt->parser.bo = (char**)malloc(sizeof(char*) * (E_TAB_LAST));
	rt->parser.bc = (char**)malloc(sizeof(char*) * (E_TAB_LAST));
	init_xmlbo(rt, 0);
	init_xmlbc(rt, 0);
	i = 1;
	rt->parser.byte[0] = 0;
	while (i < rt->parser.nb_balise)
	{
		rt->parser.byte[i] = (UINT)(1 << (i - 1));
		++i;
	}
	rt->parser.is_close = 0;
}
