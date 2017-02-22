/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:31:05 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/22 16:52:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RT_H
# define _RT_H

# include "global.h"
# include "stdafx.h"

# include "kernel.h"

# include "struct.h"

/*
** Init RT
*/

void		init_rt(t_rt *rt);
void		loading(t_rt *rt);
void		init_rand(t_rt *rt);
void		init_screen_buffer(t_rt *rt);
void		init_multithread(t_rt *rt);

t_scene		init_scene(t_rt *rt);

/*
** Menu rendering
*/

t_viewparam	new_viewparam(t_scene *scene);
void		set_viewparam(t_viewparam *p, t_rt *rt, int x, int y);

t_imgparam	new_imgparam(char* name);
void		set_imgparam(t_imgparam *param, char* name);

void		rt_3dview_surface(SDL_Surface *surf, const SDL_Rect *rect,
			const int color, void *param);

/*
** Button action
*/

t_action	actionparam(void *param, void (f)(void*));

void		button_render(void *param);
void		button_snap(void *param);

/*
** Raytracer rendering
*/

void		render(t_rt *rt);
void		render_low(t_rt *rt);

t_vec3		rt_color(t_ray ray, t_scene *scene, int depth, int max_depth);
BOOL		hit_list(t_scene *scene, const t_ray ray, const double t[2],
			t_hit *param);

SDL_Color	vec3_to_sdlcolor(t_vec3 v);
t_vec3		v3_multisampling_x2(t_vec3 c1, t_vec3 c2, t_vec3 c3, t_vec3 c4);

/*
** Multithreading
*/

void		event_loop(t_rt *rt);
void		render_loop(t_rt *rt);
void		display_loop(t_rt *rt);

void		thread_render(t_tharg *arg);
void		thread_render_low(t_tharg *arg);

/*
** Hook events
*/

void		rt_events(t_rt *rt, t_input *in);

void		draw_view(t_rt *rt);
void		draw_menu(t_rt *rt);

void		update_menu(t_rt *rt);
void		udpate_view(t_rt *rt);
void		param_view_high(t_rt *rt);

void		reset_menu(t_rt *rt);

void		display_rt(t_rt *rt);

/*
** Cameras
*/

t_camparam	camparam(double vfov, double aspect, double aperture, double focus);

t_cam		set_camera(t_vec3 look_from, t_vec3 look_at, t_vec3 v_up,
			t_camparam param);

/*
** Skyboxes
*/

t_skybox	new_skybox(t_vec3 color1, t_vec3 color2, const UCHAR type);

t_vec3		hit_gradient_skybox(const t_skybox *box, const t_ray ray);
t_vec3		hit_none_skybox(const t_skybox *box, const t_ray ray);

/*
** Bounding box
*/

t_bound_box	new_bound_box(t_vec3 min, t_vec3 max);
BOOL		hit_bound_box(t_bound_box *box, const t_ray ray, double t_min,
			double t_max);
BOOL		surrounding_box(const t_bound_box box0, const t_bound_box box1);

/*
** Objects
*/

t_obj		new_object(void *obj, const UCHAR type_obj, t_mat *mat,
			const UCHAR type_mat);
t_obj		copy_object(t_obj *obj);

t_sphere	*new_sphere(t_vec3 center, const double radius);
BOOL		hit_sphere(void *obj, const t_ray ray, const double t[2],
			t_hit *param);
BOOL		bound_box_sphere(void *obj, t_bound_box *box, double const t0,
			double const t1);

t_plane		*new_plane(t_vec3 normale, t_vec3 on_plane);
BOOL		hit_plane(void *obj, const t_ray ray, const double t[2],
			t_hit *param);

t_cylinder	*new_cylinder(t_vec3 vertex, t_vec3 cp, const double raidus);
BOOL		hit_cylinder(void *obj, const t_ray ray, const double t[2],
			t_hit *param);

/*
** Materials
*/

t_mat		*new_material(t_vec3 albedo, double t);

t_vec3		reflect(const t_vec3 v, const t_vec3 n);
BOOL		scatter_lambertian(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered);
BOOL		scatter_metal(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered);
BOOL		scatter_dielectric(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered);

BOOL		scatter_none(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered);

/*
** Light Materials
*/

BOOL		scatter_diffuse_light(const t_ray ray, const t_hit param,
			t_vec3 *attenuation, t_ray *scattered);

/*
** Rays
*/

t_ray		new_ray(t_vec3 orig, t_vec3 dir);
t_vec3		ray_point_at(const t_ray ray, const double point);
t_ray		ray_from_cam(t_cam *cam, double s, double t);

/*
** Utils & lists
*/

int			*ft_tab2(const int x, const int y);
t_surfparam	surfparam(SDL_Rect *rect, int color, void *param, int i);
t_strparam	strparam(char* string, t_font font, int rx[2], int i);
t_butnparam	butnparam(t_string *string, t_surface *surface, SDL_Rect *rect,
			int i);

t_iter		*lst_new_iter(t_iter **iter, int i, int x, int y);
t_thread	*lst_new_thread(t_thread **thread);
t_surface	*lst_new_surface(t_surface **surface, t_surfparam param, SDL_Renderer
			*render, void (f)(SDL_Surface*, const SDL_Rect*, const int, void*));
t_surface	*lst_new_image(t_surface **surface, t_surfparam param, SDL_Renderer
			*render, SDL_Texture* (f)(SDL_Renderer*, const char*, int*, int*));
t_string	*lst_new_string(t_string **string, t_strparam param, SDL_Renderer
			*render, t_text (f)(char*, t_font, int[2], SDL_Renderer*));

t_button	*lst_new_button(t_button **button, t_butnparam param,
			SDL_Renderer *render, t_action action);

void		lst_set_surface(t_surface **surface, t_surfparam param, SDL_Renderer
			*render, void (f)(SDL_Surface*, const SDL_Rect*, const int, void*));
void		lst_set_string(t_string **string, t_strparam param, SDL_Renderer
			*render, t_text (f)(char*, t_font, int[2], SDL_Renderer*));

/*
** Randomize & Min/Max
*/

t_vec3		random_in_unit_sphere();
t_vec3		random_in_unit_disk();

double		f_random();

double		f_min(double const a, double const b);
double		f_max(double const a, double const b);

void		random_seed(char *s, const int len);

/*
** Exit
*/

void		quit_rt(t_rt *rt);

#endif
