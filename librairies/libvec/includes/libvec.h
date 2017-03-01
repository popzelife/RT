/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:20:12 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/01 18:17:06 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>
# include <stdlib.h>

/*
** -----------------------------------------------------------------------------
** ------------------------------- Structures ----------------------------------
** -----------------------------------------------------------------------------
*/

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

/*
** -----------------------------------------------------------------------------
** ------------------------------- Functions -----------------------------------
** -----------------------------------------------------------------------------
*/

/*
** --------------------------------- vec3 --------------------------------------
*/

t_vec3			v3_(double const x, double const y, double const z);
t_vec3			*v3_new_vec(double const x, double const y, double const z);
t_vec3			*v3_copy_vec(t_vec3 const *v);
int				v3_duplicate(t_vec3 *v1, t_vec3 const *v2);
int				v3_set(t_vec3 *v, double const x, double const y,
				double const z);
int				v3_set_hex(t_vec3 *v, unsigned hex);
void			v3_free(t_vec3 *v);

t_vec3			v3_copy_vec_(t_vec3 const v);

double			v3_at(t_vec3 const *v, int const i);
void			v3_access(t_vec3 *v, int const i, double const f);

double			v3_at_(t_vec3 const v, int i);
void			v3_access_(t_vec3 *v, int const i, double const f);

t_vec3			*v3_add_vec(t_vec3 const *v1, t_vec3 const *v2);
t_vec3			*v3_sub_vec(t_vec3 const *v1, t_vec3 const *v2);
t_vec3			*v3_cross_vec(t_vec3 const *v1, t_vec3 const *v2);
t_vec3			*v3_multiply_vec(t_vec3 const *v1, t_vec3 const *v2);
t_vec3			*v3_scale_vec(t_vec3 const *v, double const c);
t_vec3			*v3_div_vec(t_vec3 const *v, double const c);

t_vec3			v3_add_vec_(t_vec3 const v1, t_vec3 const v2);
t_vec3			v3_sub_vec_(t_vec3 const v1, t_vec3 const v2);
t_vec3			v3_cross_vec_(t_vec3 const v1, t_vec3 const v2);
t_vec3			v3_multiply_vec_(t_vec3 const v1, t_vec3 const v2);
t_vec3			v3_scale_vec_(t_vec3 const v, double const c);
t_vec3			v3_div_vec_(t_vec3 const v, double const c);

void			v3_normalize(t_vec3 *v);
void			v3_negative(t_vec3 *v);

t_vec3			v3_normalize_(t_vec3 v);
void			v3_negative_(t_vec3 v);

double			v3_dot_double(t_vec3 const *v1, t_vec3 const *v2);
double			v3_magnitude_double(t_vec3 const *v);
double			v3_lenght_double(t_vec3 const *v);

double			v3_magnitude_double_(t_vec3 const v);
double			v3_lenght_double_(t_vec3 const v);
double			v3_dot_double_(t_vec3 const v1, t_vec3 const v2);

t_vec3			*v3_unit_vec(t_vec3 const *v);

t_vec3			v3_unit_vec_(t_vec3 const v);

#endif
