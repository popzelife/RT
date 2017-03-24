/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_matrice_filter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:38:51 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/21 16:07:48 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	choose_matrice(t_matrixf *t)
{
	static int		i;

	if (i > 3 || i < 0)
		i = 0;
	if (i == 0)
		matrice_low_blur(t);
	if (i == 1)
		matrice_motion_blur(t);
	if (i == 2)
		matrice_sharpen(t);
	if (i == 3)
		matrice_emboss(t);
	i++;
}

void	matrice_low_blur(t_matrixf *t)
{
	double			*matrice;

	matrice = (double[]){
			0, 0, 1, 0, 0,
			0, 1, 1, 1, 0,
			1, 1, 1, 1, 1,
			0, 1, 1, 1, 0,
			0, 0, 1, 0, 0
			};
	t->matrice = malloc(sizeof(double) * 25);
	ft_memcpy(t->matrice, matrice, 25 * sizeof(double));
	t->size = 4;
	t->factor = 13.0;
	t->flag = 1;
}

void	matrice_motion_blur(t_matrixf *t)
{
	double			*matrice;

	matrice = (double[]){
		1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 1
		};
	t->matrice = malloc(sizeof(double) * 9 * 9);
	ft_memcpy(t->matrice, matrice, 9 * 9 * sizeof(double));
	t->size = 8;
	t->factor = 10.0;
	t->flag = 1;
}

void	matrice_sharpen(t_matrixf *t)
{
	double	*matrice;

	matrice = (double[]){
		-1, -1, -1, -1, -1,
		-1, 2, 2, 2, -1,
		-1, 2, 8, 2, -1,
		-1, 2, 2, 2, -1,
		-1, -1, -1, -1, -1,
		};
	t->matrice = malloc(sizeof(double) * 25);
	ft_memcpy(t->matrice, matrice, 25 * sizeof(double));
	t->size = 4;
	t->factor = 9.0;
	t->flag = 1;
}

void	matrice_emboss(t_matrixf *t)
{
	double			*matrice;

	matrice = (double[]){
		-1, -1, -1, -1, 0,
		-1, -1, -1, 0, 1,
		-1, -1, 0, 1, 1,
		-1, 0, 1, 1, 1,
		0, 1, 1, 1, 1
		};
	t->matrice = malloc(sizeof(double) * 25);
	ft_memcpy(t->matrice, matrice, 25 * sizeof(double));
	t->size = 4;
	t->factor = 8.0;
	t->flag = 1;
}
