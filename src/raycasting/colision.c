/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:22:50 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/25 11:09:06 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static bool	colider(double posx, double posy, t_vector2 *c, char **map)
{
	bool		no_cool;
	double		old_dir;
	double		angle;
	t_vector	vector;

	no_cool = true;
	angle = 0.05;
	vector.x = 0.2;
	vector.y = 0;
	while (angle < 6.25)
	{
		old_dir = vector.x;
		vector.x = vector.x * cos(angle) - vector.y * sin(angle);
		vector.y = old_dir * sin(angle) + vector.y * cos(angle);
		if (c && map[(int)(posy)][(int)(posx + vector.x)] != '0')
			c->x = false;
		if (c && map[(int)(posy + vector.y)][(int)(posx)] != '0')
			c->y = false;
		if (map[(int)(posy + vector.y)][(int)(posx + vector.x)] != '0')
			no_cool = false;
		if (!no_cool && (!c || !c->x) && (!c || !c->y))
			return (false);
		angle += 0.05;
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
