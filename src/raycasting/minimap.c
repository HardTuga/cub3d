/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:20:43 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/30 17:32:53 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	paint_minimap(t_data *img, t_vector2 start, int color)
{
	double	x;

	x = fabs(sqrt(pow((SCREENW - (SCREENW / 12)) - start.x, 2)
				+ pow((SCREENH - (SCREENW / 12)) - start.y, 2)));
	x = round(x);
	if (x < SCREENW / 21)
		my_mlx_pixel_put(img, start.x, start.y, color);
	else if (x <= SCREENW / 21 + 1)
		my_mlx_pixel_put(img, start.x, start.y, 0);
}

void	print_minimap(t_vector p_cords, t_vector2 start, t_all *all, int x)
{
	double	scale;

	scale = -0.0000536 * SCREENW + 0.193;
	p_cords.x = all->pl->p.x;
	start.x = SCREENW - (SCREENW / 12);
	while (start.x >= SCREENW - (SCREENW / 12) - (SCREENW / 20)
		&& start.x < SCREENW - (SCREENW / 12) + (SCREENW / 20))
	{
		if (p_cords.x < 0 || p_cords.y < 0 || p_cords.x >= all->cub->map_x
			|| p_cords.y >= all->cub->map_y || \
			all->cub->map[(int)p_cords.y][(int)p_cords.x] == ' ')
			paint_minimap(&all->mlx.img, start, MM_V);
		else if (all->cub->map[(int)p_cords.y][(int)p_cords.x] == '0')
			paint_minimap(&all->mlx.img, start, MM_F);
		else if (all->cub->map[(int)p_cords.y][(int)p_cords.x] == '1')
			paint_minimap(&all->mlx.img, start, MM_W);
		else if (all->cub->map[(int)p_cords.y][(int)p_cords.x] == '3')
			paint_minimap(&all->mlx.img, start, MM_DO);
		else
			paint_minimap(&all->mlx.img, start, MM_DC);
		p_cords.x += scale * x;
		start.x += x;
	}
}

void	do_fov(t_all *all)
{
	t_vector	player;
	t_vector	lvert;
	t_vector	rvert;

	player.x = (double)(SCREENW - (SCREENW / 12));
	player.y = (double)(SCREENH - (SCREENW / 12));
	lvert.x = all->pl->dir.x + all->pl->plane.x * -1;
	lvert.x = lvert.x * (SCREENW / 100) + player.x;
	lvert.y = all->pl->dir.y + all->pl->plane.y * -1;
	lvert.y = lvert.y * (SCREENW / 100) + player.y;
	rvert.x = all->pl->dir.x + all->pl->plane.x * 1;
	rvert.x = rvert.x * (SCREENW / 100) + player.x;
	rvert.y = all->pl->dir.y + all->pl->plane.y * 1;
	rvert.y = rvert.y * (SCREENW / 100) + player.y;
	fill_fov(all, lvert, rvert, player);
}

void	put_player(t_all *all)
{
	t_vector	player;
	int			x;
	int			y;

	player.x = (double)(SCREENW - (SCREENW / 12));
	player.y = (double)(SCREENH - (SCREENW / 12));
	y = SCREENH - (SCREENW / 12) - (SCREENW / 20);
	while (y < SCREENH - (SCREENW / 12) + (SCREENW / 20))
	{
		x = SCREENW - (SCREENW / 12) - (SCREENW / 20);
		while (x < SCREENW - (SCREENW / 12) + (SCREENW / 20))
		{
			if ((x - player.x) * (x - player.x) + \
			(y - player.y) * (y - player.y) <= 7)
				my_mlx_pixel_put(&all->mlx.img, x, y, MM_P);
			x += 1;
		}
		y += 1;
	}
}

void	minimap(t_all *all, int x, int y)
{
	t_vector	p_cords;
	t_vector2	start;
	double		scale;

	scale = -0.0000536 * SCREENW + 0.193;
	p_cords.y = all->pl->p.y;
	start.y = SCREENH - (SCREENW / 12);
	while (start.y >= SCREENH - (SCREENW / 12) - (SCREENW / 20)
		&& start.y < SCREENH - (SCREENW / 12) + (SCREENW / 20))
	{
		print_minimap(p_cords, start, all, x);
		p_cords.y += (scale * y);
		start.y += y;
	}
	if (x != 1 || y != 1)
	{
		do_fov(all);
		put_player(all);
		return ;
	}
	minimap(all, -1, -1);
	minimap(all, -1, 1);
	minimap(all, 1, -1);
}
