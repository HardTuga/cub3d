/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:00:22 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/26 18:20:54 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	calc_tex_door(t_rloop *tudao, t_play *pl, t_draw *draw, t_data *tex)
{
	double	wallx;

	if (tudao->side == EA || tudao->side == WE)
		wallx = pl->p.y + tudao->door_dist * tudao->rdir.y;
	else
		wallx = pl->p.x + tudao->door_dist * tudao->rdir.x;
	wallx -= floor(wallx);
	draw->tex_x = (int)(wallx * tex[tudao->door_state].img_width);
	if ((tudao->side == EA || tudao->side == WE) && tudao->rdir.x < 0)
		draw->tex_x = tex[tudao->door_state].img_width - draw->tex_x - 1;
	else if ((tudao->side == NO || tudao->side == SO) && tudao->rdir.y > 0)
		draw->tex_x = tex[tudao->door_state].img_width - draw->tex_x - 1;
}


void	check_d(char **map, t_rloop *tudao)
{
	if (!tudao->hit_door)
	{
		if (map[tudao->map.y][tudao->map.x] == '2')
		{
			tudao->door_state = D_C;
			if (tudao->side == 0)
				tudao->door_dist = tudao->sdist.x - tudao->ddist.x;
			else
				tudao->door_dist = tudao->sdist.y - tudao->ddist.y;
			tudao->hit_door = true;
		}
		else if (map[tudao->map.y][tudao->map.x] == '3')
		{
			tudao->door_state = D_O;
			if (tudao->side == 0)
				tudao->door_dist = tudao->sdist.x - tudao->ddist.x;
			else
				tudao->door_dist = tudao->sdist.y - tudao->ddist.y;
			tudao->hit_door = true;
		}
	}
	else if (!(map[tudao->map.y][tudao->map.x] == '2') && !(map[tudao->map.y][tudao->map.x] == '3'))
		tudao->end_door = tudao->map.x;
}

void	door_handler(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (all->pl->dir.x < -0.5)
		x = -1;
	else if(all->pl->dir.x > 0.5)
		x = 1;
	if (all->pl->dir.y < -0.5)
		y = -1;
	else if(all->pl->dir.y > 0.5)
		y = 1;
	open_close_door(all, x ,y);
}

void	open_close_door(t_all *all, int x, int y)
{
	if (all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] == '2')
	{
		all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] = '3';
	}
	else if (all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] == '3')
	{
		all->cub->map[(int)all->pl->p.y + y][(int)all->pl->p.x + x] = '2';
	}
}
