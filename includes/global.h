/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:26:38 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/27 11:05:48 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GLOBAL_H
# define _GLOBAL_H

# define UCHAR			unsigned char
# define UINT			unsigned int
# define BOOL			int
# define TRUE			1
# define FALSE			0

# define STACK_SIZE		(1 * PAGE_SIZE)

# define ALIASING		1000
# define NO_ALIASING	1
# define MAX_DEPTH		100
# define RT_SUBXY		60
# define MSAMP			2

# define CGRID			0xff0055ff
# define CBAR			0xff323333
# define CPROGRESS		0xff55ff00

# define API_NAME		"RT ~steam"
# define MAX_FPS		60
# define MENU_RX		300
# define TILE_RY		40
# define MINWIN_RX		1400
# define MINWIN_RY		900
# define MAXWIN_RX		1920
# define MAXWIN_RY		1200
# define WIN_RX			rt->rx
# define WIN_RY			rt->ry
# define WIN_M			SDL_WINDOWPOS_CENTERED
# define LOAD_NAME		"image/Loader.png"
# define LOAD_RX		900
# define LOAD_RY		563
# define LOADBAR_RX		450
# define LOADBAR_RY		20
# define QUICKFONT		"font/Quicksand_Book.otf"
# define IMG_ADDSPHERE	"image/AddSphere.bmp"
# define IMG_ADDPLANE	"image/AddPlane.bmp"
# define IMG_ADDCUBE	"image/AddCube.bmp"
# define IMG_TOOLRENDER	"image/Render.bmp"
# define IMG_TOOLPAINT	"image/Paint.bmp"
# define IMG_TOOLSAVE	"image/Save.bmp"

# define SEED "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

# define HELP			0x1
# define ERROR			0x2

# define EV_EXIT		0x1
# define EV_RESIZE		0x2

# define OBJ_PLANE		0x1
# define OBJ_CONE		0x2
# define OBJ_PLANE_XZ	0x4
# define OBJ_SPHERE		0x8
# define OBJ_CUBE		0x10
# define OBJ_PYRAMID	0x20
# define OBJ_CYLINDER	0x40
# define OBJ_SKYBOX		0x80
# define OBJ_PARABOLOID 0x11
# define OBJ_ELLIPSOID	0x12
# define OBJ_TRIANGLE	0x92

# define SKYBX_NONE		0x1
# define SKYBX_GRADIENT	0x2

# define NULL_PARAM		0.0
# define NULL_RECT		(SDL_Rect){0,0,0,0}

# define MAT_NONE		0x0
# define MAT_LAMBERT	0x1
# define MAT_METAL		0x2
# define MAT_DIELECT	0x4
# define MAT_DIFF_LIGHT	0x8
# define TEXT_IMAGE		0x10
# define TEXT_NONE		0x20
# define TEXT_TEST		0x40
# define TEXT_CHCKBOARD	0x80
# define TEXT_LINEY 	0x11
# define TEXT_LINEX 	0x12
# define TEXT_RAINBOW	0x13

# define BTN_MINUS		0x1
# define BTN_CLOSE		0x2
# define BTN_RENDER		0x4
# define BTN_FILTER		0x8
# define BTN_SNAP		0x10
# define BTN_MORE		0x20
# define BTN_PARAM1		0x40
# define BTN_PARAM2		0x80
# define BTN_PARAM3		0x11
# define BTN_PARAM4		0x12
# define BTN_PARAM5		0x13
# define BTN_PARAM6		0x15

# define FILE_DEF		"<?DOCTYPE scn-rt?>"

# define BO_CAM			"<camera>"
# define BO_FOV			"<fov>"
# define BO_TARGET		"<target>"
# define BO_APERT		"<aperture>"
# define BO_OBJ			"<obj>"
# define BO_SPHERE		"<sphere>"
# define BO_PLANE		"<plane>"
# define BO_CYLINDER	"<cylinder>"
# define BO_CONE		"<cone>"
# define BO_ELLIPSOID	"<ellipsoid>"
# define BO_PARABLOID	"<paraboloid>"
# define BO_RADIUS		"<radius>"
# define BO_POS			"<pos>"
# define BO_ROTATE		"<rotate>"
# define BO_LAMBERT		"<lambert>"
# define BO_HEIGHT		"<height>"
# define BO_METAL		"<metal>"
# define BO_DIELECT		"<dielectric>"
# define BO_DIFFLIGHT	"<difflight>"
# define BO_COLOR		"<color>"
# define BO_PARAM		"<param>"
# define BO_TEXTURE		"<texture>"
# define BO_SKYBOX		"<skybox>"
# define BO_GRADIENT	"<gradient>"
# define BO_PATH		"<path>"
# define BO_TRIANGLE	"<triangle>"
# define BO_NONE		"<none>"

