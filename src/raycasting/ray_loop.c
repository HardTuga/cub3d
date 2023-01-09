/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:54:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/09 15:45:12 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	calc_sidedist(t_rloop *tudao, t_ray *r)
{
	if(tudao->rdir.x < 0)
	{
		tudao->stepx = -1;
		tudao->sdist.x = (r->p.x - tudao->mapx) * tudao->ddist.x;
	}
	else
	{
		tudao->stepx = 1;
		tudao->sdist.x = (tudao->mapx + 1.0 - r->p.x) * tudao->ddist.x;
	}
	if(tudao->rdir.y < 0)
	{
		tudao->stepy = -1;
		tudao->sdist.y = (r->p.y - tudao->mapy) * tudao->ddist.y;
	}
	else
	{
		tudao->stepy = 1;
		tudao->sdist.y = (tudao->mapy + 1.0 - r->p.y) * tudao->ddist.y;
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

static void	init_tudao(t_rloop *tudao, t_ray *ray, char **map)
{
	tudao->rdir.x = ray->dir.x + ray->plane.x * tudao->camx;
	tudao->rdir.y = ray->dir.y + ray->plane.y * tudao->camx;
	tudao->mapx = (int)ray->p.x;
	tudao->mapy = (int)ray->p.y;
	calc_deltadist(&(tudao->ddist), tudao->rdir);
	calc_sidedist(tudao, ray);
	tudao->hit = 0;
	while (tudao->hit == 0)
	{
		if (tudao->sdist.x < tudao->sdist.y)
		{
			tudao->sdist.x += tudao->ddist.x;
			tudao->mapx += tudao->stepx;
			tudao->side = 0;
		}
		else
		{
			tudao->sdist.y += tudao->ddist.y;
			tudao->mapy += tudao->stepy;
			tudao->side = 1;
		}
		if (map[tudao->mapx][tudao->mapy] != '0')
			tudao->hit = 1;
	}
	if (tudao->side == 0)
		tudao->perpwdist = (tudao->sdist.x - tudao->ddist.x);
	else
		tudao->perpwdist = (tudao->sdist.y - tudao->ddist.y);
}

void	ray_loop(t_mlx *mlx, t_ray *r, t_cub *cub)
{
	int		x;
	int		color;
	t_rloop	tudao;

	x = 0;
	mlx->img.img = mlx_new_image(mlx->mlx, SCREENW, SCREENH);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
								&mlx->img.line_length, &mlx->img.endian);
	while (x <= SCREENW)
	{
		tudao.camx = 2 * x / (double)SCREENW - 1;
		init_tudao(&tudao, r, cub->map);
		tudao.line_height = (int)(SCREENH / tudao.perpwdist);
		tudao.draw_start = -tudao.line_height / 2 + SCREENH / 2;
		if (tudao.draw_start < 0)
			tudao.draw_start = 0;
		tudao.draw_end = tudao.line_height / 2 + SCREENH / 2;
		if (tudao.draw_end >= SCREENH)
			tudao.draw_end = SCREENH - 1;
		if (cub->map[tudao.mapx][tudao.mapy] == '1')
			color = 0xFFFF0000;
		else if (cub->map[tudao.mapx][tudao.mapy] == '6')
			color = 0xFF00FF00;
		else if (cub->map[tudao.mapx][tudao.mapy] == '3')
			color = 0xFF0000FF;
		else if (cub->map[tudao.mapx][tudao.mapy] == '4')
			color = 0xFFFFFFFF;
		else if (cub->map[tudao.mapx][tudao.mapy] == '5')
			color = 0xFFFFFF00;
		if (tudao.side == 1)
			color = (int)((color & 0x0000FF) * 0.70)
				| (int)(((color >> 8) & 0x0000FF) * 0.70) << 8
				| (int)((color >> 16) * 0.70) << 16;
		while (tudao.draw_start <= tudao.draw_end)
		{
			my_mlx_pixel_put(&mlx->img, x, tudao.draw_start, color);
			tudao.draw_start++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}