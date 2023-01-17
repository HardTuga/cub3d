/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:46:29 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/17 11:59:19 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_images(t_all *var)
{
	var->tex[0].img = mlx_xpm_file_to_image(var->mlx.mlx, var->cub->n,
		&var->tex[0].img_width, &var->tex[0].img_height);
	var->tex[0].addr = mlx_get_data_addr(var->tex[0].img,
		var->tex[0].bits_per_pixel, var->tex[0].line_length, var->tex[0].endian);
	var->tex[1].img = mlx_xpm_file_to_image(var->mlx.mlx, var->cub->s,
		&var->tex[1].img_width, &var->tex[1].img_height);
	var->tex[1].addr = mlx_get_data_addr(var->tex[1].img,
		var->tex[1].bits_per_pixel, var->tex[1].line_length, var->tex[1].endian);
	var->tex[2].img = mlx_xpm_file_to_image(var->mlx.mlx, var->cub->w,
		&var->tex[2].img_width, &var->tex[2].img_height);
	var->tex[2].addr = mlx_get_data_addr(var->tex[2].img,
		var->tex[2].bits_per_pixel, var->tex[2].line_length, var->tex[2].endian);
	var->tex[3].img = mlx_xpm_file_to_image(var->mlx.mlx, var->cub->e,
		&var->tex[3].img_width, &var->tex[3].img_height);
	var->tex[3].addr = mlx_get_data_addr(var->tex[3].img,
		var->tex[3].bits_per_pixel, var->tex[3].line_length, var->tex[3].endian);
}