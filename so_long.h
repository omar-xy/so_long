/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:32:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 17:02:17 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_long
{
	t_coord	cor_ply;
	t_coord	cor_exit;
	char	**map;
	int		collec;
	int		ply;
	int		exit;
	int		height;
	int		width;
}				t_long;

typedef struct s_images
{
	void	*mlx;
	void	*win;
	t_long	*data;
	void	*wal;
	void	*exi;
	void	*floor;
	void	*col;
	void	*player;
	int		h;
	int		w;
}				t_images;


// parsing_utils
void	ft_error(int E, t_long *data);
void	check_map_wall(t_long *data);
void	check_into_map(t_long *data);
void	free_tow_d(char **map);
void	is_valid(char **data, int x, int y, char c);
int		check_path(char **data, char c);
char	**copy_data(t_long *data);
void	path_validate(char **map, t_long *data);

//
void	init_images(t_images *img);
void	init_win(t_images *img, t_long *data);
int		ft_hook(int keycode, t_images *img);
void	get_started_map(t_long *data);

#endif
