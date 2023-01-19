/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:54:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/19 11:43:59 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	calc_sidedist(t_rloop *tudao, t_play *player)
{
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

static void	calc_deltadist(t_vector *deltadist, t_vector raydir)
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

static void	init_tudao(t_rloop *tudao, t_play *player, char **map)
{
	tudao->rdir.x = player->dir.x + player->plane.x * tudao->camx;
	tudao->rdir.y = player->dir.y + player->plane.y * tudao->camx;
	calc_deltadist(&(tudao->ddist), tudao->rdir);
	calc_sidedist(tudao, player);
	tudao->hit = false;
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
		if (map[tudao->map.y][tudao->map.x] != '0')
			tudao->hit = true;
	}
	tudao->side = get_wall_dir(tudao->side, tudao->rdir);
}

// static void	draw_stripe(t_draw d, t_rloop *tudao)
// {
// 	tudao->line_height = (int)(SCREENH / tudao->perpwdist);
// 	tudao->draw_start = -tudao->line_height / 2 + SCREENH / 2;
// 	if (tudao->draw_start < 0)
// 		tudao->draw_start = 0;
// 	tudao->draw_end = tudao->line_height / 2 + SCREENH / 2;
// 	if (tudao->draw_end > SCREENH)
// 		tudao->draw_end = SCREENH;
// 	while (tudao->draw_start < tudao->draw_end)
// 	{
// 		my_mlx_pixel_put(&(d.mlx->img), SCREENW - d.x - 1, \
// 		tudao->draw_start, d.color);
// 		tudao->draw_start++;
// 	}
// }

void	ray_loop(t_mlx *mlx, t_play *pl, t_cub *cub)
{
	t_draw	draw;
	t_rloop	tudao;

	draw.x = 0;
	draw.mlx = mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, SCREENW, SCREENH);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.line_length, &mlx->img.endian);
	while (draw.x < SCREENW)
	{
		tudao.camx = 2 * draw.x / (double)SCREENW - 1;
		init_tudao(&tudao, pl, cub->map);
		if (tudao.side == EA || tudao.side == WE)
		{
			tudao.perpwdist = (tudao.sdist.x - tudao.ddist.x);
			tudao.wallx = pl->p.y + tudao.perpwdist * tudao.rdir.y;
		}
		else
		{
			tudao.perpwdist = (tudao.sdist.y - tudao.ddist.y);
			tudao.wallx = pl->p.x + tudao.perpwdist * tudao.rdir.x;
		}
		tudao.wallx -= floor(tudao.wallx);
		// choose_color(tudao, mlx, cub, &draw);
		// draw_stripe(draw, &tudao);
		(draw.x)++;
	}
}
