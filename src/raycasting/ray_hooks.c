/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:21:17 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/24 11:20:02 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	exit_handler(t_all *all)
{
	free_cub(all->cub);
	free_imgs(all);
	if (all->mlx.win != NULL)
		mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	#ifndef __APPLE__
	mlx_destroy_display(all->mlx.mlx);
	#endif
	free(all->mlx.mlx);
	exit(EXIT_SUCCESS);
}

static int	re_expand_window(t_all *all)
{
	if (all->m_in_window == true)
	{
		mlx_mouse_hide(all->mlx.mlx, all->mlx.win);
		mlx_mouse_move(all->mlx.win, SCREENW / 2, SCREENH / 2);
	}
	all->w_minimised = false;
	return (0);
}

static int	minimize_window(t_all *all)
{
	mlx_mouse_show(all->mlx.mlx, all->mlx.win);
	all->w_minimised = true;
	return (0);
}

void	hooks(t_all *all)
{
	mlx_hook(all->mlx.win, ON_KEYDOWN, 1L << 0, key_pressed, all);
	mlx_hook(all->mlx.win, ON_KEYUP, 1L << 1, key_released, all);
	mlx_hook(all->mlx.win, ON_ENTER, 1L << 21, re_expand_window, all);
	mlx_hook(all->mlx.win, ON_LEAVE, 1L << 21, minimize_window, all);
	mlx_mouse_hook(all->mlx.win, mouse_pressed, all);
	mlx_loop_hook(all->mlx.mlx, handle_hooks, all);
	mlx_hook(all->mlx.win, ON_DESTROY, 0, exit_handler, all);
}
