/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:00:22 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/27 14:02:10 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	check_d(char **map, t_rloop *tudao, t_all *all)
{
	if (!all->hit_door)
	{
		if (map[tudao->map.y][tudao->map.x] == '2')
		{
			all->door_state = D_C;
			all->hit_door = true;
		}
		else if (map[tudao->map.y][tudao->map.x] == '3')
		{
			all->door_state = D_O;
			all->hit_door = true;
		}
	}
}

void	door_handler(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (all->pl->dir.x < -0.5)
		x = -1;
	else if(all->pl->dir.x > 0.5)
		x = 1;
	if (all->pl->dir.y < -0.5)
		y = -1;
	else if(all->pl->dir.y > 0.5)
		y = 1;
	open_close_door(all, x ,y);
}

void	open_close_door(t_all *all, int x, int y)
{
	if (all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] == '2')
	{
		all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] = '3';
	}
	else if (all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] == '3')
	{
		all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] = '2';
	}
}
