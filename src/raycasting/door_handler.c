/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:00:22 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/27 17:07:43 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

bool	wait_time(t_all *all)
{
	struct timeval	cur_time;
	
	gettimeofday(&cur_time, NULL);
	if (!all->time_door_init)
		all->time_door_init = (cur_time.tv_sec + (cur_time.tv_usec / 1000000.0));
	all->time_door_init = (cur_time.tv_sec + (cur_time.tv_usec / 1000000.0));
	if (all->time_door_now - all->time_door_init < 10)
		return (false);
	all->time_door_init = 0;
	return (true);
}

void	check_d(char **map, t_rloop *tudao, t_all *all)
{
	if (!all->hit_door)
	{
		if (map[tudao->map.y][tudao->map.x] == '7')
		{
			all->door_state = D_C;
			all->hit_door = true;
		}
		else if (map[tudao->map.y][tudao->map.x] == '6')
		{
			if (wait_time(all))
			{
				if(all->door_state == D_C)
					map[tudao->map.y][tudao->map.x] = '5';
				else
					map[tudao->map.y][tudao->map.x] = '7';
			}
			all->door_state = D_AC;
			all->hit_door = true;
		}
		else if (map[tudao->map.y][tudao->map.x] == '5')
		{
			if (wait_time(all))
			{
			if(all->door_state == D_O)
				map[tudao->map.y][tudao->map.x] = '6';
			else
				map[tudao->map.y][tudao->map.x] = '4';
			all->door_state = D_AO;
			all->hit_door = true;
			}
		}
		else if (map[tudao->map.y][tudao->map.x] == '4')
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
	if (all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] == '7')
		all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] = '6';
	else if (all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] == '4')
		all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] = '5';
}
