/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:22:50 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/27 14:18:50 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

bool	col(char c)
{
	if (c == '1' || c == '2')
		return (true);
	return (false);
}

static bool	colider(double posx, double posy, t_vector2 *c, char **map)
{
	bool		no_cool;
	double		old_dir;
	double		angle;
	t_vector	vector;

	no_cool = true;
	angle = 0;
	vector.x = 0.25;
	vector.y = 0;
	while (angle < M_PI * 2)
	{
		old_dir = vector.x;
		vector.x = vector.x * cos(angle) - vector.y * sin(angle);
		vector.y = old_dir * sin(angle) + vector.y * cos(angle);
		if (c && col(map[(int)(posy)][(int)(posx + vector.x)]))
			c->x = false;
		if (c && col(map[(int)(posy + vector.y)][(int)(posx)]))
			c->y = false;
		if (col(map[(int)(posy + vector.y)][(int)(posx + vector.x)]))
			no_cool = false;
		if (!no_cool && (!c || !c->x) && (!c || !c->y))
			return (false);
		angle += M_1_PI;
	}
	return (no_cool);
}

void	colision(t_all *all, t_vector v)
{
	t_vector2	c;

	c.x = true;
	c.y = true;
	if (colider(all->pl->p.x + v.x, all->pl->p.y + v.y, &c, all->cub->map))
	{
		all->pl->p.x += v.x;
		all->pl->p.y += v.y;
	}
	else
	{
		if ((c.x && !c.y)
			|| colider(all->pl->p.x + v.x, all->pl->p.y, NULL, all->cub->map))
			all->pl->p.x += v.x;
		if ((c.y && !c.x)
			|| colider(all->pl->p.x, all->pl->p.y + v.y, NULL, all->cub->map))
			all->pl->p.y += v.y;
	}
}

int	get_wall_dir(int side, t_vector ray_dir)
{
	if (side == 0)
	{
		if (ray_dir.x < 0)
			side = WE;
		else
			side = EA;
	}
	else
	{	
		if (ray_dir.y < 0)
			side = SO;
		else
			side = NO;
	}
	return (side);
}
