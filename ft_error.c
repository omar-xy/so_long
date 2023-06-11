/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:58:13 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/10 17:09:58 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int E, t_long	*data)
{
	if (E == 1)
	{
		write(2, "MAP NOT VALID\n", 14);
		exit (1);
	}
	else if (E == 2)
	{
		write(2, "Invalid arguments in map\n", 25);
		free_tow_d(data->map);
		exit (1);
	}
	else if (E == 3)
	{
		write(2, "cant open file\n", 15);
		exit (1);
	}
	else
	{
		write(2, "PATH INVALID\n", 13);
		free_tow_d(data->map);
		exit (1);
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
