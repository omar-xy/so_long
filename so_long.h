/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:32:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/03/22 23:34:45 by otaraki          ###   ########.fr       */
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


// parsing_utils
void	ft_error(int E, t_long *data);
void	check_map_wall(t_long *data);
void	check_into_map(t_long *data);
void	free_tow_d(char **map);
void	get_started_map(t_long *data);
void	is_valid(char **data, int x, int y, char c);
char	**copy_data(t_long *data);
int		check_path(char **data, char c);

#endif
