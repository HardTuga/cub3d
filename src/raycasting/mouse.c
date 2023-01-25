/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:04:05 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/25 15:23:10 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_mouse(t_all *all)
{
	all->m_in_window = true;
	all->w_minimised = false;
	mlx_mouse_hide(all->mlx.mlx, all->mlx.win);
#ifndef __APPLE__
		mlx_mouse_move(all->mlx.mlx, all->mlx.win, SCREENW / 2, SCREENH / 2);
#else
		mlx_mouse_move(all->mlx.win, SCREENW / 2, SCREENH / 2);
#endif
}

int	mouse_pressed(int button, int x, int y, t_all *all)
{
	(void)button;
	(void)x;
	(void)y;
	if (all->m_in_window == false)
	{
		all->m_in_window = true;
		mlx_mouse_hide(all->mlx.mlx, all->mlx.win);
#ifndef __APPLE__
		mlx_mouse_move(all->mlx.mlx, all->mlx.win, SCREENW / 2, SCREENH / 2);
#else
		mlx_mouse_move(all->mlx.win, SCREENW / 2, SCREENH / 2);
#endif
	}
	return (0);
}

// double	handle_mouse(t_all *all)
// {
// }