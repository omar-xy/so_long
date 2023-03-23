/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:02:37 by otaraki           #+#    #+#             */
/*   Updated: 2023/03/23 00:15:34 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map(char *av, t_long *data)
{
	int		fd;
	int		i;
	char	*str;

	data->map = ft_calloc(sizeof(char *), (data->height + 1));
	if (data->map == NULL)
		return ;
	fd = open(av, O_RDONLY);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL || !*str)
			break ;
		data->map[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	free(str);
	close(fd);
}

static void	path_validate(char **map, t_long *data)
{
	char	**str;

	is_valid(map, data->cor_ply.x, data->cor_ply.y, 'E');
	if (check_path(map, 'E') == -1)
		ft_error(4, data);
	free_tow_d(map);
	str = copy_data(data);
	is_valid(str, data->cor_ply.x, data->cor_ply.y, 'F');
	if (check_path(map, 'F') == -1)
		ft_error(4, data);
	free_tow_d(str);
}

int	main(int ac, char **av)
{
	t_long	data;
	int		fd;
	char	**str;
	char	*tmp;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_error(3, &data);
		tmp = get_next_line(fd);
		while (tmp != NULL)
		{
			data.height++;
			free(tmp);
			tmp = get_next_line(fd);
		}
		if (tmp)
			free(tmp);
		ft_get_map(av[1], &data);
		if (data.map && data.map[0])
		{
			check_map_wall(&data);
			check_into_map(&data);
			str = copy_data(&data);
			path_validate(str, &data);
			get_started_map(&data);
		}
		return (0);
	}
}
