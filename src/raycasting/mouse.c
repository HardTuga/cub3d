/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:04:05 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/31 12:53:47 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_mouse(t_all *all)
{
	all->m_in_window = true;
	all->w_minimised = false;
	mlx_mouse_hide(all->mlx.mlx, all->mlx.win);
	mlx_mouse_move(all->mlx.mlx, all->mlx.win, SCREENW / 2, SCREENH / 2);
}

int	mouse_pressed(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		if (all->m_in_window == false)
		{
			all->m_in_window = true;
			mlx_mouse_hide(all->mlx.mlx, all->mlx.win);
			mlx_mouse_move(all->mlx.mlx, all->mlx.win, \
			SCREENW / 2, SCREENH / 2);
		}
		else
			all->anim = true;
	}
	return (0);
}

double	handle_mouse(t_all *all)
{
	t_vector2	m_pos;
	t_vector	mouse;

	if (!all->m_in_window || all->w_minimised)
		return (0);
	mlx_mouse_get_pos(all->mlx.mlx, all->mlx.win, &m_pos.x, &m_pos.y);
	mlx_mouse_move(all->mlx.mlx, all->mlx.win, SCREENW / 2, SCREENH / 2);
	mouse.x = 0.0;
	mouse.y = 0.0;
	if ((m_pos.x != SCREENW / 2 || m_pos.y != SCREENH / 2) && \
	m_pos.x >= 0 && m_pos.x < SCREENW && m_pos.y >= 0 && m_pos.y < SCREENH)
	{
		if (m_pos.x < SCREENW / 2 - 1)
			mouse.x = -((double)(SCREENW / 2 - m_pos.x) / 1024) * X_SEN;
		else if (m_pos.x > SCREENW / 2 + 1)
			mouse.x = ((double)-(SCREENW / 2 - m_pos.x) / 1024) * X_SEN;
		if (m_pos.y > SCREENH / 2 - 1)
			mouse.y = -((double)-(SCREENH / 2 - m_pos.y)) * X_SEN;
		else if (m_pos.y < SCREENH / 2 + 1)
			mouse.y = ((double)(SCREENH / 2 - m_pos.y)) * X_SEN;
		if (mouse.y)
			all->h += mouse.y;
	}
	return (mouse.x);
}
