/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:22 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/11 16:58:39 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

// static void	rotation(t_all *all, double angle)
// {
// 	double	old_dirx;
	
// 	if (angle == 0)
// 		return ;
// 	old_dirx = all->pl->dir.x;
	
// }

int	player_colision(t_play *player, )

int	key_pressed(int key, t_all *all)
[
	if (key == KEY_W)
	{

	}
]

int	handle_hooks(t_all *all)
{
	static double	oldtime;
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	if (!oldtime)
	{
		all->time_elapsed = 1.0;
		oldtime = (cur_time.tv_sec + (cur_time.tv_usec / 1000000.0)) - 1.0;
	}
	else
		all->time_elapsed = (cur_time.tv_sec + (cur_time.tv_usec / 1000000.0))
			- oldtime;
	oldtime += all->time_elapsed;
	all->time_elapsed *= 64;
	// handle_keys()
	ray_loop(&all->mlx, all->pl, all->cub);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img.img, 0, 0);
	return (0);
}
