/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:24:31 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/27 14:27:50 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

double	get_line_b(t_vector p_a, t_vector p_b)
{
	double	line_b;

	if (p_b.x - p_a.x == 0)
		line_b = 0;
	else
		line_b = ((p_b.y - p_a.y) * p_b.x + ((p_b.x - p_a.x) * p_b.y)
				* -1) / ((p_b.x - p_a.x) * -1);
	return (line_b);
}

bool	inside(t_vector p_a, t_vector p_b, t_vector p_c, t_vector target)
{
	static int	depth = 0;
	double		line_d_c;
	double		line_d_t;
	double		line_b;

	if (depth == 3)
		depth = 0;
	line_b = get_line_b(p_a, p_b);
	line_d_c = (p_b.y - p_a.y) * p_c.x + ((p_b.x - p_a.x)
			* p_c.y * -1) + (p_b.x - p_a.x) * line_b;
	line_d_t = (p_b.y - p_a.y) * target.x + ((p_b.x - p_a.x)
			* target.y * -1) + (p_b.x - p_a.x) * line_b;
	if ((line_d_c <= 0 && line_d_t <= 0) || (line_d_c > 0 && line_d_t > 0))
	{
		depth++;
		if (depth - 1 == 0)
			return (inside(p_b, p_c, p_a, target));
		if (depth - 1 == 1)
			return (inside(p_c, p_b, p_a, target));
		if (depth - 1 == 2)
			return (true);
	}
	depth = 0;
	return (false);
}

void	fill_fov(t_all *all, t_vector lvert, t_vector rvert, t_vector player)
{
	t_vector	min;
	t_vector	max;
	t_vector	target;

	min.x = get_min(get_min(player.x, lvert.x), rvert.x);
	min.y = get_min(get_min(player.y, lvert.y), rvert.y);
	max.x = get_max(get_max(player.x, lvert.x), rvert.x);
	max.y = get_max(get_max(player.y, lvert.y), rvert.y);
	target.x = min.x;
	target.y = min.y;
	while (target.y <= max.y)
	{
		while (target.x <= max.x)
		{
			if (inside(player, lvert, rvert, target) == true)
				my_mlx_pixel_put(&all->mlx.img, \
				(int)target.x, (int)target.y, MM_FOV);
			target.x += 1.0;
		}
		target.x = min.x;
		target.y += 1.0;
	}
}
