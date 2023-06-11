/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:40:11 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 21:23:10 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	while (data->map[i])
	{
		h = 0;
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->floor, h, w);
				mlx_put_image_to_window(img->mlx, img->win, img->wal, h, w);
			}
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(img->mlx, img->win, img->col, h, w);
			else if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->floor, h, w);
				mlx_put_image_to_window(img->mlx, img->win, img->exi, h, w);
			}
			else if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(img->mlx, img->win, img->floor, h, w);
				mlx_put_image_to_window(img->mlx, img->win, img->player, h, w);
			}
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(img->mlx, img->win, img->floor, h, w);
			h += 61;
			j++;
		}
		w += 61;
		i++;
	}
	img->data = data;
	mlx_hook(img->win, 02, 0, &ft_hook, img);
	mlx_loop(img->mlx);
}
