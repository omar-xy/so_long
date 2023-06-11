/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:46:46 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 23:50:14 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*protec_img(t_images *img, char *name_f)
{
	void	*tmp;
	int		a;
	int		b;

	tmp = mlx_xpm_file_to_image(img->mlx, name_f, &a, &b);
	if (tmp == NULL)
		exit(1);// failed if the file name doesn't exist
	return (tmp);
}

void	init_images(t_images *img)
{
	img->wal = protec_img(img, "wallr.XPM");
	img->col = protec_img(img, "bluecol.xpm");
	img->player_r = protec_img(img, "Jump.xpm");
	img->player_l = protec_img(img, "left_jump.xpm");
	img->exi = protec_img(img, "portal.xpm");
	img->floor = protec_img(img, "bluefloor.XPM");
}
