/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:40:11 by otaraki           #+#    #+#             */
/*   Updated: 2023/03/21 22:25:58 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	get_started_map(t_long *data)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	(void)data;
	int a,b;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, data->width * 50, data->height * 50, "Hello world!");
	
	int i;
	int j;
	i = 0;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (data->map[i][j] == '1')
			{
				img = mlx_xpm_file_to_image(mlx, "wall.xpm",&a, &b);
				mlx_put_image_to_window(mlx, mlx_win, img,j * 50, i * 50);
				mlx_destroy_image(mlx, img);
			}
			j++;
		}
		i++;
	}
	// img = mlx_xpm_file_to_image(mlx,"o.xpm",&a,&b);
	// mlx_put_image_to_window(mlx, mlx_win, img, 50,50);
	mlx_loop(mlx);
}