# define BC_CAM			"</camera>"
# define BC_FOV			"</fov>"
# define BC_TARGET		"</target>"
# define BC_APERT		"</aperture>"
# define BC_OBJ			"</obj>"
# define BC_SPHERE		"</sphere>"
# define BC_PLANE		"</plane>"
# define BC_CYLINDER	"</cylinder>"
# define BC_PARABLOID	"</paraboloid>"
# define BC_CONE		"</cone>"
# define BC_RADIUS		"</radius>"
# define BC_POS			"</pos>"
# define BC_ROTATE		"</rotate>"
# define BC_HEIGHT		"</height>"
# define BC_LAMBERT		"</lambert>"
# define BC_METAL		"</metal>"
# define BC_DIELECT		"</dielectric>"
# define BC_DIFFLIGHT	"</difflight>"
# define BC_COLOR		"</color>"
# define BC_PARAM		"</param>"
# define BC_TEXTURE     "</texture>"
# define BC_SKYBOX		"</skybox>"
# define BC_GRADIENT	"</gradient>"
# define BC_ELLIPSOID   "</ellipsoid>"
# define BC_PATH		"</path>"
# define BC_TRIANGLE	"</triangle>"
# define BC_NONE		"</none>"

# define BYTE_CAM		((UINT)1 << 0)
# define BYTE_OBJ		((UINT)1 << 1)
# define BYTE_SKYBOX	((UINT)1 << 2)
# define BYTE_FOV		((UINT)1 << 3)
# define BYTE_TARGET	((UINT)1 << 4)
# define BYTE_APERT		((UINT)1 << 5)
# define BYTE_SPHERE	((UINT)1 << 6)
# define BYTE_PLANE		((UINT)1 << 7)
# define BYTE_CYLINDER	((UINT)1 << 8)
# define BYTE_CONE		((UINT)1 << 9)
# define BYTE_ELLIPSOID ((UINT)1 << 10)
# define BYTE_PARABLOID ((UINT)1 << 11)
# define BYTE_TRIANGLE	((UINT)1 << 12)
# define BYTE_RADIUS	((UINT)1 << 13)
# define BYTE_POS		((UINT)1 << 14)
# define BYTE_ROTATE	((UINT)1 << 15)
# define BYTE_HEIGHT    ((UINT)1 << 16)
# define BYTE_LAMBERT	((UINT)1 << 17)
# define BYTE_METAL		((UINT)1 << 18)
# define BYTE_DIELECT	((UINT)1 << 19)
# define BYTE_DIFFLIGHT	((UINT)1 << 20)
# define BYTE_COLOR		((UINT)1 << 21)
# define BYTE_PARAM		((UINT)1 << 22)
# define BYTE_GRADIENT	((UINT)1 << 23)
# define BYTE_TEXTURE   ((UINT)1 << 24)
# define BYTE_PATH		((UINT)1 << 25)
# define BYTE_NONE		((UINT)1 << 26)

enum			e_bytetab
{
	E_TAB_VOID = 0,
	E_TAB_CAM,
	E_TAB_OBJ,
	E_TAB_SKYBOX,
	E_TAB_FOV,
	E_TAB_TARGET,
	E_TAB_APERT,
	E_TAB_SPHERE,
	E_TAB_PLANE,
	E_TAB_CYLINDER,
	E_TAB_CONE,
	E_TAB_ELLIPSOID,
	E_TAB_PARABLOID,
	E_TAB_TRIANGLE,
	E_TAB_RADIUS,
	E_TAB_POS,
	E_TAB_ROTATE,
	E_TAB_HEIGHT,
	E_TAB_LAMBERT,
	E_TAB_METAL,
	E_TAB_DIELECT,
	E_TAB_DIFFLIGHT,
	E_TAB_COLOR,
	E_TAB_PARAM,
	E_TAB_GRADIENT,
	E_TAB_TEXTURE,
	E_TAB_PATH,
	E_TAB_NONE,
	E_TAB_LAST
};

#endif
