/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:46:29 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/17 19:25:50 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_images(t_all *var)
{
	var->tex[NO].img = mlx_xpm_file_to_image(var->mlx.mlx, var->cub->n,
				&var->tex[NO].img_width, &var->tex[NO].img_height);
	var->tex[NO].addr = mlx_get_data_addr(var->tex[NO].img,
				&var->tex[NO].bpp, &var->tex[NO].line_length, &var->tex[NO].endian);
	var->tex[SO].img = mlx_xpm_file_to_image(var->mlx.mlx, var->cub->s,
				&var->tex[SO].img_width, &var->tex[SO].img_height);
	var->tex[SO].addr = mlx_get_data_addr(var->tex[SO].img,
				&var->tex[SO].bpp, &var->tex[SO].line_length, &var->tex[SO].endian);
	var->tex[WE].img = mlx_xpm_file_to_image(var->mlx.mlx, var->cub->w,
				&var->tex[WE].img_width, &var->tex[WE].img_height);
	var->tex[WE].addr = mlx_get_data_addr(var->tex[WE].img,
				&var->tex[WE].bpp, &var->tex[WE].line_length, &var->tex[WE].endian);
	var->tex[EA].img = mlx_xpm_file_to_image(var->mlx.mlx, var->cub->e,
				&var->tex[EA].img_width, &var->tex[EA].img_height);
	var->tex[EA].addr = mlx_get_data_addr(var->tex[EA].img,
				&var->tex[EA].bpp, &var->tex[EA].line_length, &var->tex[EA].endian);
}

unsigned int	*get_img_pixel(t_data *data, int x, int y)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bpp / 8));
	return ((unsigned int *) pixel);
}
