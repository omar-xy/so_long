/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:36:10 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/12 00:04:18 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_handle(t_images *img)
{
	if (img->data->map[img->data->cor_ply.y][img->data->cor_ply.x + 1] != '1')
	{
		if (img->data->map[img->data->cor_ply.y][img->data->cor_ply.x + 1] == 'C')
		{
			img->data->map[img->data->cor_ply.y][img->data->cor_ply.x + 1] = '0';
			img->data->collec--;
		}
		if (img->data->map[img->data->cor_ply.y][img->data->cor_ply.x + 1] == 'E' && img->data->collec <= 0)
		{
			puts("GOOD JOB !");
			ft_error(4, img->data);
		}
		else if (img->data->map[img->data->cor_ply.y][img->data->cor_ply.x + 1] != 'E')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->floor, \
				img->data->cor_ply.x * 61, img->data->cor_ply.y * 61);
			mlx_put_image_to_window(img->mlx, img->win, img->player_r, \
				(img->data->cor_ply.x + 1) * 61, img->data->cor_ply.y * 61);
			img->data->cor_ply.x++;
			ft_putstr_fd("step ", 1);
			ft_putnbr_fd(++img->steps, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	left_handle(t_images *img)
{
	if (img->data->map[img->data->cor_ply.y][img->data->cor_ply.x - 1] != '1')
	{
		if (img->data->map[img->data->cor_ply.y][img->data->cor_ply.x - 1] == 'C')
		{
			img->data->map[img->data->cor_ply.y][img->data->cor_ply.x - 1] = '0';
			img->data->collec--;
		}
		if (img->data->map[img->data->cor_ply.y][img->data->cor_ply.x - 1] == 'E' && img->data->collec <= 0)
		{
			puts("GOOD JOB !");
			ft_error(4, img->data);
		}
		else if (img->data->map[img->data->cor_ply.y][img->data->cor_ply.x - 1] != 'E')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->floor, \
				img->data->cor_ply.x * 61, img->data->cor_ply.y * 61);
			mlx_put_image_to_window(img->mlx, img->win, img->player_l, \
				(img->data->cor_ply.x - 1) * 61, img->data->cor_ply.y * 61);
			img->data->cor_ply.x--;
			ft_putstr_fd("step ", 1);
			ft_putnbr_fd(++img->steps, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	up_handle(t_images *img)
{
	if (img->data->map[img->data->cor_ply.y - 1][img->data->cor_ply.x] != '1')
	{
		if (img->data->map[img->data->cor_ply.y - 1][img->data->cor_ply.x] == 'C')
		{
			img->data->map[img->data->cor_ply.y - 1][img->data->cor_ply.x] = '0';
			img->data->collec--;
		}
		if (img->data->map[img->data->cor_ply.y - 1][img->data->cor_ply.x] == 'E' && img->data->collec <= 0)
		{
			puts("GOOD JOB !");
			ft_error(4, img->data);
		}
		else if (img->data->map[img->data->cor_ply.y - 1][img->data->cor_ply.x] != 'E')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->floor, \
				img->data->cor_ply.x * 61, img->data->cor_ply.y * 61);
			mlx_put_image_to_window(img->mlx, img->win, img->player_r, \
				img->data->cor_ply.x * 61, (img->data->cor_ply.y - 1) * 61);
			img->data->cor_ply.y--;
			ft_putstr_fd("step ", 1);
			ft_putnbr_fd(++img->steps, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	down_handle(t_images *img)
{
	if (img->data->map[img->data->cor_ply.y + 1][img->data->cor_ply.x] != '1')
	{
		if (img->data->map[img->data->cor_ply.y + 1][img->data->cor_ply.x] == 'C')
		{
			img->data->map[img->data->cor_ply.y + 1][img->data->cor_ply.x] = '0';
			img->data->collec--;
		}
		if (img->data->map[img->data->cor_ply.y + 1][img->data->cor_ply.x] == 'E' && img->data->collec <= 0)
		{
			puts("GOOD JOB !");
			ft_error(4, img->data);
		}
		else if (img->data->map[img->data->cor_ply.y + 1][img->data->cor_ply.x] != 'E')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->floor, \
				img->data->cor_ply.x * 61, img->data->cor_ply.y * 61);
			mlx_put_image_to_window(img->mlx, img->win, img->player_l, \
				img->data->cor_ply.x * 61, (img->data->cor_ply.y + 1) * 61);
			img->data->cor_ply.y++;
			ft_putstr_fd("step ", 1);
			ft_putnbr_fd(++img->steps, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

int	ft_hook(int keycode, t_images *img)
{
	if (keycode == 2 || keycode == 124)
		right_handle(img);
	if (keycode == 0 || keycode == 123)
		left_handle(img);
	if (keycode == 13 || keycode == 126)
		up_handle(img);
	if (keycode == 1 || keycode == 125)
		down_handle(img);
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		ft_error(4,img->data);
	}
	return (1);
}
