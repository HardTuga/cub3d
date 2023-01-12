/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:22 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/12 09:22:05 by lucas-ma         ###   ########.fr       */
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

bool	player_colision(t_all *all)
{
	
}

int	key_release(int key, t_all, *all)
{
	if (key == KEY_W)
		all->kmap[_W] = false;
	else if (key == KEY_S)
		all->kmap[_S] = false;
	else if (key == KEY_D)
		all->kmap[_D] = false;
	else if (key == KEY_A)
		all->kmap[_A] = false;
	else if (key == KEY_RGT_ARR)
		all->kmap[_RA] = false;
	else if (key == KEY_LFT_ARR)
		all->kmap[_LA] = false;
	else if (key == KEY_UP_ARR)
		all->kmap[_UA] = false;
	else if (key == KEY_DOWN_ARR)
		all->kmap[_DA] = false;
	return (0);
}

int	key_pressed(int key, t_all *all)
{
	if (key == KEY_W)
		all->kmap[_W] = true;
	else if (key == KEY_S)
		all->kmap[_S] = true;
	else if (key == KEY_D)
		all->kmap[_D] = true;
	else if (key == KEY_A)
		all->kmap[_A] = true;
	else if (key == KEY_RGT_ARR)
		all->kmap[_RA] = true;
	else if (key == KEY_LFT_ARR)
		all->kmap[_LA] = true;
	else if (key == KEY_UP_ARR)
		all->kmap[_UA] = true;
	else if (key == KEY_DOWN_ARR)
		all->kmap[_DA] = true;
	return (0);
}

void	handle_keys(t_all *all)
{
	
}

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
	handle_keys(all);
	ray_loop(&all->mlx, all->pl, all->cub);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img.img, 0, 0);
	return (0);
}
