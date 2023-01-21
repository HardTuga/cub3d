# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 15:07:52 by lucas-ma          #+#    #+#              #
#    Updated: 2023/01/21 12:50:52 by lucas-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ PROGRAM ################

NAME	    =    cub3d

################ TERMINAL ###############

RMV        =        rm -f
MKD        =        mkdir
PRT        =        printf
MKE        =        make
CPY        =        cp

################# COLORS ################

--GRN    =        \033[32m
--RED    =        \033[31m
--WHT    =        \033[39m

################# DIRS ##################

_SRC    =        src/
_OBJ 	=		 obj/
_LIB    =        libs/
_MLX    =        ./mlx/
_BIN    =        ./

############### COMPILER ################

CC      =        cc
CFLAGS      =        -Wall -Werror -Wextra #-g -fsanitize=address
#valgrind --leak-check=full --show-leak-kinds=all ./minishell
SRCS    =        $(_SRC)cub3d_main.c \
                 $(_SRC)errors.c \
                 $(_SRC)time.c \
                 $(_SRC)free_utils.c \
                 $(_SRC)utils.c \
                 $(_SRC)parsing/check_args.c \
                 $(_SRC)parsing/parse_file.c \
                 $(_SRC)parsing/parse_file_utils.c \
				 $(_SRC)parsing/parse_file_rgb.c \
                 $(_SRC)parsing/check_map.c \
                 $(_SRC)parsing/check_map_utils.c \
				 $(_SRC)raycasting/ray_main.c \
				 $(_SRC)raycasting/ray_loop.c \
				 $(_SRC)raycasting/ray_moves.c \
				 $(_SRC)raycasting/ray_moves_utils.c \
				 $(_SRC)raycasting/colision.c \
				 $(_SRC)raycasting/images.c \
				 $(_SRC)raycasting/draw.c \

OBJS    =        $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))
DEPS    =        ./libs/libft.a ./mlx/libmlx.a
LIBS    =        -lft

################ RULES ##################

all: deps $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(MKD) -p $(@D)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -Lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) -L $(_LIB) $(LIBS) -L $(_MLX) -lmlx

################ DEPS ###################

./libs/libft.a:
	$(MKE) -C libft/

./mlx/libmlx.a:
	$(MKE) -C $(_MLX)

############## STRUCTURE ################

$(_BIN):
	$(MKD) $(_BIN)libs/libft.a

clean:
	$(RMV) -r $(_OBJ)

fclean: clean
	$(RMV) -r $(NAME)
	$(RMV) -r $(_LIB)libft.a
	cd $(_MLX); $(MKE) clean;
	
re: fclean all

rebonus: fclean bonus

.PHONY: all deps clean fclean re
