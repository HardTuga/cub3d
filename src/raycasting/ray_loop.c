/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:54:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/30 14:53:05 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	calc_sidedist(t_rloop *tudao, t_play *player)
{
	tudao->hit = false;
	tudao->map.x = (int)player->p.x;
	tudao->map.y = (int)player->p.y;
	if (tudao->rdir.x < 0)
	{
		tudao->stepx = -1;
		tudao->sdist.x = (player->p.x - tudao->map.x) * tudao->ddist.x;
	}
	else
	{
		tudao->stepx = 1;
		tudao->sdist.x = (tudao->map.x + 1.0 - player->p.x) * tudao->ddist.x;
	}
	if (tudao->rdir.y < 0)
	{
		tudao->stepy = -1;
		tudao->sdist.y = (player->p.y - tudao->map.y) * tudao->ddist.y;
	}
	else
	{
		tudao->stepy = 1;
		tudao->sdist.y = (tudao->map.y + 1.0 - player->p.y) * tudao->ddist.y;
	}
}

void	calc_deltadist(t_vector *deltadist, t_vector raydir)
{
	if (raydir.x == 0)
		deltadist->x = 1e30;
	else
		deltadist->x = fabs(1 / raydir.x);
	if (raydir.y == 0)
		deltadist->y = 1e30;
	else
		deltadist->y = fabs(1 / raydir.y);
}

static void	init_tudao(t_rloop *tudao, t_play *player, char **map, t_all *all)
{
	tudao->rdir.x = player->dir.x + player->plane.x * tudao->camx;
	tudao->rdir.y = player->dir.y + player->plane.y * tudao->camx;
	calc_deltadist(&(tudao->ddist), tudao->rdir);
	calc_sidedist(tudao, player);
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
		check_d(map, tudao, all);
		if (map[tudao->map.y][tudao->map.x] == '1')
			tudao->hit = true;
	}
	tudao->side = get_wall_dir(tudao->side, tudao->rdir);
}

static void	calc_tex_x(t_rloop *tudao, t_play *pl, t_draw *draw, t_data *tex)
{
	double	wallx;

	if (tudao->side == EA || tudao->side == WE)
	{
		tudao->perpwdist = tudao->sdist.x - tudao->ddist.x;
		wallx = pl->p.y + tudao->perpwdist * tudao->rdir.y;
	}
	else
	{
		tudao->perpwdist = tudao->sdist.y - tudao->ddist.y;
		wallx = pl->p.x + tudao->perpwdist * tudao->rdir.x;
	}
	wallx -= floor(wallx);
	draw->tex_x = (int)(wallx * tex[tudao->side].img_width);
	if ((tudao->side == EA || tudao->side == WE) && tudao->rdir.x < 0)
		draw->tex_x = tex[tudao->side].img_width - draw->tex_x - 1;
	else if ((tudao->side == NO || tudao->side == SO) && tudao->rdir.y > 0)
		draw->tex_x = tex[tudao->side].img_width - draw->tex_x - 1;
}

void	ray_loop(t_play *pl, t_cub *cub, t_all *all)
{
	t_draw	draw;
	t_rloop	door;

	draw.x = -1;
	all->mlx.img.img = mlx_new_image(all->mlx.mlx, SCREENW, SCREENH);
	all->mlx.img.addr = mlx_get_data_addr(all->mlx.img.img, &all->mlx.img.bpp,
			&all->mlx.img.line_length, &all->mlx.img.endian);
	all->hit_door = false;
	while (++(draw.x) < SCREENW)
	{
		all->tudao.camx = 2 * draw.x / (double)SCREENW - 1;
		all->tudao.hit = false;
		init_tudao(&all->tudao, pl, cub->map, all);
		calc_tex_x(&all->tudao, pl, &draw, all->tex);
		all->line_height = (int)(SCREENH / all->tudao.perpwdist);
		draw_all(&all->tudao, &draw, all);
		if (all->hit_door)
		{
			raycast_door(all, draw.x, &door);
			calc_tex_door(&door, all, &draw, all->tex);
			draw_door_util(door, draw, all);
		}
	}
	minimap(all, 1, 1);
}
