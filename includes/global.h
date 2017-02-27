/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:26:38 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/27 11:36:03 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GLOBAL_H
# define _GLOBAL_H

# define UCHAR			unsigned char
# define UINT			unsigned int
# define BOOL			int
# define TRUE			1
# define FALSE			0

# ifdef __linux__
# define PAGE_SIZE		4096
# endif
# define STACK_SIZE		(1 * PAGE_SIZE)

# define ALIASING		100
# define NO_ALIASING	1
# define MAX_DEPTH		25
# define RT_SUBXY		60
# define MULTISAMP		2

# define API_NAME		"RT"
# define MAX_FPS		25
# define WIN_RX			1400
# define WIN_RY			900
# define MENU_RX		300
# define LOAD_NAME		"image/Loader.bmp"
# define LOAD_RX		900
# define LOAD_RY		563
# define QUICKFONT		"font/Quicksand_Book.otf"
# define IMG_ADDSPHERE	"image/AddSphere.bmp"
# define IMG_ADDPLANE	"image/AddPlane.bmp"
# define IMG_ADDCUBE	"image/AddCube.bmp"
# define IMG_TOOLRENDER	"image/Render.bmp"
# define IMG_TOOLPAINT	"image/Paint.bmp"
# define IMG_TOOLSAVE	"image/Save.bmp"

# define HELP			-2
# define ERROR			-1

# define EV_EXIT		-1
# define EV_RESIZE		-2

# define OBJ_PLANE		0x1
# define OBJ_CONE		0x2
# define OBJ_PLANE_XZ	0x4
# define OBJ_SPHERE		0x5
# define OBJ_CUBE		0x10
# define OBJ_PYRAMID	0x20
# define OBJ_CYLINDER	0x40
# define OBJ_SKYBOX		0x50

# define SKYBX_NONE		0x0
# define SKYBX_GRADIENT	0x1

# define NULL_PARAM		0.0
# define NULL_RECT		(SDL_Rect){0,0,0,0}

# define MAT_NONE		0x0
# define MAT_LAMBERT	0x1
# define MAT_METAL		0x2
# define MAT_DIELECT	0x4
# define MAT_DIFF_LIGHT	0x8

# define BO_S	"<scene>"
# define BC_S	"</scene>"
# define BO_C	"<camera>"
# define BC_C	"</camera>"
# define BO_L	"<light>"
# define BC_L	"</light>"
# define BO_O	"<object>"
# define BC_O	"</object>"
# define BO_N	"<name>"
# define BC_N	"</name>"
# define BO_A	"<ambient>"
# define BC_A	"</ambient>"
# define BO_AA	"<anti-aliasing>"
# define BC_AA	"</anti-aliasing>"
# define BO_MR	"<max-reflexion>"
# define BC_MR	"</max-reflexion>"
# define BO_P	"<position>"
# define BC_P	"</position>"
# define BO_R	"<rotation>"
# define BC_R	"</rotation>"
# define BO_FL	"<focal>"
# define BC_FL	"</focal>"
# define BO_V	"<visibility>"
# define BC_V	"</visibility>"
# define BO_I	"<intensity>"
# define BC_I	"</intensity>"
# define BO_T	"<type>"
# define BC_T	"</type>"
# define BO_M	"<material>"
# define BC_M	"</material>"
# define BO_OP	"<opacity>"
# define BC_OP	"</opacity>"
# define BO_CR	"<color-rgb>"
# define BC_CR	"</color-rgb>"
# define BO_CH	"<color-hex>"
# define BC_CH	"</color-hex>"

#endif
