# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 17:10:25 by qfremeau          #+#    #+#              #
#    Updated: 2017/03/21 13:53:00 by vafanass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC =		clang
CFLAGS =	-Wall -Wextra -g
ADDFLAGS =	

# Precompiled header
PRECOMP =	stdafx.h

# Default rule
DEFRULE =	all

# Binary
NAME =		rt
DST =		

# Directories
SRCDIR =	sources
OBJDIR =	objects
ifeq ($(OS),Windows_NT)
	INCDIR =	includes\
				librairies/libft/includes\
				librairies/libvec/includes\
	CFSDL =		
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		ID_UN := $(shell id -un)
		INCDIR =	includes\
					librairies/libft/includes\
					librairies/libvec/includes\
					/Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.5/include/SDL2\
					/Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/2.0.14/include/SDL2\
					/Users/$(ID_UN)/.brew/Cellar/sdl2_image/2.0.1_2/include/SDL2\
					/usr/local/Cellar/sdl2/2.0.5/include/SDL2\
					/usr/local/Cellar/sdl2_ttf/2.0.14/include/SDL2\
					/usr/local/Cellar/sdl2_image/2.0.1_2/include/SDL2\
					-F -framework Cocoa 
		CFSDL =		
	endif
	ifeq ($(UNAME_S),Linux)
		INCDIR =	includes\
					librairies/libft/includes\
					librairies/libvec/includes
		CFSDL =		`sdl2-config --cflags`
	endif
endif
PREDIR =	includes

# Sources
SRC = \
			display/display.c\
			\
			esdl/color.c\
			esdl/inputs.c\
			esdl/exit.c\
			esdl/fps.c\
			esdl/init.c\
			esdl/texture.c\
			esdl/pixel.c\
			esdl/rect.c\
			esdl/surface.c\
			esdl/ttf.c\
			\
			init/init.c\
			init/loading.c\
			init/quit.c\
			\
			input/events.c\
			input/arrow_lmouse.c\
			input/arrow_rmouse.c\
			\
			interface/button/add_plane.c\
			interface/button/add_cone.c\
			interface/button/add_sphere.c\
			interface/button/add_cylinder.c\
			interface/button/add_triangle.c\
			interface/button/button_triangle.c\
			interface/button/button_cone.c\
			interface/button/button_cylinder.c\
			interface/button/button_material.c\
			interface/button/button_plane.c\
			interface/button/button_sphere.c\
			interface/button/header_button.c\
			interface/button/general_button.c\
			interface/surface_rendering/surface_bkg.c\
			interface/surface_rendering/surface_text.c\
			interface/surface_rendering/surface_button.c\
			interface/surface_rendering/surface_draw_button.c\
			interface/surface_rendering/surface_draw_button_param.c\
			interface/view/view.c\
			interface/view/miniview.c\
			interface/param_object.c\
			interface/param_material.c\
			interface/filter.c\
			interface/menu.c\
			\
			kernel/isopencl.c\
			\
			parser/balise/bc_cam.c\
			parser/balise/bc_skybox.c\
			parser/balise/bc_sphere.c\
			parser/balise/bc_plane.c\
			parser/balise/bc_cylinder.c\
			parser/balise/bc_cone.c\
			parser/balise/bc_ellipsoid.c\
			parser/balise/bc_lambert.c\
			parser/balise/bc_metal.c\
			parser/balise/bc_dielectric.c\
			parser/balise/bc_difflight.c\
			parser/balise/bc_paraboloid.c\
			parser/balise/bc_triangle.c\
			parser/check/xml_flag_object.c\
			parser/check/xml_flag_texture.c\
			parser/check/check_balise.c\
			parser/check/check_opt.c\
			parser/material/lambert.c\
			parser/material/metal.c\
			parser/material/dielectric.c\
			parser/material/difflight.c\
			parser/material/texture.c\
			parser/primitive/sphere.c\
			parser/primitive/plane.c\
			parser/primitive/cylinder.c\
			parser/primitive/cone.c\
			parser/primitive/ellipsoid.c\
			parser/primitive/paraboloid.c\
			parser/primitive/triangle.c\
			parser/scene/default.c\
			parser/scene/camera.c\
			parser/scene/skybox.c\
			parser/init.c\
			parser/random.c\
			parser/parser.c\
			parser/read_xml.c\
			parser/get_material.c\
			parser/get_type.c\
			\
			raytracer/thread/render_thread.c\
			raytracer/thread/util_thread.c\
			raytracer/ray.c\
			raytracer/raytracer.c\
			raytracer/render.c\
			raytracer/scatter.c\
			raytracer/util_random.c\
			raytracer/util_render.c\
			\
			scene/camera/camera.c\
			scene/material/light.c\
			scene/material/lambert.c\
			scene/material/metal.c\
			scene/material/dielectric.c\
			scene/primitives/sphere.c\
			scene/primitives/plane.c\
			scene/primitives/cylinder.c\
			scene/primitives/cone.c\
			scene/primitives/paraboloid.c\
			scene/primitives/ellipsoid.c\
			scene/primitives/triangle.c\
			scene/primitives/multiobject.c\
			scene/texture/texture_uv.c\
			scene/texture/procedural.c\
			scene/material.c\
			scene/object.c\
			scene/skybox.c\
			scene/texture.c\
			\
			utils/list_button.c\
			utils/list_surface.c\
			utils/list_thread.c\
			utils/util_file.c\
			utils/util_filter.c\
			utils/util_matrice_filter.c\
			utils/util_surface.c\
			utils/util_texture.c\
			utils/util_view.c\
			utils/utils.c\
			\
			main.c

