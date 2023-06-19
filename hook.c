/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:36:10 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/12 16:12:20 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_handle(t_images *img)
{
	if (img->data->map[img->data->c_p.y][img->data->c_p.x + 1] != '1')
	{
		if (img->data->map[img->data->c_p.y][img->data->c_p.x + 1] == 'C')
		{
			img->data->map[img->data->c_p.y][img->data->c_p.x + 1] = '0';
			img->data->collec--;
		}
		if (img->data->map[img->data->c_p.y][img->data->c_p.x + 1] == 'E'
			&& img->data->collec <= 0)
			ft_error(4, img->data, "GOOD JOB !");
		else if (img->data->map[img->data->c_p.y][img->data->c_p.x + 1] != 'E')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->floor, \
				img->data->c_p.x * 61, img->data->c_p.y * 61);
			mlx_put_image_to_window(img->mlx, img->win, img->pr_r, \
				(img->data->c_p.x + 1) * 61, img->data->c_p.y * 61);
			img->data->c_p.x++;
			ft_putstr_fd("step ", 1);
			ft_putnbr_fd(++img->steps, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	left_handle(t_images *img)
{
	if (img->data->map[img->data->c_p.y][img->data->c_p.x - 1] != '1')
	{
		if (img->data->map[img->data->c_p.y][img->data->c_p.x - 1] == 'C')
		{
			img->data->map[img->data->c_p.y][img->data->c_p.x - 1] = '0';
			img->data->collec--;
		}
		if (img->data->map[img->data->c_p.y][img->data->c_p.x - 1] == 'E'
			&& img->data->collec <= 0)
			ft_error(4, img->data, "GOOD JOB !");
		else if (img->data->map[img->data->c_p.y][img->data->c_p.x - 1] != 'E')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->floor, \
				img->data->c_p.x * 61, img->data->c_p.y * 61);
			mlx_put_image_to_window(img->mlx, img->win, img->pr_l, \
				(img->data->c_p.x - 1) * 61, img->data->c_p.y * 61);
			img->data->c_p.x--;
			ft_putstr_fd("step ", 1);
			ft_putnbr_fd(++img->steps, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	up_handle(t_images *img)
{
	if (img->data->map[img->data->c_p.y - 1][img->data->c_p.x] != '1')
	{
		if (img->data->map[img->data->c_p.y - 1][img->data->c_p.x] == 'C')
		{
			img->data->map[img->data->c_p.y - 1][img->data->c_p.x] = '0';
			img->data->collec--;
		}
		if (img->data->map[img->data->c_p.y - 1][img->data->c_p.x] == 'E' 
			&& img->data->collec <= 0)
			ft_error(4, img->data, "GOOD JOB !");
		else if (img->data->map[img->data->c_p.y - 1][img->data->c_p.x] != 'E')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->floor, \
				img->data->c_p.x * 61, img->data->c_p.y * 61);
			mlx_put_image_to_window(img->mlx, img->win, img->pr_r, \
				img->data->c_p.x * 61, (img->data->c_p.y - 1) * 61);
			img->data->c_p.y--;
			ft_putstr_fd("step ", 1);
			ft_putnbr_fd(++img->steps, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	down_handle(t_images *img)
{
	if (img->data->map[img->data->c_p.y + 1][img->data->c_p.x] != '1')
	{
		if (img->data->map[img->data->c_p.y + 1][img->data->c_p.x] == 'C')
		{
			img->data->map[img->data->c_p.y + 1][img->data->c_p.x] = '0';
			img->data->collec--;
		}
		if (img->data->map[img->data->c_p.y + 1][img->data->c_p.x] == 'E' 
			&& img->data->collec <= 0)
			ft_error(4, img->data, "GOOD JOB !");
		else if (img->data->map[img->data->c_p.y + 1][img->data->c_p.x] != 'E')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->floor, \
				img->data->c_p.x * 61, img->data->c_p.y * 61);
			mlx_put_image_to_window(img->mlx, img->win, img->pr_l, \
				img->data->c_p.x * 61, (img->data->c_p.y + 1) * 61);
			img->data->c_p.y++;
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
		ft_error(4, img->data, "NICE TO MEET YOU!");
	}
	return (1);
}
