/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:28:25 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/25 14:40:58 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_all(t_rloop *tudao, t_draw *draw, t_all *all)
{
	int	y;

	y = -1;
	if (tudao->hit_door == true)
		draw->step = 1.0 * all->tex[tudao->door_state].img_height / \
			tudao->line_height;
	else
		draw->step = 1.0 * all->tex[tudao->side].img_height / \
			tudao->line_height;
	draw->texpos = (tudao->draw_start - (SCREENH / 2) + all->h + \
	tudao->line_height / 2) * draw->step;
	tudao->draw_start = -tudao->line_height / 2 + SCREENH / 2 + all->h;
	if (tudao->draw_start < 0)
		tudao->draw_start = 0;
	tudao->draw_end = tudao->line_height / 2 + SCREENH / 2 + all->h;
	if (tudao->draw_end > SCREENH)
		tudao->draw_end = SCREENH;
	while (++y < tudao->draw_start)
		my_mlx_pixel_put(&(all->mlx.img), SCREENW - \
		draw->x - 1, y, all->cub->c_trgb);
	y = tudao->draw_start;
	while (++y < tudao->draw_end)
		draw_wall(tudao, draw, all, y);
	while (++y < SCREENH)
		my_mlx_pixel_put(&all->mlx.img, SCREENW - \
		draw->x - 1, y, all->cub->f_trgb);
}

void	draw_wall(t_rloop *tudao, t_draw *draw, t_all *all, int y)
{
	if (tudao->hit_door == true)
		draw->tex_y = (int)draw->texpos & \
		(all->tex[tudao->door_state].img_height - 1);
	else
		draw->tex_y = (int)draw->texpos & \
		(all->tex[tudao->side].img_height - 1);
	draw->texpos += draw->step;
	if (tudao->hit_door == true)
		draw->color = *(get_img_pixel(&(all->tex[tudao->door_state]), \
		draw->tex_x, draw->tex_y));
	else
		draw->color = *(get_img_pixel(&(all->tex[tudao->side]), \
		draw->tex_x, draw->tex_y));
	if (tudao->side == NO || tudao->side == SO)
		draw->color = mlx_get_color_value(all->mlx.mlx,
				(int)((draw->color & 0x0000FF) * 0.70)
				| (int)(((draw->color >> 8) & 0x0000FF) * 0.70) << 8
				| (int)((draw->color >> 16) * 0.70) << 16);
	my_mlx_pixel_put(&(all->mlx.img), SCREENW - draw->x - 1, y, draw->color);
}
