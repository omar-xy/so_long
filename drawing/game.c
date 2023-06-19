/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:40:11 by otaraki           #+#    #+#             */
<<<<<<< HEAD:drawing/game.c
/*   Updated: 2023/06/19 20:05:49 by otaraki          ###   ########.fr       */
=======
/*   Updated: 2023/06/12 18:39:15 by otaraki          ###   ########.fr       */
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b:game.c
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	red_cross(int key)
{
	(void)key;
	exit(0);
	return (1);
}

void	get_started_map(t_long *data)
{
	t_images	*img;

	img = malloc (sizeof (t_images));
	if (img == NULL)
		return ;
	img->data = data;
	init_win(img);
	init_images(img);
	drawing(img);
	img->steps = 0;
	mlx_hook(img->win, 02, 0, &ft_hook, img);
	mlx_hook(img->win, 17, 0, &red_cross, NULL);
	mlx_loop(img->mlx);
}
