# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 15:07:52 by lucas-ma          #+#    #+#              #
#    Updated: 2023/01/05 16:19:54 by lucas-ma         ###   ########.fr        #
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
_MLX    =        ./minilibx_linux/
_BIN    =        ./

############### COMPILER ################

CC      =        cc
CFLAGS      =        -Wall -Werror -Wextra -g #-fsanitize=address
#valgrind --leak-check=full --show-leak-kinds=all ./minishell
SRCS    =        $(_SRC)cub3d_main.c \
                 $(_SRC)errors.c \
                 $(_SRC)free_utils.c \
                 $(_SRC)utils.c \
                 $(_SRC)check_args.c \
                 $(_SRC)parse_file.c \
                 $(_SRC)parse_file_utils.c \
                 $(_SRC)check_map.c \
                 $(_SRC)check_map_utils.c \
				 $(_SRC)raycasting/ray_main.c \
				 $(_SRC)raycasting/ray_loop.c \

OBJS    =        $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))
DEPS    =        ./libs/libft.a ./minilibx_linux/libmlx_Linux.a
LIBS    =        -lft

################ RULES ##################

all: deps $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(MKD) -p $(@D)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJS) -o $(NAME) -L $(_LIB) $(LIBS) -L $(_MLX) -lmlx_Linux

################ DEPS ###################

./libs/libft.a:
	$(MKE) -C libft/

./minilibx_linux/libmlx_Linux.a:
	$(MKE) -C minilibx_linux/

############## STRUCTURE ################

$(_BIN):
	$(MKD) $(_BIN)libs/libft.a

clean:
	$(RMV) -r $(_OBJ)

fclean: clean
	$(RMV) -r $(NAME)
	$(RMV) -r $(_LIB)libft.a
	$(RMV) -r $(_MLX)libmlx.a
	$(RMV) -r $(_MLX)libmlx_Linux.a

re: fclean all

rebonus: fclean bonus

.PHONY: all deps clean fclean re
