/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:22 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/12 14:22:29 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	rotation(t_all *all, t_play *p, double angle)
{
	double	old_dir;
	double	old_plane;
	
	if (angle == 0)
		return ;
	old_dir = p->dir.x;
	old_plane = p->plane.x;
	p->dir.x = p->dir.x * cos(angle) - all->pl->dir.y * sin(angle);
	p->dir.y = old_dir * sin(angle) + p->dir.y * sin(angle);
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = old_plane * sin(angle) + p->plane.y * cos(angle);
}

int	key_release(int key, t_all *all)
{
	if (key == KEY_ESC)
		exit_handler(all);
	else if (key == KEY_W)
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
	return (0);
}

void	handle_keys(t_all *all)
{
	t_vector	v;

	rotation(all, all->pl, (all->kmap[_RA] * X_ROT - all->kmap[_LA] * X_ROT));
	v.x += all->time_elapsed * ((all->pl->dir.x * all->kmap[_W]) + (all->pl->dir.y * all->kmap[_A])
			- (all->pl->dir.x * all->kmap[_S]) - (all->pl->dir.y * all->kmap[_D]));
	v.y += all->time_elapsed * ((all->pl->dir.y * all->kmap[_W]) + (all->pl->dir.x * all->kmap[_A])
			- (all->pl->dir.y * all->kmap[_S]) - (all->pl->dir.x * all->kmap[_D]));
	v.x = (v.x / 16) * X_VEL;
	v.y = (v.y / 16) * X_VEL;
	if (v.x != 0 || v.y != 0)
	{
		all->pl->p.x += v.x;
		all->pl->p.y += v.y;
	}
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
