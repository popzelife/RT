/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:17:20 by popzelife         #+#    #+#             */
/*   Updated: 2017/01/04 15:00:19 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw_menu(t_rt *rt)
{
	t_surface		*nullsurf = NULL;
	t_string		*nullstring = NULL;
	SDL_Rect		rect;
	SDL_Rect		rect2;

	rt->panel = malloc(sizeof(t_panel));
	rt->panel->lst_surf = NULL;
	rt->panel->lst_string = NULL;
	rt->panel->lst_button = NULL;
	rt->panel->viewparam = new_viewparam(rt->scene);
	rt->panel->imgparam = new_imgparam(IMG_ADDCUBE);
	rt->r_menu = malloc(sizeof (SDL_Rect));
	SDL_GetWindowSize(rt->win_temp, &(rt->r_menu->w), &(rt->r_menu->h));
	rt->r_menu->x = rt->r_menu->w - MENU_RX;
	rt->r_menu->y = 0;

	/*
	  Background surfaces
	*/

	//background
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		rt->r_menu, 0xff373737, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	//title1
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 0, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	//3dview
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(50, 50, 200, 200));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0, (void*)rt->panel->viewparam, 0), rt->esdl->eng.render, \
		rt_3dview_surface);

	//subtitle1
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 280, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff222222, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	//title2
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 480, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	//primitives
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(27, 520, 0, 0));
	rt->panel->lst_surf = lst_new_image(&(rt->panel->lst_surf), \
		surfparam(&rect, 0, (void*)rt->panel->imgparam, 0), \
		rt->esdl->eng.render, esdl_load_texture);

	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 + 27 * 2, 520, 0, 0));
	set_imgparam(rt->panel->imgparam, IMG_ADDPLANE);
	rt->panel->lst_surf = lst_new_image(&(rt->panel->lst_surf), \
		surfparam(&rect, 0, (void*)rt->panel->imgparam, 0), \
		rt->esdl->eng.render, esdl_load_texture);

	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 * 2 + 27 * 3, 520, 0, 0));
	set_imgparam(rt->panel->imgparam, IMG_ADDSPHERE);
	rt->panel->lst_surf = lst_new_image(&(rt->panel->lst_surf), \
		surfparam(&rect, 0, (void*)rt->panel->imgparam, 0), \
		rt->esdl->eng.render, esdl_load_texture);

	//title3
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 750, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	/*
	  Get param from object
	*/

	//Get object type
	if (rt->panel->viewparam->obj->type_obj == OBJ_SPHERE)
	{
		t_sphere		*sphere;

		sphere = (t_sphere*)rt->panel->viewparam->obj->p_obj;
		sprintf(rt->panel->viewparam->str_obj, "Sphere Param:");
		sprintf(rt->panel->viewparam->str_pos, "Position: %5s[%.3g; %.3g; %.3g]", \
			"", sphere->center->x, sphere->center->y, sphere->center->z);
		sprintf(rt->panel->viewparam->str_param_o, "Radius: %10.3g", \
			sphere->radius);
	}
	else if (rt->panel->viewparam->obj->type_obj == OBJ_PLANE_XY)
		sprintf(rt->panel->viewparam->str_obj, "Plane Param:");
	else if (rt->panel->viewparam->obj->type_obj == OBJ_CUBE)
		sprintf(rt->panel->viewparam->str_obj, "Cube Param:");

	//Get material type
	if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_METAL)
	{
		sprintf(rt->panel->viewparam->str_mat, "Material: %5sMetallic", "");
		sprintf(rt->panel->viewparam->str_param_m, "Fuzzy: %10.3g", \
			rt->panel->viewparam->obj->p_mat->t);
	}
	else if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_LAMBERT)
	{
		sprintf(rt->panel->viewparam->str_mat, "Material: %5sLambertian", "");
		sprintf(rt->panel->viewparam->str_param_m, "");
	}
	else if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_DIFF_LIGHT)
	{

		sprintf(rt->panel->viewparam->str_mat, "Material: %5sDiffuse Light", "");
		sprintf(rt->panel->viewparam->str_param_m, "");
	}
	sprintf(rt->panel->viewparam->str_color, "Color: %10srgb(%.3g, %.3g, %.3g)", \
		"", rt->panel->viewparam->obj->p_mat->albedo->x * 255.0, \
		rt->panel->viewparam->obj->p_mat->albedo->y * 255.0, \
		rt->panel->viewparam->obj->p_mat->albedo->z * 255.0);

	/*
	  Text & Title
	*/

	//Fonts
	rt->panel->title1 = esdl_load_font(QUICKFONT, 22, 0x222222ff);
	rt->panel->sub_title1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
	rt->panel->word1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);

	//Object preview
	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Object Setting:", rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 7), 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"2D view", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 220, 257), 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	//Param list object 
	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_obj, rt->panel->sub_title1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_pos, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 30), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_param_o, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 60), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_mat, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 90), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_color, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 120), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_param_m, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 150), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	//Add primitives
	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Primitives:", rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 487), 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Cube", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 32, 530 + 64) , 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Plane", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 29 * 2 + 64, \
		530 + 64), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Sphere", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 27 * 3 + 64 * \
		2, 530 + 64), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	//Rendering tools
	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Render Tools:", rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 757), 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	/*
	  Button interface
	*/

	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(24, 790, 0, 0));
	rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(15, 790, 82, 95));
	set_imgparam(rt->panel->imgparam, IMG_TOOLRENDER);
	rt->panel->lst_button = lst_new_button(&rt->panel->lst_button, \
	butnparam( \
		lst_new_string(&nullstring, strparam("Render", \
			rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 25, 800 + 64) , 0), \
			rt->esdl->eng.render, esdl_render_blendedtext), \
		lst_new_image(&nullsurf, surfparam(&rect, 0, (void*) \
			rt->panel->imgparam, 0), rt->esdl->eng.render, esdl_load_texture), \
		&rect2, 0), \
	rt->esdl->eng.render, actionparam((void*)rt, button_render));

	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 + 27 * 2, 790, 0, 0));
	rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(14 * 2 + 81, 790, 84, 95));
	set_imgparam(rt->panel->imgparam, IMG_TOOLSAVE);
	rt->panel->lst_button = lst_new_button(&rt->panel->lst_button, \
	butnparam( \
		lst_new_string(&nullstring, strparam("Snap", rt->panel->word1, \
			ft_tab2(WIN_RX - MENU_RX + 32 * 2 + 64, 800 + 64) , 0), \
			rt->esdl->eng.render, esdl_render_blendedtext), \
		lst_new_image(&nullsurf, surfparam(&rect, 0, (void*) \
			rt->panel->imgparam, 0), rt->esdl->eng.render, esdl_load_texture), \
		&rect2, 0), \
	rt->esdl->eng.render, actionparam((void*)rt, button_render));

	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 * 2 + 29 * 3, 790, 0, 0));
	rect2 = esdl_fuse_rect(*(rt->r_menu), esdl_rect(14 * 3 + 82 * 2, 790, 80, 95));
	set_imgparam(rt->panel->imgparam, IMG_TOOLPAINT);
	rt->panel->lst_button = lst_new_button(&rt->panel->lst_button, \
	butnparam( \
		lst_new_string(&nullstring, strparam("Paint", rt->panel->word1, \
			ft_tab2(WIN_RX - MENU_RX + 32 * 3 + 64 * 2, 800 + 64) , 0), \
			rt->esdl->eng.render, esdl_render_blendedtext), \
		lst_new_image(&nullsurf, surfparam(&rect, 0, (void*) \
			rt->panel->imgparam, 0), rt->esdl->eng.render, esdl_load_texture), \
		&rect2, 0), \
	rt->esdl->eng.render, actionparam((void*)rt, button_render));

}

