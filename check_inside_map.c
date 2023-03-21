/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:56:44 by otaraki           #+#    #+#             */
/*   Updated: 2023/03/21 18:06:37 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_dup(t_long	*data)
{
	if (data->ply != 1)
	{
		write(2, "one player required\n", 20);
		ft_error(4, data);
	}
	else if (data->exit != 1)
	{
		write(2, "one exit required\n", 18);
		ft_error(4, data);
	}
}

void	check_into_map(t_long *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->ply++;
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (data->map[i][j] == 'C')
				data->collec++;
			else if (data->map[i][j] == '0')
				data->empt++;
			else if (data->map[i][j] == '1')
				data->wall++;
			else
				ft_error(2, data);
			j++;
		}
	}
	check_for_dup(data);
}
