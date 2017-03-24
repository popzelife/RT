/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:22:20 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/24 21:54:17 by qfremeau         ###   ########.fr       */
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
	static	int		reset;

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
		free(t->matrice);
		free(t);
	}
	//if (t->flag == 1)
	//	free(t->matrice);
	//-2(t);
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

void		button_close(void *param)
{
	t_rt			*rt;

	rt = (void*)param;
	rt->esdl->eng.input->quit = 1;
	rt->esdl->run = 0;
}

void		button_minus(void *param)
{
	t_rt			*rt;

	rt = (void*)param;
	SDL_MinimizeWindow(rt->esdl->eng.win);
}

static void	re_render_win(t_rt *rt)
{
	SDL_RaiseWindow(rt->esdl->eng.win);
	update_menu(rt);
	udpate_view(rt);
	while (rt->iter->s == 0)
		render_low(rt);
	esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
	param_view_high(rt);
	rt->render = TRUE;
}

void		button_spherepos(void *param)
{
	char			value[256];
	t_sphere		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_sphere*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new sphere position:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->center))
		{
			ft_printf("%-40s", "Try a different sphere position:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_spherenormal(void *param)
{
	char			value[256];
	t_sphere		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_sphere*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new sphere normal:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->normal))
		{
			ft_printf("%-40s", "Try a different sphere normal:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_sphereradius(void *param)
{
	char			value[256];
	t_sphere		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_sphere*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new sphere radius:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
		&o->radius))
		{
			ft_printf("%-40s", "Try a different sphere radius:");
			fgets(value, 255, stdin);
		}
		o->radius2 = o->radius * o->radius;
		re_render_win(rt);
	}
}

void		button_planepos(void *param)
{
	char			value[256];
	t_plane			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_plane*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new plane position:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->on_plane))
		{
			ft_printf("%-40s", "Try a different plane position:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_planeradius(void *param)
{
	char			value[256];
	t_plane			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_plane*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new plane radius:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
		&o->radius))
		{
			ft_printf("%-40s", "Try a different plane radius:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_planenormal(void *param)
{
	char			value[256];
	t_plane			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_plane*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new plane normal:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->normale))
		{
			ft_printf("%-40s", "Try a different plane normal:");
			fgets(value, 255, stdin);
		}
		v3_normalize(&o->normale);
		re_render_win(rt);
	}
}

void		button_conepos(void *param)
{
	char			value[256];
	t_cone			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cone*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cone position:");
		fgets(value, 255, stdin);
		while (!xml_to_vec(strtok(&value[0], "\n"), &o->cp))
		{
			ft_printf("%-40s", "Try a different cone position:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_conenormal(void *param)
{
	char			value[256];
	t_cone			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cone*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cone normal:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->vertex))
		{
			ft_printf("%-40s", "Try a different cone normal:");
			fgets(value, 255, stdin);
		}
		v3_normalize(&o->vertex);
		re_render_win(rt);
	}
}

void		button_coneheight(void *param)
{
	char			value[256];
	t_cone			*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cone*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cone radius:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
		&o->height))
		{
			ft_printf("%-40s", "Try a different cone radius:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_cylindpos(void *param)
{
	char			value[256];
	t_cylinder		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cylinder*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder position:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"), &o->cp))
		{
			ft_printf("%-40s", "Try a different cylinder position:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_cylindradius(void *param)
{
	char			value[256];
	t_cylinder		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cylinder*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder radius:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
		&o->radius))
		{
			ft_printf("%-40s", "Try a different cylinder radius:");
			fgets(value, 255, stdin);
		}
		o->radius2 = o->radius * o->radius;
		re_render_win(rt);
	}
}

void		button_cylindnormal(void *param)
{
	char			value[256];
	t_cylinder		*o;
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		o = (t_cylinder*)rt->scene->this_obj->p_obj;
		ft_printf("%-40s", "Enter a new cylinder normal:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
		&o->vertex))
		{
			ft_printf("%-40s", "Try a different cylinder normal:");
			fgets(value, 255, stdin);
		}
		v3_normalize(&o->vertex);
		re_render_win(rt);
	}
}

void		button_matalbedo(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new material albedo:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_vec(strtok(&value[0], "\n"),
			&rt->scene->this_obj->p_mat->albedo))
		{
			ft_printf("%-40s", "Try a different material albedo:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_mattype(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new material type:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_material(strtok(&value[0], "\n"),
			&rt->scene->this_obj->p_mat->type_mat))
		{
			ft_printf("%-40s", "Try a different material type:");
			fgets(value, 255, stdin);
		}
		rt->scene->this_obj->p_mat->scatter = select_scatter(
		rt->scene->this_obj->p_mat->type_mat);
		if (rt->scene->this_obj->p_mat->type_mat == MAT_DIFF_LIGHT)
			rt->scene->this_obj->p_mat->emitted =
			rt->scene->this_obj->p_mat->albedo;
		else if (rt->scene->this_obj->p_mat->type_mat == MAT_DIELECT)
			rt->scene->this_obj->p_mat->t = 1.;
		else if (rt->scene->this_obj->p_mat->type_mat == MAT_METAL)
			rt->scene->this_obj->p_mat->t = 0.;
		re_render_win(rt);
	}
}

void		button_matmetal(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new metal reflection:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
			&rt->scene->this_obj->p_mat->t))
		{
			ft_printf("%-40s", "Try a different metal reflection:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}

void		button_matdielect(void *param)
{
	char			value[256];
	t_rt			*rt;

	rt = (void*)param;
	if (rt->suspend)
	{
		ft_printf("%-40s", "Enter a new dielect refraction:");
		fgets(value, 255, stdin);
		while (value[0] == '\n' || !xml_to_double(strtok(&value[0], "\n"),
			&rt->scene->this_obj->p_mat->t))
		{
			ft_printf("%-40s", "Try a different dielect refraction:");
			fgets(value, 255, stdin);
		}
		re_render_win(rt);
	}
}