/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:46:46 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/19 20:40:01 by otaraki          ###   ########.fr       */
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
	img->wal = protec_img(img, "./images/wallr.xpm");
	img->col = protec_img(img, "./images/bluecol.xpm");
	img->pr_r = protec_img(img, "./images/Jump.xpm");
	img->pr_l = protec_img(img, "./images/left_jump.xpm");
	img->exi = protec_img(img, "./images/portal.xpm");
	img->floor = protec_img(img, "./images/bluefloor.xpm");
}
