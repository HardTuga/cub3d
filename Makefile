# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 15:07:52 by lucas-ma          #+#    #+#              #
#    Updated: 2022/12/27 11:24:11 by pcampos-         ###   ########.fr        #
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
_BIN    =        ./

############### COMPILER ################

CC      =        cc
CFLAGS      =        -Wall -Werror -Wextra -g # -fsanitize=address
#valgrind --leak-check=full --show-leak-kinds=all ./minishell
SRCS    =        $(_SRC)cub3d_main.c \

OBJS    =        $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))
DEPS    =        ./libs/libft.a
LIBS    =        -lft

################ RULES ##################

all: deps $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(MKD) -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) -L $(_LIB) $(LIBS)

################ DEPS ###################

./libs/libft.a:
	$(MKE) -C libft/

############## STRUCTURE ################

$(_BIN):
	$(MKD) $(_BIN)libs/libft.a

clean:
	$(RMV) -r $(_OBJ)

fclean: clean
	$(RMV) -r $(NAME)
	$(RMV) -r $(_LIB)libft.a

re: fclean all

rebonus: fclean bonus

.PHONY: all deps clean fclean re
