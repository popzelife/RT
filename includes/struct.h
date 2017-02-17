/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popzelife <popzelife@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:35:06 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/17 11:36:44 by popzelife        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCT_H
# define _STRUCT_H

/*
  Ray
*/

typedef struct	s_ray
{
	t_vec3			orig;
	t_vec3			dir;
}				t_ray;

/*
  Param link object and material for rendering
*/

typedef struct s_hit
{
	double			t;
	double			u;
	double			v;
	int				i_lst;
	t_vec3			pos;
	t_vec3			normal;
	struct s_mat	*material;
}				t_hit;

/*
  Materials
*/

typedef struct s_mat
{
	UCHAR			type_mat;
	t_vec3			albedo;
	t_vec3			emitted;
	double			t;
	BOOL			(*scatter)(const t_ray*, const t_hit, t_vec3*, t_ray*);
}				t_mat;

/*
  Bounding box
*/

typedef struct	s_bound_box
{
	t_vec3			min;
	t_vec3			max;
}				t_bound_box;

/*
  Objects
*/

typedef struct	s_plane_xy
{
	double		x0;
	double		x1;
	double		y0;
	double		y1;
	double		k;
}				t_plane_xy;

typedef struct	s_sphere
{
	t_vec3			center;
	double			radius;
	double			radius2;
}				t_sphere;

/*
  Scene holder
*/

typedef struct s_obj
{
	UCHAR			type_obj;
	void			*p_obj;
	BOOL			(*hit)(void*, const t_ray*, const double, const double, \
		t_hit*);
	BOOL			(*bound_box)(void*, t_bound_box*, const double, const double);
	t_mat			*p_mat;
	char			*name;
	int				nb;
	float			visible;
	int				active;
}				t_obj;

typedef struct	s_cam
{
	t_vec3			low_left_corner;
	t_vec3			horizontal;
	t_vec3			vertical;
	t_vec3			orig;
	t_vec3			u;
	t_vec3			v;
	t_vec3			w;
	double			lens_radius;
	double			half_width;
	double			half_height;
	t_vec3			look_from;
	t_vec3			look_at;
	t_vec3			v_up;
	char			*name;
	int				nb;
	float			visible;
	int				active;
}				t_cam;

typedef struct	s_skybox
{
	t_vec3			color1;
	t_vec3			color2;
	BOOL			(*hit)(const struct s_skybox*, const t_ray*);
	char			*name;
	int				nb;
	int				active;
}				t_skybox;

typedef struct	s_scene
{
	t_cam			**cam;
	t_obj			**obj;
	t_skybox		**skybox;
	int				ambiance;
	int				obj_nb;
	int				cam_nb;
	int				skb_nb;
	char			lgt_flag;
	int				selected;
}				t_scene;

/*
  Param for menu with lists rendering
*/

typedef struct	s_surface
{
	SDL_Surface			*surf;
	SDL_Texture			*text;
	SDL_Rect			*rect;
	struct s_surface	*next;
}				t_surface;

typedef struct	s_string
{
	t_text				text;
	struct s_string		*next;
}				t_string;


typedef struct	s_surfparam
{
	SDL_Rect		*rect;
	int				color;
	void			*param;
	int				i_lst;
}				t_surfparam;

typedef struct	s_strparam
{
	t_font			font;
	char*			string;
	int				xy[2];
	int				i_lst;
}				t_strparam;

/*
  Button event and action
*/

typedef struct	s_button
{
	t_string			*string;
	t_surface			*surface;
	SDL_Rect			*rect;
	BOOL				hover;
	void				*param;
	void				(*action)(void*);
	struct s_button		*next;
}				t_button;

typedef struct	s_butnparam
{
	t_string		*string;
	t_surface		*surface;
	SDL_Rect		*rect;
	int				i_lst;
}				t_butnparam;

typedef struct	s_action
{
	void			*param;
	void			(*f)(void*);
}				t_action;

/*
  Mini 3D view rendering for menu
*/

typedef struct	s_viewparam
{
	t_scene			*scene;
	t_obj			*obj;

	char			str_obj[128];
	char			str_pos[128];
	char			str_param_o[128];
	char			str_mat[128];
	char			str_color[128];
	char			str_param_m[128];
}				t_viewparam;

typedef struct	s_imgparam
{
	char			*path;
}				t_imgparam;

/*
  Menu view
*/

typedef struct	s_panel
{
	t_surface		*lst_surf;
	t_string		*lst_string;
	t_button		*lst_button;

	t_viewparam		*viewparam;
	t_imgparam		*imgparam;

	t_font			title1;
	t_font			sub_title1;
	t_font			word1;
	t_text			objview;
}				t_panel;

/*
  Param for rendering
*/

typedef struct	s_iter
{
	int				s;
	int				x;
	int				y;
	struct s_iter	*next;
}				t_iter;

/*
  Raytracer main
*/

typedef struct	s_rt
{
	t_esdl			*esdl;
	t_scene			*scene;

	SDL_Window		*win_temp;
	SDL_Texture		*t_load;

	SDL_Rect		*r_view;
	SDL_Surface		*s_view;
	SDL_Texture		*t_view;

	SDL_Surface		*s_process;
	SDL_Texture		*t_process;

	SDL_Rect		*r_menu;
	SDL_Surface		*s_menu;
	SDL_Texture		*t_menu;

	t_panel			*panel;

	BOOL			render;
	BOOL			suspend;

	t_vec3			***tab;
	t_iter			*iter;
	void			*stack;
	int				m_thread;
	struct s_thread	*t;

	pthread_t		render_th;
	pthread_mutex_t	mutex;
	pthread_cond_t	display_cond;
}				t_rt;

/*
  Multithreading
*/

typedef struct	s_tharg
{
	t_rt		*rt;
	t_scene		*scene;

	int			*i;
	int			*j;
	int			*s;

	t_vec3		***tab;
}				t_tharg;

typedef struct	s_thread
{
	pthread_t			thread;
	pthread_attr_t		attr;
	t_tharg				arg;
	struct s_thread		*next;
}				t_thread;

#endif
