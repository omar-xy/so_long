/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:02:37 by otaraki           #+#    #+#             */
<<<<<<< HEAD:parse/so_long.c
/*   Updated: 2023/06/19 20:06:55 by otaraki          ###   ########.fr       */
=======
/*   Updated: 2023/06/12 18:51:21 by otaraki          ###   ########.fr       */
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b:so_long.c
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

void	tst(void)
{
	system("leaks so_long");
}

static void	set_map(t_long *data)
{
	char	**str;
<<<<<<< HEAD:parse/so_long.c
	
=======

	atexit(tst);
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b:so_long.c
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
<<<<<<< HEAD:parse/so_long.c
	if (!tmp || !tmp[0])
		ft_error(1, NULL, "MAP INVALID\n");
=======
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b:so_long.c
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
}
