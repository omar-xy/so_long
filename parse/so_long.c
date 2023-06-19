/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:02:37 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/19 20:37:45 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_get_map(char *av, t_long *data)
{
	int		fd;
	int		i;
	char	*str;

	data->map = ft_calloc(sizeof(char *), (data->height + 1));
	if (data->map == NULL)
		return ;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(2, data, "can't open file\n");
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

static void	calculate_height(t_long *data, char *av)
{
	int		fd;
	char	*tmp;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(1, NULL, "can't open file");
	tmp = get_next_line(fd);
	if (!tmp || !tmp[0])
		ft_error(1, NULL, "MAP INVALID\n");
	while (tmp != NULL)
	{
		data->height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (tmp != NULL)
		free(tmp);
	close(fd);
}

int	main(int ac, char **av)
{
	t_long	data;

	if (ac == 2)
	{
		calculate_height(&data, av[1]);
		ft_get_map(av[1], &data);
		set_map(&data);
	}
	else
		ft_putstr_fd("INVALD ARGUMENTS\n", 2);
}
