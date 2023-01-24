/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:00:22 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/24 13:23:28 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

bool	check_d(char **map, t_rloop *tudao)
{
	if (map[tudao->map.y][tudao->map.x] == '2')
	{
		tudao->door_state = D_C;
		return (true);
	}
	else if (map[tudao->map.y][tudao->map.x] == '3')
	{
		tudao->door_state = D_O;
		return (true);
	}
	return (false);
}

// void	door_handler(t_rloop *tudao, t_play *player, char **map)
// {
	
// }
// void	open_close_door(t_all *all)
// {
// 	if (all->cub->map[][] == '2')
// 	{
// 		//do_door_animation();
// 		all->cub->map[][] = '3';
// 	}
// 	else if (all->cub->map[][] == '3')
// 	{
// 		//do_door_animation();
// 		all->cub->map[][] = '2';
// 	}
// }
