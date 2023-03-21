/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:32:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/03/21 20:29:41 by otaraki          ###   ########.fr       */
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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_long
{
	char	**map;
	int		collec;
	int		ply;
	int		exit;
	int		empt;
	int		wall;
	int		height;
	int		width;
}				t_long;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

// parsing_utils
void	ft_error(int E, t_long *data);
void	check_map_wall(t_long *data);
void	check_into_map(t_long *data);
void	free_tow_d(char **map);
void 	get_started_map(t_long *data);

#endif
