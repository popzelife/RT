/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:31:05 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/10 01:08:00 by qfremeau         ###   ########.fr       */
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

/*
** Parsing
*/

t_scene		init_scene(t_rt *rt);
void		default_cam(t_rt *rt, t_scene *scene);
void		default_skybox(t_rt *rt, t_scene *scene);
void		default_obj(t_scene *scene);

void		init_xml(t_rt *rt);
void		read_xml(t_rt *rt, t_scene *scene);

int			check_opt(UINT opt);
void		check_bo(t_parser *parser, UINT flag);
void		check_bc(t_parser *parser, UINT flag);
void		check_flag(t_parser *parser, UINT flag);
void		check_objsame(t_parser *p, char *line, char *str);

int			xml_get_value(char *line, char **value);
int			xml_to_int(char *line, int *i);
int			xml_to_double(char *line, double *i);
int			xml_to_vec(char *line, t_vec3 *v);

void		bo_cam_pos(t_scene *s, t_parser *p, char *line);
void		bo_cam_target(t_scene *s, t_parser *p, char *line);
void		bo_cam_rotate(t_scene *s, t_parser *p, char *line);
void		bo_cam_fov(t_scene *s, t_parser *p, char *line);
void		bo_cam_apert(t_scene *s, t_parser *p, char *line);
void		bo_sphere_pos(t_scene *s, t_parser *p, char *line);
void		bo_sphere_radius(t_scene *s, t_parser *p, char *line);
void		bo_plane_pos(t_scene *s, t_parser *p, char *line);
void		bo_plane_rotate(t_scene *s, t_parser *p, char *line);
void		bo_cone_pos(t_scene *s, t_parser *p, char *line);
void		bo_cone_radius(t_scene *s, t_parser *p, char *line);
void		bo_cone_rotate(t_scene *s, t_parser *p, char *line);
void		bo_cylinder_pos(t_scene *s, t_parser *p, char *line);
void		bo_cylinder_radius(t_scene *s, t_parser *p, char *line);
void		bo_cylinder_rotate(t_scene *s, t_parser *p, char *line);
void		bo_lambert_color(t_scene *s, t_parser *p, char *line);
void		bo_metal_color(t_scene *s, t_parser *p, char *line);
void		bo_metal_param(t_scene *s, t_parser *p, char *line);
void		bo_dielect_color(t_scene *s, t_parser *p, char *line);
void		bo_dielect_param(t_scene *s, t_parser *p, char *line);
void		bo_difflight_color(t_scene *s, t_parser *p, char *line);
void		bo_skgradient_color(t_scene *s, t_parser *p, char *line);
void		bo_sknone_color(t_scene *s, t_parser *p, char *line);
void		bo_void(t_scene *s, t_parser *p, char *line);

void		bo_cam(t_scene *s, t_parser *p, char *line);
void		bo_sphere(t_scene *s, t_parser *p, char *line);
void		bo_plane(t_scene *s, t_parser *p, char *line);
void		bo_cone(t_scene *s, t_parser *p, char *line);
void		bo_cylinder(t_scene *s, t_parser *p, char *line);
void		bo_lambert(t_scene *s, t_parser *p, char *line);
void		bo_metal(t_scene *s, t_parser *p, char *line);
void		bo_difflight(t_scene *s, t_parser *p, char *line);
void		bo_skybox_gradient(t_scene *s, t_parser *p, char *line);
void		bo_skybox_none(t_scene *s, t_parser *p, char *line);

void		bc_cam(t_scene *s, t_parser *p, char *line);
void		bc_sphere(t_scene *s, t_parser *p, char *line);
void		bc_plane(t_scene *s, t_parser *p, char *line);
void		bc_cone(t_scene *s, t_parser *p, char *line);
void		bc_cylinder(t_scene *s, t_parser *p, char *line);
void		bc_lambert(t_scene *s, t_parser *p, char *line);
void		bc_metal(t_scene *s, t_parser *p, char *line);
void		bc_difflight(t_scene *s, t_parser *p, char *line);
void		bc_skybox_gradient(t_scene *s, t_parser *p, char *line);
void		bc_skybox_none(t_scene *s, t_parser *p, char *line);

/*
** Menu rendering
*/

t_viewparam	new_viewparam(t_scene *scene);
void		set_viewparam(t_viewparam *p, t_rt *rt, int x, int y);

t_imgparam	new_imgparam(char *name);
void		set_imgparam(t_imgparam *param, char *name);

void		rt_miniview_surface(SDL_Surface *surf, const SDL_Rect *rect,
			const int color, void *param);

