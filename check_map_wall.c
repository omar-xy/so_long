/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:18:40 by otaraki           #+#    #+#             */
/*   Updated: 2023/03/23 00:06:56 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_wall(t_long *data)
{
	int	i;
	int	j;

	i = -1;
	data->width = ft_strlen(data->map[0]);
	while (data->map[++i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			ft_error(1, data);
		if (i == 0 || i == (data->height - 1))
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] != '1')
					ft_error(1, data);
				j++;
			}
		}
	}
}
