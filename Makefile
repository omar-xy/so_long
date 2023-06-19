# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 15:33:52 by otaraki           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/06/19 20:14:50 by otaraki          ###   ########.fr        #
=======
#    Updated: 2023/06/12 18:20:01 by otaraki          ###   ########.fr        #
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b
#                                                                              #
# **************************************************************************** #

NAME = so_long

INC = inc/so_long.h 

LIBFT =	libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 


<<<<<<< HEAD
SRC = parse/so_long.c \
	  parse/check_map_wall.c \
	  parse/check_inside_map.c \
	  parse/ch_path.c \
	  drawing/ft_error.c \
	  drawing/init_images.c \
	  drawing/init_win.c \
	  drawing/game.c \
	  drawing/draw.c \
	  drawing/hook.c \
	  g_n_l/get_next_line.c \
	  g_n_l/get_next_line_utils.c
=======
SRC = so_long.c \
	game.c\
	check_map_wall.c check_inside_map.c ch_path.c\
	g_n_l/get_next_line.c \
	g_n_l/get_next_line_utils.c\
	ft_error.c init_images.c init_win.c draw.c hook.c\
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b

OBJ = $(SRC:.c=.o)

m := MakefileAutoPush

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

%.o : %.c $(INC)
	${CC} ${CFLAGS} -Imlx -c -o $@ $<

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY: all clean fclean re