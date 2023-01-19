/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:28:25 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/19 18:58:00 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_wall(t_rloop *tudao, t_draw *draw, t_all *all, int y)
{
	draw->color = *(get_img_pixel(&(all->tex[tudao->side]), draw->tex_x, (int)draw->texpos));
	draw->texpos += draw->step;
	if (tudao->side == NO || tudao->side == SO)
		draw->color = mlx_get_color_value(all->mlx.mlx,
			(int)((draw->color & 0x0000FF) * 0.70)
			| (int)(((draw->color >> 8) & 0x0000FF) * 0.70) << 8
			| (int)((draw->color >> 16) * 0.70) << 16);
	my_mlx_pixel_put(&(all->mlx.img), SCREENW - draw->x - 1, y, draw->color);
}
