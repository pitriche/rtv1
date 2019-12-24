# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:21:44 by pitriche          #+#    #+#              #
#    Updated: 2019/12/24 15:58:36 by pierre42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY    = \033[030m
RED     = \033[031m
GREEN   = \033[032m
YELLOW  = \033[033m
BLUE    = \033[034m
MAGENTA = \033[035m
CYAN	= \033[036m
RESET   = \033[0m

# **************************************************************************** #

CC = cc

MLX = -lmlx -framework OpenGL -framework AppKit
FL_OPTI = 
#-O3 -flto
FLAGS = -Wall -Wextra $(FL_OPTI)
LFLAGS = $(FLAGS) $(MLX)
CFLAGS = -c $(FLAGS)

LIB = libft/libft.a -LMLX

HEADERS = include/rtv1.h
CINCLUDE = -I include -I libft/include -I MLX/X11

NAME = rtv1

SRC_FILES = 	\
main_rt.c		\
init.c			\
mica_parser.c	\
mica_parser2.c	\
mica_parser3.c	\
vector_maths.c	\
gen_camera.c	\
main_loop.c		\
render.c

SRC_DIR = src/
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ_DIR = obj/
OBJ := $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)
	@echo "$(CYAN)$(NAME) ready sir !$(RESET)"

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	@echo "$(GREEN)objects done sir !$(RESET)"
	@$(CC) $(LFLAGS) -o $(NAME) $(LIB) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled sir !$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
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
