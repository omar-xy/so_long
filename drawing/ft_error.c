/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:58:13 by otaraki           #+#    #+#             */
<<<<<<< HEAD:drawing/ft_error.c
/*   Updated: 2023/06/19 20:05:44 by otaraki          ###   ########.fr       */
=======
/*   Updated: 2023/06/12 18:46:08 by otaraki          ###   ########.fr       */
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b:ft_error.c
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
