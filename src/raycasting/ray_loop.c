/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:54:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/05 15:57:45 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	calc_sidedist(t_rloop *tudao, t_ray *r)
{
	if(r->dir.x < 0)
	{
		tudao->stepx = -1;
		tudao->sdist.x = (r->p.x - tudao->mapx) * tudao->ddist.x;
	}
	else
	{
		tudao->stepx = 1;
		tudao->sdist.x = (tudao->mapx + 1.0 - r->p.x) * tudao->ddist.x;
	}
	if(r->dir.y < 0)
	{
		tudao->stepy = -1;
		tudao->sdist.y = (r->p.y - tudao->mapy) * tudao->ddist.x;
	}
	else
	{
		tudao->stepy = 1;
		tudao->sdist.y = (tudao->mapy + 1.0 - r->p.y) * tudao->ddist.y;
	}
}

static void	calc_deltadist(t_vector deltadist, t_vector raydir)
{
	if (raydir.x == 0)
		deltadist.x = 1e30;
	else
		deltadist.x = fabs(1 / raydir.x);
	if (raydir.y == 0)
		deltadist.y = 1e30;
	else
		deltadist.x = fabs(1 / raydir.y);
}

static void	init_tudao(t_rloop *tudao, t_ray *ray, char **map)
{
	tudao->rdir.x = ray->dir.x + ray->plane.x * tudao->camx;
	tudao->rdir.y = ray->dir.y + ray->plane.y * tudao->camx;
	tudao->mapx = (int)ray->p.x;
	tudao->mapy = (int)ray->p.y;
	calc_deltadist(tudao->ddist, tudao->rdir);
	tudao->hit = 0;
	calc_sidedist(tudao, ray);
	while (!tudao->hit)
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
		if (map[tudao->mapx][tudao->mapy] > 0)
			tudao->hit = 1;
	}
	if (tudao->side == 0)
		tudao->perpwdist = tudao->sdist.x - tudao->ddist.x;
	else
		tudao->perpwdist = tudao->sdist.y - tudao->ddist.y;
}

void	ray_loop(t_mlx *mlx, t_ray *r, t_cub *cub)
{
	int		x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	t_rloop	tudao;


	x = 0;
	mlx->img->img = mlx_new_image(mlx->mlx, mlx->screenx, mlx->screeny);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &(mlx->img->bits_per_pixel),
				&(mlx->img->line_length), &(mlx->img->endian));
	while (x < mlx->screenx)
	{
		tudao.camx = 2 * x / (double)mlx->screenx - 1;
		init_tudao(&tudao, r, cub->map);
		line_height = (int)(mlx->screeny / tudao.perpwdist);
		draw_start = -line_height / 2 + mlx->screeny / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + mlx->screeny / 2;
		if (draw_end >= mlx->screeny - 1)
			draw_end = mlx->screeny - 1;
		if (cub->map[tudao.mapx][tudao.mapy] == 1)
			color = 0xffff0000;
		else if (cub->map[tudao.mapx][tudao.mapy] == 2)
			color = 0xff00ff00;
		else if (cub->map[tudao.mapx][tudao.mapy] == 3)
			color = 0xff0000ff;
		else if (cub->map[tudao.mapx][tudao.mapy] == 4)
			color = 0xFFFFFFFF;
		if (tudao.side == 1)
			color = (int)((color & 0x0000FF) * 0.70)
				| (int)(((color >> 8) & 0x0000FF) * 0.70) << 8
				| (int)((color >> 16) * 0.70) << 16;
		my_mlx_pixel_put(mlx->img, draw_start, draw_end, color);
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}