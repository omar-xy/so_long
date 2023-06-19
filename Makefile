# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 15:33:52 by otaraki           #+#    #+#              #
#    Updated: 2023/06/19 20:33:27 by otaraki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INC = inc/so_long.h 

LIBFT =	libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 


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