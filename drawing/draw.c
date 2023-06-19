/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:43:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/19 20:05:29 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	image_to_window(t_images *img, void *typ1, void *typ2, int c)
{
	if (c == 2)
	{
		mlx_put_image_to_window(img->mlx, img->win, typ1, img->h, img->w);
		mlx_put_image_to_window(img->mlx, img->win, typ2, img->h, img->w);
	}
	else
	{
		mlx_put_image_to_window(img->mlx, img->win, typ1, img->h, img->w);
	}
}

void	drawing(t_images *img)
{
	int	i;
	int	j;

	img->w = 0;
	i = -1;
	while (img->data->map[++i])
	{
		j = -1;
		img->h = 0;
		while (img->data->map[i][++j])
		{
			if (img->data->map[i][j] == '1')
				image_to_window(img, img->floor, img->wal, 2);
			else if (img->data->map[i][j] == 'C')
				image_to_window(img, img->col, NULL, 1);
			else if (img->data->map[i][j] == 'E')
				image_to_window(img, img->floor, img->exi, 2);
			else if (img->data->map[i][j] == 'P')
				image_to_window(img, img->floor, img->pr_r, 2);
			else if (img->data->map[i][j] == '0')
				image_to_window(img, img->floor, NULL, 1);
			img->h += 61;
		}
		img->w += 61;
	}
}
