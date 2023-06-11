/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:54:15 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 23:07:11 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char **data, char c)
{
	int	i;
	int	j;

	i = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] == c)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	is_valid(char **data, int x, int y, char c)
{
	if ((data[y][x]) != '1' && data[y][x] != 'G')
	{
		data[y][x] = 'G';
		is_valid(data, x + 1, y, c);
		is_valid(data, x, y + 1, c);
		is_valid(data, x - 1, y, c);
		is_valid(data, x, y - 1, c);
	}
}

char	**copy_data(t_long *data)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *) * data->height + 1);
	while (data->map[i])
	{
		str[i] = ft_strdup(data->map[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
