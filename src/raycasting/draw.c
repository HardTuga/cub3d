/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:28:25 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/02/13 13:04:07 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_util(t_rloop *tudao, t_draw *draw, t_all *all)
{
	draw->step = 1.0 * all->tex[tudao->side].img_height / \
		all->line_height;
	tudao->draw_start = (-all->line_height + all->h) / 2 + SCREENH / 2;
	if (tudao->draw_start < 0)
		tudao->draw_start = 0;
	tudao->draw_end = (all->line_height + all->h) / 2 + SCREENH / 2;
	if (tudao->draw_end > SCREENH)
		tudao->draw_end = SCREENH;
	draw->texpos = (tudao->draw_start - ((SCREENH + all->h) / 2) + \
	all->line_height / 2) * draw->step;
}

void	draw_all(t_rloop *tudao, t_draw *draw, t_all *all)
{
	int	y;

	y = -1;
	draw_util(tudao, draw, all);
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

void	choose_color(t_rloop *tudao, t_draw *draw, t_all *all)
{
	draw->step = 1.0 * all->tex[all->door_state].img_height / \
		all->line_height;
	draw->texpos = (tudao->draw_start - ((SCREENH + all->h) / 2) + \
	all->line_height / 2) * draw->step;
	draw->tex_y = (int)draw->texpos \
	& (all->tex[all->door_state].img_height - 1);
	draw->texpos += draw->step;
	draw->color = *(get_img_pixel(&(all->tex[all->door_state]), \
	draw->tex_x, draw->tex_y));
}

void	draw_door(t_rloop *tudao, t_draw *draw, t_all *all, int y)
{
	choose_color(tudao, draw, all);
	if ((tudao->side == NO || tudao->side == SO) && draw->color != 0xff000000)
		draw->color = mlx_get_color_value(all->mlx.mlx,
				(int)((draw->color & 0x0000FF) * 0.70)
				| (int)(((draw->color >> 8) & 0x0000FF) * 0.70) << 8
				| (int)((draw->color >> 16) * 0.70) << 16);
	if (draw->color != 0xff000000)
		my_mlx_pixel_put(&(all->mlx.img), \
		SCREENW - draw->x - 1, y, draw->color);
	if (y + 1 == tudao->draw_end)
	{
		my_mlx_pixel_put(&all->mlx.img, \
		SCREENW - draw->x - 1, y, all->cub->f_trgb);
		all->hit_door = false;
	}
}

void	draw_wall(t_rloop *tudao, t_draw *draw, t_all *all, int y)
{
	draw->tex_y = (int)draw->texpos & (all->tex[tudao->side].img_height - 1);
	draw->texpos += draw->step;
	draw->color = *(get_img_pixel(&(all->tex[tudao->side]), \
	draw->tex_x, draw->texpos));
	if (tudao->side == NO || tudao->side == SO)
		draw->color = mlx_get_color_value(all->mlx.mlx,
				(int)((draw->color & 0x0000FF) * 0.70)
				| (int)(((draw->color >> 8) & 0x0000FF) * 0.70) << 8
				| (int)((draw->color >> 16) * 0.70) << 16);
	my_mlx_pixel_put(&(all->mlx.img), SCREENW - draw->x - 1, y, draw->color);
}
