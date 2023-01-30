/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:22 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/30 11:12:08 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	key_released(int key, t_all *all)
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
	else if (key == KEY_DOWN_ARR)
		all->kmap[_DA] = false;
	else if (key == KEY_UP_ARR)
		all->kmap[_UA] = false;
	else if (key == KEY_SHIFT)
		all->kmap[_SHIFT] = false;
	return (0);
}

int	key_pressed(int key, t_all *all)
{
	if (key == KEY_ESC)
		exit_handler(all);
	else if (key == KEY_W)
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
	else if (key == KEY_SHIFT)
		all->kmap[_SHIFT] = true;
	else if (key == KEY_TAB)
		all->kmap[_TAB] = true;
	else if (key == KEY_E)
		door_handler(all);
	return (0);
}

static void	move_player(t_all *all)
{
	t_vector	v;

	v.x = all->time_elapsed * ((all->pl->dir.x * all->kmap[_W]) + \
			(all->pl->dir.y * all->kmap[_A])
			- (all->pl->dir.x * all->kmap[_S]) - \
			(all->pl->dir.y * all->kmap[_D]));
	v.y = all->time_elapsed * ((all->pl->dir.y * all->kmap[_W]) + \
			(all->pl->dir.x * all->kmap[_D])
			- (all->pl->dir.y * all->kmap[_S]) - \
			(all->pl->dir.x * all->kmap[_A]));
	if (all->kmap[_SHIFT] == true)
	{
		v.x = ((v.x / 16) * X_VEL) * 2;
		v.y = ((v.y / 16) * X_VEL) * 2;
	}
	else
	{
		v.x = (v.x / 16) * X_VEL;
		v.y = (v.y / 16) * X_VEL;
	}
	if (v.x != 0 || v.y != 0)
		colision(all, v);
}

static void	handle_keys(t_all *all)
{
	if (all->kmap[_TAB] == true)
	{
		if (all->m_in_window == true)
		{
			mlx_mouse_show(all->mlx.mlx, all->mlx.win);
			all->m_in_window = false;
		}
		all->kmap[_TAB] = false;
	}
	move_player(all);
	horizontal_rot(all->pl, handle_mouse(all) + \
	(all->kmap[_RA] * X_ROT - all->kmap[_LA] * X_ROT));
	if (all->kmap[_UA] == true)
		all->h += Y_SEN;
	if (all->kmap[_DA] == true)
		all->h -= Y_SEN;
	if (all->h >= SCREENH)
		all->h = SCREENH;
	else if (all->h < -(SCREENH))
		all->h = -(SCREENH - 1);
}

int	handle_hooks(t_all *all)
{
	static double	oldtime;
	char			*fps;
	struct timeval	cur_time;

	fps = NULL;
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
	ray_loop(all->pl, all->cub, all);
	handle_keys(all);
	mlx_clear_window(all->mlx.mlx, all->mlx.win);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img.img, 0, 0);
	fps = ft_itoa(get_fps());
	mlx_string_put(all->mlx.mlx, all->mlx.win, 20, 20, 0xFFFFFFFF, fps);
	free(fps);
	mlx_destroy_image(all->mlx.mlx, all->mlx.img.img);
	return (0);
}
