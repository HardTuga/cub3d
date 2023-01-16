/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:46:29 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/16 14:24:52 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_images(t_all *var)
{
	var->east.img = mlx_xpm_file_to_image(var->mlx.mlx ,var->cub->e, \
	&var->tex_height, &var->tex_width);
	var->east.addr = mlx_get_data_addr(&var->east.img, );
}