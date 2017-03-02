/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:35:06 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/02 22:42:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCT_H
# define _STRUCT_H

/*
** Ray
*/

typedef struct	s_ray
{
	t_vec3			orig;
	t_vec3			dir;
}				t_ray;

/*
** Param link object and material for rendering
*/

typedef struct	s_hit
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
** Materials
*/

typedef struct	s_mat
{
	UCHAR			type_mat;
	t_vec3			albedo;
	t_vec3			emitted;
	double			t;
	BOOL			(*scatter)(const t_ray, const t_hit, t_vec3*, t_ray*);
}				t_mat;

/*
** Objects
*/

typedef struct	s_plane
{
	t_vec3			normale;
	t_vec3			on_plane;
}				t_plane;

typedef struct	s_sphere
{
	t_vec3			center;
	double			radius;
	double			radius2;
}				t_sphere;

typedef struct	s_cylinder
{
	t_vec3			vertex;
	t_vec3			cp;
	double			m;
	double			radius;
	double			radius2;
	double			height;
}				t_cylinder;

typedef struct	s_cone
{
	t_vec3			vertex;
	t_vec3			cp;
	double			m;
	double			tang;
	double			height;
}				t_cone;

/*
** Discriminant
*/

typedef struct	s_discriminant
{
	t_vec3			oc;
	double			a;
	double			b;
	double			c;
	double			discriminant;
	double			sol;
	double			m;
}				t_discriminant;

/*
** Scene holder
*/

typedef struct	s_obj
{
	UCHAR			type_obj;
	void			*p_obj;
	BOOL			(*hit)(void*, const t_ray, const double[2], t_hit*);
	t_mat			*p_mat;
	char			*name;
	BOOL			active;
	double			visible;
}				t_obj;

typedef struct	s_camparam
{
	t_vec3			look_from;
	t_vec3			look_at;
	t_vec3			v_up;
	double			vfov;
	double			aspect;
	double			aperture;
	double			focus;
}				t_camparam;

typedef struct	s_cam
{
	t_camparam		param;
	t_vec3			low_left_corner;
	t_vec3			horizontal;
	t_vec3			vertical;
	t_vec3			origin;
	t_vec3			u;
	t_vec3			v;
	t_vec3			w;
	double			lens_radius;
	double			half_width;
	double			half_height;
	char			*name;
}				t_cam;

typedef struct	s_skybox
{
	t_vec3			color1;
	t_vec3			color2;
	t_vec3			(*hit)(const struct s_skybox*, const t_ray);
	char			*name;
}				t_skybox;

typedef struct	s_scene
{
	t_cam			*cam;
	t_obj			*obj;
	t_skybox		*skybox;
	int				ambiance;
	int				sizeof_obj;
	int				sizeof_cam;
	int				sizeof_skb;
	t_obj			*this_obj;
	t_cam			*this_cam;
	t_skybox		*this_skb;
}				t_scene;

/*
** Param for menu with lists rendering
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
	void			*param;
	int				color;
	int				i_lst;
}				t_surfparam;

typedef struct	s_strparam
{
	t_font			font;
	char			*string;
	int				xy[2];
	int				i_lst;
}				t_strparam;

/*
** Button event and action
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
** Mini 3D view rendering for menu
*/

typedef struct	s_viewparam
{
	t_scene			scene;
	char			str_obj[128];
	char			str_pos[128];
	char			str_rotate[128];
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
** Menu view
*/

typedef struct	s_menu
{
	t_surface		*nullsurf;
	t_string		*nullstring;
	SDL_Rect		rect;
	SDL_Rect		rect2;
}				t_menu;

typedef struct	s_panel
{
	t_surface		*lst_surf;
	t_string		*lst_string;
	t_button		*lst_button;

	t_viewparam		viewparam;
	t_imgparam		imgparam;

	t_font			title1;
	t_font			sub_title1;
	t_font			word1;
	t_text			objview;
}				t_panel;

/*
** Param for rendering
*/

typedef struct	s_render
{
	int				x;
	int				y;
	int				s;
	double			u;
	double			v;
	t_vec3			tmp;
}				t_render;

typedef struct	s_iter
{
	int				s;
	int				x;
	int				y;
	struct s_iter	*next;
}				t_iter;

/*
** Parser
*/

typedef struct	s_parser
{
	int					is_close;
	char				*bo[NB_BALISE];
	char				*bc[NB_BALISE];
	UINT				byte[NB_BALISE];
	UINT				flag;
	void				(*f)(t_scene*, char*);
}				t_parser;

/*
** Raytracer main
*/

typedef struct	s_rt
{
	t_esdl			*esdl;

	char			seed[8];
	char			*filename;
	t_parser		parser;
	t_scene			*scene;
	int				sizeof_scn;
	t_scene			*this_scene;

	SDL_Window		*win_temp;
	SDL_Texture		*tx_load;
	SDL_Rect		*r_view;
	SDL_Surface		*sr_view;
	SDL_Texture		*tx_view;
	SDL_Surface		*s_process;
	SDL_Texture		*tx_process;
	SDL_Rect		*r_menu;
	SDL_Surface		*sr_menu;
	SDL_Texture		*tx_menu;
	t_panel			panel;

	BOOL			render;
	BOOL			suspend;
	t_vec3			**tab;
	t_iter			*iter;
	int				limit_iter;
	void			*stack;
	int				m_thread;
	struct s_thread	*t;
	pthread_t		render_th;
	pthread_mutex_t	mutex;
	pthread_cond_t	display_cond;
}				t_rt;

/*
** Multithreading
*/

typedef struct	s_tharg
{
	t_rt		*rt;
	t_scene		*scene;

	int			*i;
	int			*j;
	int			*s;

	t_vec3		**tab;
}				t_tharg;

typedef struct	s_thread
{
	pthread_t			thread;
	pthread_attr_t		attr;
	t_tharg				arg;
	struct s_thread		*next;
}				t_thread;

#endif
