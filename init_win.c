/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:37:58 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 17:23:52 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_win(t_images *img, t_long *data)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, data->width * 61,
			data->height * 61, "HH");
}
