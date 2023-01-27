/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:00:22 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/27 14:06:36 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

bool	check_d(char **map, t_rloop *tudao)
{
	if (map[tudao->map.y][tudao->map.x] == '2')
	{
		if(tudao->door_state == D_AC)
			tudao->door_state = D_AO;
		else if(tudao->door_state == D_AO)
		// {
			// tudao->door_state = D_O;
			map[tudao->map.y][tudao->map.x] = '3';
		// }
		else
			tudao->door_state = D_C;
		return (true);
	}
	else if (map[tudao->map.y][tudao->map.x] == '3')
	{
		if(tudao->door_state == D_AO)
			tudao->door_state = D_AC;
		else if(tudao->door_state == D_AC)
		// {
			// tudao->door_state = D_C;
			map[tudao->map.y][tudao->map.x] = '2';
		// }
		else
			tudao->door_state = D_O;
		return (true);
	}
	return (false);
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
		all->tudao.door_state = D_AC;
	else if (all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] == '3')
		all->tudao.door_state = D_AO;
}
