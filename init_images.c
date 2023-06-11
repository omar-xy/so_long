/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:46:46 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 17:59:17 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*protec_img(t_images *img, char *name_f, int *a, int *b)
{
	void	*tmp;

	tmp = mlx_xpm_file_to_image(img->mlx, name_f, a, b);
	if (tmp == NULL)
	{
		exit(1);// failed if the file name doesn't exist
	}
	puts("");
	return (tmp);
}

void	init_images(t_images *img)
{
	int	a;
	int	b;

	img->wal = protec_img(img, "wallr.XPM", &a, &b);
	img->col = protec_img(img, "bluecol.xpm", &a, &b);
	img->player = protec_img(img, "Jump.xpm", &a, &b);
	img->exi = protec_img(img, "portal.xpm", &a, &b);
	img->floor = protec_img(img, "bluefloor.XPM", &a, &b);
}
