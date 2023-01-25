/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:24:31 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/25 17:00:30 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	get_min(int a, int b)
{
	if(a < b)
		return(a);
	return (b);
}

int	get_max(int a, int b)
{
	if(a > b)
		return(a);
	return (b);
}

double	get_line_b(t_vector2 player, t_vector2 lvert)
{
	double	line_b;

	if (lvert.x - player.x == 0)
		line_b = 0;
	else
		line_b = ((lvert.y - player.y) * lvert.x + ((lvert.x - player.x) +
				lvert.y) * -1) / ((lvert.x - player.x) * -1);
	return(line_b);
}

bool	inside(t_vector2 player, t_vector2 lvert, t_vector2 rvert, t_vector2 p)
{
	static int	depth = 0;
	double		line_d_c;
	double		line_d_t;
	double		line_b;

	if (depth == 3)
		depth = 0;
	line_b = get_line_b(player, lvert);
	line_d_c = (lvert.y - player.y) * rvert.x + ((lvert.x - player.x) *
				rvert.y - 1) + (lvert.x- player.x) * line_b;
	line_d_t = (lvert.y - player.y) * p.x + ((lvert.x - player.x) *
				rvert.y - 1) + (lvert.x- player.x) * line_b;
	if ((line_d_c <= 0 && line_d_t <= 0) || (line_d_c > 0 && line_d_t > 0))
	{
		depth++;
		if (depth - 1 == 0)
			return(inside(lvert, rvert, player, p));
		if (depth - 1 == 1)
			return(inside(rvert, lvert, player, p));
		if (depth - 1 == 2)
			return(true);
	}
	depth = 0;
	return(false);
}

void	fill_fov(t_all *all, t_vector2 lvert, t_vector2 rvert, t_vector2 player)
{
	t_vector2	min;
	t_vector2	max;
	t_vector2	point;

	min.x = get_min(get_min(player.x, lvert.x), rvert.x);
	min.y = get_min(get_min(player.y, lvert.y), rvert.y);
	max.x = get_max(get_max(player.x, lvert.x), rvert.x);
	max.y = get_max(get_max(player.y, lvert.y), rvert.y);
	point.x = min.x;
	point.y = min.y;
	while(point.y <= max.y)
	{
		while(point.x <= max.x)
		{
			if(inside(player, lvert, rvert, point))
				my_mlx_pixel_put(&all->mlx.img, point.x, point.y, MM_FOV);
			point.x += 1;
		}
		point.x = min.x;
		point.y += 1;
	}
}