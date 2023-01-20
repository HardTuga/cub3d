/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:20:43 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/19 15:22:43 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	print_minimap(t_vector p_cords, t_vector2 start, t_all *all, int x)
{
	double	scale;

	scale = -0.0000536 * SCREENW + 0.193;
	p_cords.x = all->pl->p.x;
	start.x = SCREENW - (SCREENW / 12);
	while (start.y >= SCREENW - (SCREENW / 12) - (SCREENW / 20)
		&& start.y < SCREENW - (SCREENW / 12) + (SCREENW / 20))
	{
		if ()
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
		return ;
	}
	minimap(all, -1, -1);
	minimap(all, -1, 1);
	minimap(all, 1, -1);
}