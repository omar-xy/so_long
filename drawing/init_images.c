/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:46:46 by otaraki           #+#    #+#             */
<<<<<<< HEAD:drawing/init_images.c
/*   Updated: 2023/06/19 20:05:57 by otaraki          ###   ########.fr       */
=======
/*   Updated: 2023/06/12 18:55:06 by otaraki          ###   ########.fr       */
>>>>>>> 42ae2ea5cc5d46a05e69fe4d054e1233ab2d158b:init_images.c
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*protec_img(t_images *img, char *name_f)
{
	void	*tmp;
	int		a;
	int		b;

	tmp = mlx_xpm_file_to_image(img->mlx, name_f, &a, &b);
	if (tmp == NULL)
	{
		ft_error(2, img->data, "IMAGE NOT FOUND!\n");
		exit (1);
	}
	return (tmp);
}

void	init_images(t_images *img)
{
	img->wal = protec_img(img, "wallr.XPM");
	img->col = protec_img(img, "bluecol.xpm");
	img->pr_r = protec_img(img, "Jump.xpm");
	img->pr_l = protec_img(img, "left_jump.xpm");
	img->exi = protec_img(img, "portal.xpm");
	img->floor = protec_img(img, "bluefloor.XPM");
}
