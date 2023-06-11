/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:36:10 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 17:23:49 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_handle(t_images **img)
{
	(void)img;
	printf("right_handle\n");
}

void	left_handle(t_images **img)
{
	(void)img;
	printf("left_handle\n");
}

void	up_handle(t_images **img)
{
	(void)img;
	printf("up_handle\n");
}

void	down_handle(t_images **img)
{
	(void)img;
	printf("down_handle\n");
}

int	ft_hook(int keycode, t_images *img)
{
	if (keycode == 2 || keycode == 124)
		right_handle(&img);
	if (keycode == 0 || keycode == 123)
		left_handle(&img);
	if (keycode == 13 || keycode == 126)
		up_handle(&img);
	if (keycode == 1 || keycode == 125)
		down_handle(&img);
	printf("%d\n", keycode);
	return (1);
}