void		update_menu(t_rt *rt)
{	
	SDL_GetWindowSize(rt->esdl->eng.win, &rt->r_menu->w, &rt->r_menu->h);
	rt->r_menu->x = rt->r_menu->w - MENU_RX;
	rt->r_menu->y = 0;

	rt->panel->imgparam = new_imgparam(IMG_ADDCUBE);

	/*
	  Update 3dview as pos 2
	*/

	lst_set_surface(&(rt->panel->lst_surf), surfparam( \
		NULL, 0, (void*)rt->panel->viewparam, 2), rt->esdl->eng.render, \
		rt_3dview_surface);

	/*
	  Get param from object
	*/

	//Get object type
	if (rt->panel->viewparam->obj->type_obj == OBJ_SPHERE)
	{
		t_sphere		*sphere;

		sphere = (t_sphere*)rt->panel->viewparam->obj->p_obj;
		sprintf(rt->panel->viewparam->str_obj, "Sphere Param:");
		sprintf(rt->panel->viewparam->str_pos, "Position: %5s[%.3g; %.3g; %.3g]", \
			"", sphere->center->x, sphere->center->y, sphere->center->z);
		sprintf(rt->panel->viewparam->str_param_o, "Radius: %10.3g", \
			sphere->radius);
	}
	else if (rt->panel->viewparam->obj->type_obj == OBJ_PLANE_XY)
		sprintf(rt->panel->viewparam->str_obj, "Plane Param:");
	else if (rt->panel->viewparam->obj->type_obj == OBJ_CUBE)
		sprintf(rt->panel->viewparam->str_obj, "Cube Param:");

	//Get material type
	if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_METAL)
	{
		sprintf(rt->panel->viewparam->str_mat, "Material: %5sMetallic", "");
		sprintf(rt->panel->viewparam->str_param_m, "Fuzzy: %10.3g", \
			rt->panel->viewparam->obj->p_mat->t);
	}
	else if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_LAMBERT)
	{
		sprintf(rt->panel->viewparam->str_mat, "Material: %5sLambertian", "");
		sprintf(rt->panel->viewparam->str_param_m, "");
	}
	else if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_DIFF_LIGHT)
	{

		sprintf(rt->panel->viewparam->str_mat, "Material: %5sDiffuse Light", "");
		sprintf(rt->panel->viewparam->str_param_m, "");
	}
	sprintf(rt->panel->viewparam->str_color, "Color: %10srgb(%.3g, %.3g, %.3g)", \
		"", rt->panel->viewparam->obj->p_mat->albedo->x * 255.0, \
		rt->panel->viewparam->obj->p_mat->albedo->y * 255.0, \
		rt->panel->viewparam->obj->p_mat->albedo->z * 255.0);

	/*
	  Update object params
	*/

	//Param list object 
	lst_set_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_obj, rt->panel->sub_title1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289), 2), rt->esdl->eng.render, esdl_render_blendedtext);

	lst_set_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_pos, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 30), 3), rt->esdl->eng.render, esdl_render_blendedtext);

	lst_set_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_param_o, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 60), 4), rt->esdl->eng.render, esdl_render_blendedtext);

	lst_set_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_mat, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 90), 5), rt->esdl->eng.render, esdl_render_blendedtext);

	lst_set_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_color, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 120), 6), rt->esdl->eng.render, esdl_render_blendedtext);

	lst_set_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_param_m, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 150), 7), rt->esdl->eng.render, esdl_render_blendedtext);

}

