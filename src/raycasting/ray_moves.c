/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:22 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/11 16:17:02 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	handle_hooks(t_all *all)
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
}
