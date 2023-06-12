/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:37:58 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/12 18:24:47 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_win(t_images *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, img->data->width * 61,
			img->data->height * 61, "THE WITCH");
}
