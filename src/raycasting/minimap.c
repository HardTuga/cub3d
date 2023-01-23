/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:20:43 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/23 12:06:14 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	paint_minimap(t_data *data, t_vector2 start, int color)
{
	double	x;

	x = fabs(sqrt(pow((SCREENW - (SCREENW / 12)) - start.x, 2)
				+ pow((SCREENH - (SCREENW / 12)) - start.y, 2)));
	x = round(x);
	if (x < SCREENW / 21)
		my_mlx_pixel_put(data, start.x, start.y, color);
	else if (x <= SCREENW / 21 + 1)
		my_mlx_pixel_put(data, start.x, start.y, 0);
}

void	print_minimap(t_vector p_cords, t_vector2 start, t_all *all, int x)
{
	double	scale;

	scale = -0.0000536 * SCREENW + 0.193;
	p_cords.x = all->pl->p.x;
	start.x = SCREENW - (SCREENW / 12);
	while (start.y >= SCREENW - (SCREENW / 12) - (SCREENW / 20)
		&& start.y < SCREENW - (SCREENW / 12) + (SCREENW / 20))
	{
		if (all->cub->map[(int)p_cords.y][(int)p_cords.x] &&
			all->cub->map[(int)p_cords.y][(int)p_cords.x] == '0')
			paint_minimap(&all->mlx.img, start, mm_floor);
		else if (all->cub->map[(int)p_cords.y][(int)p_cords.x] &&
			all->cub->map[(int)p_cords.y][(int)p_cords.x] == '1')
			paint_minimap(&all->mlx.img, start, mm_wall);
		else if (all->cub->map[(int)p_cords.y][(int)p_cords.x] &&
			all->cub->map[(int)p_cords.y][(int)p_cords.x] == '2')
			paint_minimap(&all->mlx.img, start, mm_door_closed);
		else if (all->cub->map[(int)p_cords.y][(int)p_cords.x] &&
			all->cub->map[(int)p_cords.y][(int)p_cords.x] == '3')
			paint_minimap(&all->mlx.img, start, mm_door_open);
		else
			paint_minimap(&all->mlx.img, start, mm_void);
		p_cords.x += scale * x;
		start.x += x;
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
		//do_fov(all);
		return ;
	}
	minimap(all, -1, -1);
	minimap(all, -1, 1);
	minimap(all, 1, -1);
}