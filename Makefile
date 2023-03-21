# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 15:33:52 by otaraki           #+#    #+#              #
#    Updated: 2023/03/21 19:42:36 by otaraki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT =	libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror 

INC = so_long.h \

SRC = so_long.c game.c\
	check_map_wall.c check_inside_map.c\
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c\
	ft_error.c\



OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

%.o : %.c so_long.h
	${CC} ${CFLAGS} -Imlx -c -o $@ $<

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re