# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/02 11:44:08 by qfremeau          #+#    #+#              #
#    Updated: 2017/02/21 18:53:06 by qfremeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC =		clang
CFLAGS =	-Wall -Wextra -Werror
ADDFLAGS =

# Default rule
DEFRULE =	all

# Binary
NAME =		libft.a
DST =		

# Directories
SRCDIR =	srcs
OBJDIR =	objs
INCDIR =	includes
LIBDIR =	

# Sources
SRC =\
	basics/memory/ft_bzero.c\
	basics/memory/ft_memalloc.c\
	basics/memory/ft_memccpy.c\
	basics/memory/ft_memchr.c\
	basics/memory/ft_memcmp.c\
	basics/memory/ft_memcpy.c\
	basics/memory/ft_memdel.c\
	basics/memory/ft_memmove.c\
	basics/memory/ft_memset.c\
	basics/memory/ft_realloc.c\
	\
	basics/print/ft_putchar.c\
	basics/print/ft_putchar_fd.c\
	basics/print/ft_putendl.c\
	basics/print/ft_putendl_fd.c\
	basics/print/ft_putnbr.c\
	basics/print/ft_putnbr_fd.c\
	basics/print/ft_putstr.c\
	basics/print/ft_putstr_fd.c\
	basics/print/ft_putnl.c\
	\
	basics/string/ft_strcat.c\
	basics/string/ft_strchr.c\
	basics/string/ft_strclr.c\
	basics/string/ft_strcmp.c\
	basics/string/ft_strcpy.c\
	basics/string/ft_strdel.c\
	basics/string/ft_strdup.c\
	basics/string/ft_strequ.c\
	basics/string/ft_striter.c\
	basics/string/ft_striteri.c\
	basics/string/ft_strjoin.c\
	basics/string/ft_strlcat.c\
	basics/string/ft_strlen.c\
	basics/string/ft_strmap.c\
	basics/string/ft_strmapi.c\
	basics/string/ft_strncat.c\
	basics/string/ft_strncmp.c\
	basics/string/ft_strncpy.c\
	basics/string/ft_strnequ.c\
	basics/string/ft_strnew.c\
	basics/string/ft_strnstr.c\
	basics/string/ft_strrchr.c\
	basics/string/ft_strsplit.c\
	basics/string/ft_strstr.c\
	basics/string/ft_strsub.c\
	basics/string/ft_strtrim.c\
	\
	basics/types/ft_isalnum.c\
	basics/types/ft_isalpha.c\
	basics/types/ft_isascii.c\
	basics/types/ft_isdigit.c\
	basics/types/ft_isprint.c\
	basics/types/ft_isspace.c\
	basics/types/ft_tolower.c\
	basics/types/ft_toupper.c\
	basics/types/ft_uporlow.c\
	\
	containers/list/ft_lstadd.c\
	containers/list/ft_lstdel.c\
	containers/list/ft_lstdelone.c\
	containers/list/ft_lstiter.c\
	containers/list/ft_lstmap.c\
	containers/list/ft_lstnew.c\
	\
	utils/cast/ft_atoi.c\
	utils/cast/ft_atof.c\
	utils/cast/ft_itoa.c\
	\
	utils/math/ft_sqrt.c\
	utils/math/ft_swap.c\
	\
	wide/ft_nbrlen.c\
	wide/ft_strlen_w.c\
	wide/ft_putnbrlong.c\
	wide/ft_itoa_w.c\
	\
	printf/ft_addto.c\
	printf/ft_printf.c\
	printf/ft_options.c\
	printf/ft_setoptions.c\
	printf/ft_apply.c\
	printf/ft_getparams.c\
	printf/option_c.c\
	printf/option_di.c\
	printf/option_p.c\
	printf/option_u.c\
	printf/option_s.c\
	printf/option_o.c\
	printf/option_b.c\
	printf/option_uni.c\
	printf/option_hexa.c\
	printf/option_mod.c\
	printf/ft_strnchr.c\
	printf/ft_sitoa.c\
	printf/ft_maths.c\
	printf/ft_nbrlen.c\
	\
	gnl/get_next_line.c

LIB =		
OBJ =		$(SRC:.c=.o)

# Prefixes
LLIBP =		$(addprefix -l, $(LIB))
LIBP =		$(addprefix lib, $(LIB))
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
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

.PHONY: glu dev

# Main rules
default:
	@echo -e "$(LOG_BOLD)Default execution: rule $(DEFRULE)$(LOG_NOCOLOR)"
	@make $(DEFRULE)
	@echo -e "$(LOG_BOLD)Execution finished     $(LOG_NOCOLOR)ヽ(ヅ)ノ"
	

glu: re
	@make clean

all: $(NAME)

re: fclean all

# Compilation rules
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)...................... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCDIR)

$(OBJDIR):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJS_DIRS)

$(NAME): $(OBJDIR) $(OBJP)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)..................... $(LOG_YELLOW)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@ar rc $(DST)$(NAME) $(OBJP)
	@ranlib $(DST)$(NAME)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR) compiled............. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

# MrProper's legacy
clean:
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -f $(NAME)
