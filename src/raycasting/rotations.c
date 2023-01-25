/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:07:31 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/25 14:30:20 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	horizontal_rot(t_play *p, double angle)
{
	double	old_dir;
	double	old_plane;

	if (angle == 0)
		return ;
	old_dir = p->dir.x;
	old_plane = p->plane.x;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = old_dir * sin(angle) + p->dir.y * cos(angle);
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = old_plane * sin(angle) + p->plane.y * cos(angle);
}

void	vertical_rot(t_all *all)
{
	ssize_t h;
	
	h = 0;
	if (all->kmap[_UA] == true)
		h++;
	if (all->kmap[_DA] == true)
		h--;
	if (h >= SCREENH)
		h = SCREENH - 1;
	else if (h < -SCREENH)
		h = -(SCREENH - 1);
	all->h += h / (X_ROT * 2);
}