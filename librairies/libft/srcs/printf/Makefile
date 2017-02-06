# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/02 11:44:08 by qfremeau          #+#    #+#              #
#    Updated: 2016/09/15 17:26:50 by qfremeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC =		clang
CFLAGS =	-Wall -Wextra -Werror
ADDFLAGS =	

# Default rule
DEFRULE =	all

# Binary
NAME =		libftprintf.a
DST =		

# Directories
SRCDIR =	srcs
OBJDIR =	objs
INCDIR =	includes
LIBDIR =

# Sources
SRC =\
			ft_addto.c\
			ft_printf.c\
			ft_options.c\
			ft_setoptions.c\
			ft_apply.c\
			ft_getparams.c\
			option_c.c\
			option_di.c\
			option_p.c\
			option_u.c\
			option_s.c\
			option_o.c\
			option_b.c\
			option_uni.c\
			option_hexa.c\
			option_mod.c\
			ft_strchr.c\
			ft_itoa.c\
			ft_maths.c\
			ft_nbrlen.c\
			ft_bzero.c

LIB =		
OBJ =		$(SRC:.c=.o)

# Prefixes
LLIBP =		$(addprefix -l, $(LIB))
LIBP =		$(addprefix lib, $(LIB))
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

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

.PHONY: glu 

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
	@echo -e "$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJP)
	@echo -e "$(LOG_CLEAR)$(LOG_VIOLET)(NAME)$(LOG_NOCOLOR)....................... $(LOG_YELLOW)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@ar rc $(DST)$(NAME) $(OBJP)
	@ranlib $(DST)$(NAME)
	@echo -e "$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR) compiled....... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

# MrProper's legacy
clean:
	@echo -e "$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo -e "$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -f $(NAME)
