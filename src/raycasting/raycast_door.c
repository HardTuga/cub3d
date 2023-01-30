/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:56:02 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/30 17:34:09 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	calc_tex_door(t_rloop *tudao, t_all *all, t_draw *draw, t_data *tex)
{
	double	wallx;

	if (tudao->side == EA || tudao->side == WE)
	{
		tudao->perpwdist = tudao->sdist.x - tudao->ddist.x;
		wallx = all->pl->p.y + tudao->perpwdist * tudao->rdir.y;
	}
	else
	{
		tudao->perpwdist = tudao->sdist.y - tudao->ddist.y;
		wallx = all->pl->p.x + tudao->perpwdist * tudao->rdir.x;
	}
	wallx -= floor(wallx);
	draw->tex_x = (int)(wallx * tex[all->door_state].img_width);
	if ((tudao->side == EA || tudao->side == WE) && tudao->rdir.x < 0)
		draw->tex_x = tex[all->door_state].img_width - draw->tex_x - 1;
	else if ((tudao->side == NO || tudao->side == SO) && tudao->rdir.y > 0)
		draw->tex_x = tex[all->door_state].img_width - draw->tex_x - 1;
}

void	draw_door_util(t_rloop door, t_draw draw, t_all *all)
{
	all->line_height = (int)(SCREENH / door.perpwdist);
	door.draw_start = (-all->line_height + all->h) / 2 + SCREENH / 2;
	if (door.draw_start < 0)
		door.draw_start = 0;
	door.draw_end = (all->line_height + all->h) / 2 + SCREENH / 2;
	if (door.draw_end > SCREENH)
		door.draw_end = SCREENH;
	while (door.draw_start < door.draw_end)
		draw_door(&door, &draw, all, door.draw_start++);
}

void	raycast_door(t_all *all, int x, t_rloop *tudao)
{
	tudao->camx = 2 * x / (double)SCREENW - 1;
	tudao->rdir.x = all->pl->dir.x + all->pl->plane.x * tudao->camx;
	tudao->rdir.y = all->pl->dir.y + all->pl->plane.y * tudao->camx;
	calc_deltadist(&(tudao->ddist), tudao->rdir);
	calc_sidedist(tudao, all->pl);
	while (!(tudao->hit))
	{
		if (tudao->sdist.x < tudao->sdist.y)
		{
			tudao->map.x += tudao->stepx;
			tudao->sdist.x += tudao->ddist.x;
			tudao->side = 0;
		}
		else
		{
			tudao->map.y += tudao->stepy;
			tudao->sdist.y += tudao->ddist.y;
			tudao->side = 1;
		}
		if (all->cub->map[tudao->map.y][tudao->map.x] >= '2')
			tudao->hit = true;
		if (all->cub->map[tudao->map.y][tudao->map.x] == '1')
			return ;
	}
	tudao->side = get_wall_dir(tudao->side, tudao->rdir);
}
