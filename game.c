/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:40:11 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/12 00:02:26 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int red_cross(int key)
{
	(void)key;
	exit(0);
	return (1);
}

void	get_started_map(t_long *data)
{
	t_images	*img;
	int			j;
	int			i;
	int			h;
	int			w;

	(void)data;
	i = 0;
	w = 0;
	img = malloc (sizeof (t_images));
	init_win(img, data);
	init_images(img);
	img->steps = 0;
	img->data = data;
	while (img->data->map[i])
	{
		h = 0;
		j = 0;
		while (img->data->map[i][j])
		{
			if (img->data->map[i][j] == '1')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->floor, h, w);
				mlx_put_image_to_window(img->mlx, img->win, img->wal, h, w);
			}
			else if (img->data->map[i][j] == 'C')
				mlx_put_image_to_window(img->mlx, img->win, img->col, h, w);
			else if (img->data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->floor, h, w);
				mlx_put_image_to_window(img->mlx, img->win, img->exi, h, w);
			}
			else if (img->data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->floor, h, w);
				mlx_put_image_to_window(img->mlx, img->win, img->player_r, h, w);
			}
			else if (img->data->map[i][j] == '0')
				mlx_put_image_to_window(img->mlx, img->win, img->floor, h, w);
			h += 61;
			j++;
		}
		w += 61;
		i++;
	}
	
	mlx_hook(img->win, 02, 0, &ft_hook, img);
	mlx_hook(img->win, 17, 0, &red_cross, NULL);

	mlx_loop(img->mlx);
}
