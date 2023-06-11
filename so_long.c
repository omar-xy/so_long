/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:02:37 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 23:28:54 by otaraki          ###   ########.fr       */
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
	data->map[i] = NULL;
	free(str);
	close(fd);
}

static void	set_map(t_long *data)
{
	char	**str;

	if (data->map && data->map[0])
	{
		check_map_wall(data);
		check_into_map(data);
		str = copy_data(data);
		path_validate(str, data);
		get_started_map(data);
	}
}

int	main(int ac, char **av)
{
	t_long	data;
	int		fd;
	char	*tmp;


	if (ac == 2)
	{
		// I need to check about the name of the map file should end with .ber
		fd = open(av[1], O_RDONLY);

		if (fd == -1)
			ft_error(3, NULL);
		tmp = get_next_line(fd);
		while (tmp != NULL)
		{
			data.height++;
			free(tmp);
			tmp = get_next_line(fd);
		}
		if (tmp != NULL)
			free(tmp);
		ft_get_map(av[1], &data);
		set_map(&data);
	}
}
