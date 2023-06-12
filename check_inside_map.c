/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:27:23 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/12 16:17:35 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	check_for_dup(t_long	*data)
{
	if (data->ply != 1)
		ft_error(2, data, "INVALID ARGUMENTS IN MAP\n");
	else if (data->exit != 1)
		ft_error(2, data, "INVALID ARGUMENTS IN MAP\n");
}

static void	get_pos(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
			{
				data->c_p.x = j;
				data->c_p.y = i;
			}
			if (data->map[i][j] == 'E')
			{
				data->c_e.x = j;
				data->c_e.y = i;
			}
		}
		i++;
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
			else if (data->map[i][j] != '1' && data->map[i][j] != '0')
				ft_error(2, data, "INVALID ARGUMENTS IN MAP\n");
			j++;
		}
	}
	check_for_dup(data);
	get_pos(data);
}
