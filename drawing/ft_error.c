/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:58:13 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/19 20:05:44 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(int E, t_long	*data, char *str)
{
	if (E == 1)
	{
		ft_putstr_fd(str, 2);
		exit (1);
	}
	else if (E == 2)
	{
		ft_putstr_fd(str, 2);
		free_tow_d(data->map);
		exit (1);
	}
	else if (E == 4)
	{
		ft_putstr_fd(str, 1);
		free_tow_d(data->map);
		exit (0);
	}
}

void	free_tow_d(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
