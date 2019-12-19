# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:21:44 by pitriche          #+#    #+#              #
#    Updated: 2019/12/19 11:32:48 by pitriche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY    = \033[030m
RED     = \033[031m
GREEN   = \033[132m
YELLOW  = \033[033m
BLUE    = \033[034m
MAGENTA = \033[035m
CYAN	= \033[036m
RESET   = \033[0m

# **************************************************************************** #

CC = cc

MLX = -lmlx -framework OpenGL -framework AppKit
FL_OPTI = -O3 -flto
FLAGS = -Wall -Wextra $(FL_OPTI)
LFLAGS = $(FLAGS) $(MLX)
CFLAGS = -c $(FLAGS)

LIB = libft/libft.a
CINCLUDE = -I include -I libft/include -I MLX/X11

NAME = rtv1

SRC = \
main_rt.c	\
init.c		\

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(LIB) $(OBJ_DIR) $(NAME)
	@echo "$(CYAN)$(NAME) ready sir !$(RESET)"

$(NAME): $(OBJ)
	@echo "$(GREEN)objects done sir !$(RESET)"
	@$(CC) $(LFLAGS) -o $(NAME) $(LIB) $^
	@echo "$(GREEN)$(NAME) compiled sir !$(RESET)"

$(addprefix $(OBJ_DIR), %.o) : %.c
	@$(CC) $(CINCLUDE) $(CFLAGS) -o $@ $<
	@echo -n '.'

$(LIB) :
	@make -C libft
	@make -C MLX

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@#echo "$(GREEN)Object directory created sir !$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Objects deleted sir !$(RESET)"
	@rm -rf $(OBJ_DIR)
	@#echo "$(RED)Object directory deleted sir !$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted sir !$(RESET)"

lclean: fclean
	@make -C libft fclean
	@echo "$(RED)libft deleted sir !$(RESET)"
	@make -C MLX fclean
	@echo "$(RED)MLX deleted sir !$(RESET)"

re: fclean all

lre: lclean all