OBJ =		$(SRC:.c=.o)

# Prefixes
ifeq ($(OS),Windows_NT)
	OPNCL =		-L/lib/ -lOpenCL
	LSDL2 =		-L/lib/ -lSDL2 -lSDL2_ttf -lSDL2_image
	LMATH =		
	LPTHR =		
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		OPNCL =		-framework OpenCL
		LSDL2 =		-L/Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.5/lib -lSDL2\
							-L/Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/2.0.14/lib -lSDL2_ttf\
							-L/Users/$(ID_UN)/.brew/Cellar/sdl2_image/2.0.1_2/lib -lSDL2_image\
							-L/usr/local/Cellar/sdl2/2.0.5/lib -lSDL2\
							-L/usr/local/Cellar/sdl2_ttf/2.0.14/lib -lSDL2_ttf\
							-L/usr/local/Cellar/sdl2_image/2.0.1_2/lib -lSDL2_image
		LMATH =		-lm
		LPTHR =		-lpthread
	endif
	ifeq ($(UNAME_S),Linux)
		OPNCL =		-L/usr/lib/x86_64-linux-gnu -lOpenCL
		LSDL2 =		`sdl2-config --libs` -lSDL2_ttf -lSDL2_image
		LMATH =		-lm
		LPTHR =		-pthread
	endif
endif
LIBFT =		-Llibrairies/libft/ -lft
LIBVEC =	-Llibrairies/libvec/ -lvec

# Paths foreach
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP =		$(foreach dir, $(INCDIR), -I$(dir))
PREP =		$(addprefix $(PREDIR)/, $(PRECOMP))
OBJS_DIRS = $(sort $(dir $(OBJP)))

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************** #
# RULES
.SILENT:

# Main rules
default:
	@echo -e "$(LOG_BOLD)Default execution: rule $(DEFRULE)$(LOG_NOCOLOR)"
	@make $(DEFRULE)
	@echo -e "$(LOG_BOLD)Execution finished     $(LOG_NOCOLOR)ヽ(ヅ)ノ"

all: libcomp $(OBJDIR) $(NAME)

re: fclean all

# Compilation rules
libcomp:
	@make all -C librairies/libft/
	@make all -C librairies/libvec/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ $(INCP) $(CFSDL)

$(OBJDIR):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJS_DIRS)

$(NAME): $(OBJP)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)......................... $(LOG_YELLOW)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) $(LPTHR) -o $@ $^ $(OPNCL) $(LSDL2) $(LIBFT) $(LIBVEC) $(LMATH) $(INCP)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR) compiled.................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

# MrProper's legacy
.PHONY: fclean clean glu

clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean libft$(LOG_NOCOLOR)"
	@make clean -C librairies/libft/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean libvec$(LOG_NOCOLOR)"
	@make clean -C librairies/libvec/

fclean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean libft$(LOG_NOCOLOR)"
	@make fclean -C librairies/libft/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean libvec$(LOG_NOCOLOR)"
	@make fclean -C librairies/libvec/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -f $(NAME)

glu: re clean

# SDL2 brew

sdl2:
	brew install sdl2
	brew link sdl2
	brew install sdl2_ttf
	brew link sdl2_ttf
	brew install sdl2_image
	brew link sdl2_image
