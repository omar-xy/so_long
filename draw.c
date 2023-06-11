/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:43:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 16:46:25 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawing(t_long *data, t_long *img)
{
	while (data->map[i])
	{
		h = 0;
		j = -1;
		while (data->map[i][++j])
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
		}
		w += 61;
		i++;
	}
}