void		get_param_material(t_rt *rt);
void		get_param_object(t_rt *rt);
void		draw_bkg_surface(t_rt *rt, t_menu *m);
void		draw_text_surface(t_rt *rt);
void		draw_text_list_object(t_rt *rt);
void		draw_button_surface(t_rt *rt, t_menu *m);

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
void		render_highres(t_tharg *a);
void		render_lowres(t_tharg *a);

void		init_rt_color(t_vec3 *pos, t_vec3 *normal, double *t0, double *t1);
t_vec3		rt_color(t_ray ray, t_scene *scene, int depth, int max_depth);
BOOL		hit_list(t_scene *scene, const t_ray ray, const double t[2],
			t_hit *param);
void		multisampling(t_tharg *a);

SDL_Color	vec3_to_sdlcolor(t_vec3 v);
t_vec3		v3_multismp(t_vec3 c1, t_vec3 c2, t_vec3 c3, t_vec3 c4);

/*
** Multithreading
*/

void		event_loop(t_rt *rt);
void		render_loop(t_rt *rt);
void		display_loop(t_rt *rt);

void		thread_render(t_tharg *arg);
void		thread_render_low(t_tharg *arg);

void		set_thread_pos(t_tharg *arg);
void		set_thread(t_thread *t, t_rt *rt, int *i[2], int *s);
void		destroy_thread_attr(t_thread *t);
void		join_thread(t_thread *t);
void		set_thread_low(t_thread *t, t_rt *rt, int *i[2], int *s);
void		end_thread(t_tharg *arg);

/*
** Hook events
*/

void		rt_events(t_rt *rt, t_input *in);
void		display_rt(t_rt *rt);

void		draw_view(t_rt *rt);
void		draw_menu(t_rt *rt);
void		update_menu(t_rt *rt);
void		udpate_view(t_rt *rt);
void		param_view_high(t_rt *rt);

void		right_lmouse(t_rt *rt);
void		left_lmouse(t_rt *rt);
void		up_lmouse(t_rt *rt);
void		down_lmouse(t_rt *rt);
void		right_rmouse(t_rt *rt);
void		left_rmouse(t_rt *rt);
void		up_rmouse(t_rt *rt);
void		down_rmouse(t_rt *rt);

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
** Objects
*/

t_obj		new_object(void *obj, const UCHAR type_obj, t_mat *mat,
			const UCHAR type_mat);
t_obj		copy_object(t_obj *obj);

t_sphere	*new_sphere(const t_vec3 center, const double radius);
BOOL		hit_sphere(void *obj, const t_ray ray, const double t[2],
			t_hit *param);

t_plane		*new_plane(t_vec3 normale, t_vec3 on_plane);
BOOL		hit_plane(void *obj, const t_ray ray, const double t[2],
			t_hit *param);

t_cylinder	*new_cylinder(t_vec3 vertex, t_vec3 cp, const double raidus,
			const double height);
BOOL		hit_cylinder(void *obj, const t_ray ray, const double t[2],
			t_hit *param);

t_cone		*new_cone(t_vec3 vertex, t_vec3 cp, const double tang,
			const double height);
BOOL		hit_cone(void *obj, const t_ray ray, const double t[2],
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

char		*ft_uitoa_32bit(UINT lvalue);
char		*ft_strtolower(char *s);
char		*ft_rtrim(char *s);
char		*ft_ltrim(char *s);
char		*ft_trim(char *s);
int			ft_isnumerical(char *s);
char		*ft_strccstr(char *dst, char *src, char start, char end);
char		*ft_strcstr(char *dst, char *src, char end);
int			ft_strloopstr(const char *s1, const char *s2);
int			ft_strcmptab(char *line, char**tab, int size);

int			*ft_tab2(const int x, const int y);
void		settab2(int *xy, const int x, const int y);
t_surfparam	surfparam(SDL_Rect *rect, int color, void *param, int i);
t_strparam	strparam(char *string, t_font font, int rx[2], int i);
t_butnparam	butnparam(t_string *string, t_surface *surface, SDL_Rect *rect,
			int i);

t_iter		*lst_new_iter(t_iter **iter, int i, int x, int y);
t_thread	*lst_new_thread(t_thread **thread);
t_surface	*lst_new_surface(t_surface **surface, t_surfparam param,
			SDL_Renderer *render, void (f)(SDL_Surface*, const SDL_Rect*,
			const int, void*));
t_surface	*lst_new_image(t_surface **surface, t_surfparam param, SDL_Renderer
			*render, SDL_Texture *(f)(SDL_Renderer*, const char*, int*, int*));
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

t_vec3		random_in_unit_sphere(void);
t_vec3		random_in_unit_disk(void);

double		f_rand(void);

double		f_min(double const a, double const b);
double		f_max(double const a, double const b);

void		random_seed(char *s, const int len);

/*
** Exit
*/

void		quit_rt(t_rt *rt);

#endif