void		reset_menu(t_rt *rt)
{
	SDL_Rect		rect;

	rt->panel = malloc(sizeof(t_panel));
	rt->panel->lst_surf = NULL;
	rt->panel->lst_string = NULL;
	rt->panel->viewparam = new_viewparam(rt->scene);
	rt->panel->imgparam = new_imgparam(IMG_ADDCUBE);
	rt->r_menu = malloc(sizeof (SDL_Rect));
	SDL_GetWindowSize(rt->esdl->eng.win, &(rt->r_menu->w), &(rt->r_menu->h));
	rt->r_menu->x = rt->r_menu->w - MENU_RX;
	rt->r_menu->y = 0;

	/*
	  Background surfaces
	*/

	//background
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		rt->r_menu, 0xff373737, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	//title1
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 0, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	//3dview
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(50, 50, 200, 200));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0, (void*)rt->panel->viewparam, 0), rt->esdl->eng.render, \
		rt_3dview_surface);

	//subtitle1
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 280, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff222222, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	//title2
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(0, 480, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff888888, NULL, 0), rt->esdl->eng.render, esdl_clear_surface);

	//primitives
	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(27, 520, 0, 0));
	rt->panel->lst_surf = lst_new_image(&(rt->panel->lst_surf), \
		surfparam(&rect, 0, (void*)rt->panel->imgparam, 0), \
		rt->esdl->eng.render, esdl_load_texture);

	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 + 27 * 2, 520, 0, 0));
	set_imgparam(rt->panel->imgparam, IMG_ADDPLANE);
	rt->panel->lst_surf = lst_new_image(&(rt->panel->lst_surf), \
		surfparam(&rect, 0, (void*)rt->panel->imgparam, 0), \
		rt->esdl->eng.render, esdl_load_texture);

	rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(64 * 2 + 27 * 3, 520, 0, 0));
	set_imgparam(rt->panel->imgparam, IMG_ADDSPHERE);
	rt->panel->lst_surf = lst_new_image(&(rt->panel->lst_surf), \
		surfparam(&rect, 0, (void*)rt->panel->imgparam, 0), \
		rt->esdl->eng.render, esdl_load_texture);

	/*
	  Get param from object
	*/

	//Get object type
	if (rt->panel->viewparam->obj->type_obj == OBJ_SPHERE)
	{
		t_sphere		*sphere;

		sphere = (t_sphere*)rt->panel->viewparam->obj->p_obj;
		sprintf(rt->panel->viewparam->str_obj, "Sphere Param:");
		sprintf(rt->panel->viewparam->str_pos, "Position: %5s[%.3g; %.3g; %.3g]", \
			"", sphere->center->x, sphere->center->y, sphere->center->z);
		sprintf(rt->panel->viewparam->str_param_o, "Radius: %10.3g", \
			sphere->radius);
	}
	else if (rt->panel->viewparam->obj->type_obj == OBJ_PLANE_XY)
		sprintf(rt->panel->viewparam->str_obj, "Plane Param:");
	else if (rt->panel->viewparam->obj->type_obj == OBJ_CUBE)
		sprintf(rt->panel->viewparam->str_obj, "Cube Param:");

	//Get material type
	if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_METAL)
	{
		sprintf(rt->panel->viewparam->str_mat, "Material: %5sMetallic", "");
		sprintf(rt->panel->viewparam->str_param_m, "Fuzzy: %10.3g", \
			rt->panel->viewparam->obj->p_mat->t);
	}
	else if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_LAMBERT)
	{
		sprintf(rt->panel->viewparam->str_mat, "Material: %5sLambertian", "");
		sprintf(rt->panel->viewparam->str_param_m, "");
	}
	else if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_DIFF_LIGHT)
	{

		sprintf(rt->panel->viewparam->str_mat, "Material: %5sDiffuse Light", "");
		sprintf(rt->panel->viewparam->str_param_m, "");
	}
	sprintf(rt->panel->viewparam->str_color, "Color: %10srgb(%.3g, %.3g, %.3g)", \
		"", rt->panel->viewparam->obj->p_mat->albedo->x * 255.0, \
		rt->panel->viewparam->obj->p_mat->albedo->y * 255.0, \
		rt->panel->viewparam->obj->p_mat->albedo->z * 255.0);

	/*
	  Text & Title
	*/

	//Fonts
	rt->panel->title1 = esdl_load_font(QUICKFONT, 22, 0x222222ff);
	rt->panel->sub_title1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
	rt->panel->word1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);

	//Object preview
	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Object Setting:", rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 7), 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"2D view", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 220, 257), 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	//Param list object 
	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_obj, rt->panel->sub_title1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_pos, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 30), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_param_o, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 60), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_mat, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 90), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_color, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 120), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_param_m, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 150), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	//Add primitives
	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Primitives:", rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 487), 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Cube", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 27, 530 + 64) , 0), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Plane", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 27 * 2 + 64, \
		530 + 64), 0), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Sphere", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 27 * 3 + 64 * \
		2, 530 + 64), 0), rt->esdl->eng.render, esdl_render_blendedtext);
}
