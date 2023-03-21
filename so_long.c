/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:02:37 by otaraki           #+#    #+#             */
/*   Updated: 2023/03/21 20:57:20 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_h_w(char *str, t_long *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error(3, data);
	while (get_next_line(fd))
		i++;
	data->height = i;
	close(fd);
	fd = open(str, O_RDONLY);
	str = get_next_line(fd);
	data->width = ft_strlen(str);
	close(fd);
	free(str);
}

void	ft_get_map(char *av, t_long *data)
{
	int		fd;
	int		i;
	char	*str;

	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (data->map == NULL)
		return ;
	fd = open(av, O_RDONLY);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		data->map[i] = ft_strtrim(str, "\n");
		if (str == NULL)
			break ;
		free(str);
		i++;
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_long	data;

	(void)data;
	//check for .ber in file name
	if (ac == 2)
		calculate_h_w(av[1], &data);
	else
		exit(1);
	ft_get_map(av[1], &data);
	check_map_wall(&data);
	check_into_map(&data);
	get_started_map(&data);
	return (0);
}
