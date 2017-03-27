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
CFLAGS =	-Wall -Wextra -Werror -g
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
SRC =		esdl/color.c\
			esdl/events.c\
			esdl/exit.c\
			esdl/fps.c\
			esdl/init.c\
			esdl/image.c\
			esdl/pixel.c\
			esdl/rect.c\
			esdl/surface.c\
			esdl/ttf.c\
			kernel/isopencl.c\
			events/events.c\
			events/hook.c\
			events/init.c\
			events/loading.c\
			events/quit.c\
			events/events.c\
			events/arrow_lmouse.c\
			events/arrow_rmouse.c\
			interface/miniview.c\
			interface/add_plane.c\
			interface/add_cone.c\
			interface/add_sphere.c\
			interface/add_cylinder.c\
			interface/add_triangle.c\
			interface/button.c\
			interface/button_triangle.c\
			interface/button_cone.c\
			interface/button_cylinder.c\
			interface/button_material.c\
			interface/button_plane.c\
			interface/button_sphere.c\
			interface/button_top.c\
			interface/menu.c\
			interface/surface_bkg.c\
			interface/surface_text.c\
			interface/surface_text2.c\
			interface/surface_button.c\
			interface/surface_draw_button.c\
			interface/surface_draw_button_param.c\
			interface/surface_draw_button_param2.c\
			interface/param_object.c\
			interface/param_object_bis.c\
			interface/param_material.c\
			interface/view.c\
			interface/filter.c\
			parser/init.c\
			parser/default.c\
			parser/random.c\
			parser/scene.c\
			parser/read_xml.c\
			parser/check_xml_flag.c\
			parser/check_xml_flag2.c\
			parser/check_xml.c\
			parser/check_opt.c\
			parser/get.c\
			parser/get2.c\
			parser/camera.c\
			parser/skybox.c\
			parser/sphere.c\
			parser/plane.c\
			parser/cylinder.c\
			parser/cone.c\
			parser/ellipsoid.c\
			parser/lambert.c\
			parser/metal.c\
			parser/dielectric.c\
			parser/difflight.c\
			parser/bc_cam.c\
			parser/bc_skybox.c\
			parser/bc_sphere.c\
			parser/bc_plane.c\
			parser/bc_cylinder.c\
			parser/bc_cone.c\
			parser/bc_ellipsoid.c\
			parser/bc_lambert.c\
			parser/bc_metal.c\
			parser/bc_dielectric.c\
			parser/bc_difflight.c\
			parser/bc_paraboloid.c\
			parser/paraboloid.c\
			parser/triangle.c\
			parser/bc_triangle.c\
			parser/texture.c\
			raytracer/random.c\
			raytracer/ray.c\
			raytracer/render.c\
			raytracer/scatter.c\
			raytracer/thread.c\
			raytracer/thread_tools.c\
			raytracer/render_thread_tools.c\
			raytracer/render_tools.c\
			scene/camera.c\
			scene/light.c\
			scene/material.c\
			scene/lambert.c\
			scene/metal.c\
			scene/dielectric.c\
			scene/object.c\
			scene/skybox.c\
			scene/sphere.c\
			scene/plane.c\
			scene/cylinder.c\
			scene/cone.c\
			scene/texture.c\
			scene/texture_bmp.c\
			scene/texture_calculator.c\
			scene/paraboloid.c\
			scene/ellipsoid.c\
			scene/triangle.c\
			utils/list.c\
			utils/list2.c\
			utils/list3.c\
			utils/utils.c\
			utils/utils2.c\
			utils/utils3.c\
			utils/utils4.c\
			utils/utils5.c\
			utils/util_texture.c\
			utils/util_filter.c\
			utils/util_matrice_filter.c\
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
					-L/Users/$(ID_UN)/.brew/Cellar/sdl2_image/2.0.1_2/lib -lSDL2_image
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
