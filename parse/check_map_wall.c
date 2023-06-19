/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:18:40 by otaraki           #+#    #+#             */
<<<<<<< HEAD:parse/check_map_wall.c
/*   Updated: 2023/06/19 20:06:48 by otaraki          ###   ########.fr       */
=======
/*   Updated: 2023/06/12 16:09:24 by otaraki          ###   ########.fr       */
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b:check_map_wall.c
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_map_wall(t_long *data)
{
	int	i;
	int	j;

	i = -1;
	data->width = ft_strlen(data->map[0]);
	while (data->map[++i])
	{
		if ((int)ft_strlen(data->map[i]) != data->width)
			ft_error(1, data, "MAP NOT VALID\n");
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			ft_error(1, data, "MAP NOT VALID\n");
		if (i == 0 || i == (data->height - 1))
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] != '1')
					ft_error(1, data, "MAP NOT VALID\n");
				j++;
			}
		}
	}
}

void	path_validate(char **map, t_long *data)
{
	char	**str;

	is_valid(map, data->c_p.x, data->c_p.y, 'E');
	if (check_path(map, 'E') == -1)
		ft_error(2, data, "MAP NOT VALID\n");
	free_tow_d(map);
	str = copy_data(data);
	is_valid(str, data->c_p.x, data->c_p.y, 'C');
	if (check_path(str, 'C') == -1)
		ft_error(2, data, "MAP NOT VALID\n");
	free_tow_d(str);
}
