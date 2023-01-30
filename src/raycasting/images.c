/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:46:29 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/30 17:56:31 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_gun(t_all *var)
{
	var->tex[GUN5].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN5].img_width, &var->tex[GUN5].img_height);
	var->tex[GUN5].addr = mlx_get_data_addr(var->tex[GUN5].img, \
	&var->tex[GUN5].bpp, &var->tex[GUN5].line_length, &var->tex[GUN5].endian);
	var->tex[GUN6].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN6].img_width, &var->tex[GUN6].img_height);
	var->tex[GUN6].addr = mlx_get_data_addr(var->tex[GUN6].img, \
	&var->tex[GUN6].bpp, &var->tex[GUN6].line_length, &var->tex[GUN6].endian);
	var->tex[GUN7].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN7].img_width, &var->tex[GUN7].img_height);
	var->tex[GUN7].addr = mlx_get_data_addr(var->tex[GUN7].img, \
	&var->tex[GUN7].bpp, &var->tex[GUN7].line_length, &var->tex[GUN7].endian);
	var->tex[GUN8].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN8].img_width, &var->tex[GUN8].img_height);
	var->tex[GUN8].addr = mlx_get_data_addr(var->tex[GUN8].img, \
	&var->tex[GUN8].bpp, &var->tex[GUN8].line_length, &var->tex[GUN8].endian);
	var->tex[GUN9].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN9].img_width, &var->tex[GUN9].img_height);
	var->tex[GUN9].addr = mlx_get_data_addr(var->tex[GUN9].img, \
	&var->tex[GUN9].bpp, &var->tex[GUN9].line_length, &var->tex[GUN9].endian);
}

void	init_door_image(t_all *var)
{
	var->tex[D_O].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[D_O].img_width, &var->tex[D_O].img_height);
	var->tex[D_O].addr = mlx_get_data_addr(var->tex[D_O].img, \
	&var->tex[D_O].bpp, &var->tex[D_O].line_length, &var->tex[D_O].endian);
	var->tex[D_C].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_1.xpm", &var->tex[D_C].img_width, &var->tex[D_C].img_height);
	var->tex[D_C].addr = mlx_get_data_addr(var->tex[D_C].img, \
	&var->tex[D_C].bpp, &var->tex[D_C].line_length, &var->tex[D_C].endian);
	var->tex[GUN1].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN1].img_width, &var->tex[GUN1].img_height);
	var->tex[GUN1].addr = mlx_get_data_addr(var->tex[GUN1].img, \
	&var->tex[GUN1].bpp, &var->tex[GUN1].line_length, &var->tex[GUN1].endian);
	var->tex[GUN2].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN2].img_width, &var->tex[GUN2].img_height);
	var->tex[GUN2].addr = mlx_get_data_addr(var->tex[GUN2].img, \
	&var->tex[GUN2].bpp, &var->tex[GUN2].line_length, &var->tex[GUN2].endian);
	var->tex[GUN3].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN3].img_width, &var->tex[GUN3].img_height);
	var->tex[GUN3].addr = mlx_get_data_addr(var->tex[GUN3].img, \
	&var->tex[GUN3].bpp, &var->tex[GUN3].line_length, &var->tex[GUN3].endian);
	var->tex[GUN4].img = mlx_xpm_file_to_image(var->mlx.mlx, \
	"./assets/gate_4.xpm", &var->tex[GUN4].img_width, &var->tex[GUN4].img_height);
	var->tex[GUN4].addr = mlx_get_data_addr(var->tex[GUN4].img, \
	&var->tex[GUN4].bpp, &var->tex[GUN4].line_length, &var->tex[GUN4].endian);
	init_gun(var);
}

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
	init_door_image(var);
}

unsigned int	*get_img_pixel(t_data *data, int x, int y)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bpp / 8));
	return ((unsigned int *) pixel);
}
