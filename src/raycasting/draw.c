/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:28:25 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/23 16:25:55 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_all(t_rloop *tudao, t_draw *draw, t_all *all)
{
	int	y;

	y = -1;
	draw->step = 1.0 * all->tex[tudao->side].img_height / tudao->line_height;
	draw->texpos = (tudao->draw_start - SCREENH / 2 + tudao->line_height / 2) * draw->step;
	while (++y < tudao->draw_start)
		my_mlx_pixel_put(&(all->mlx.img), SCREENW - draw->x - 1, y, all->cub->c_trgb);
	y = tudao->draw_start;
	while (++y < tudao->draw_end)
		draw_wall(tudao, draw, all, y);
	while (++y < SCREENH)
		my_mlx_pixel_put(&all->mlx.img, SCREENW - draw->x - 1, y, all->cub->f_trgb);
}

void	draw_wall(t_rloop *tudao, t_draw *draw, t_all *all, int y)
{
	draw->tex_y = (int)draw->texpos & (all->tex[tudao->side].img_height - 1);
	draw->texpos += draw->step;
	draw->color = *(get_img_pixel(&(all->tex[tudao->side]), draw->tex_x, draw->tex_y));
	if (tudao->side == NO || tudao->side == SO)
		draw->color = mlx_get_color_value(all->mlx.mlx,
			(int)((draw->color & 0x0000FF) * 0.70)
			| (int)(((draw->color >> 8) & 0x0000FF) * 0.70) << 8
			| (int)((draw->color >> 16) * 0.70) << 16);
	my_mlx_pixel_put(&(all->mlx.img), SCREENW - draw->x - 1, y, draw->color);
}
