/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:36:40 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/09 16:54:18 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_vector	find_dir(char dir)
{
	t_vector	d;
	
	if (dir == 'N' || dir == 'S')
	{
		d.x = 0;
		if (dir == 'N')
			d.y = -1;
		else
			d.y = 1;
	}
	else
	{
		d.y = 0;
		if (dir == 'E')
			d.x = 1;
		else
			d.x = -1;
	}
	return (d);
}

t_vector calc_plane(char dir)
{
	t_vector	plane;

	if (dir == 'N' || dir == 'S')
	{
		plane.y = 0;
		plane.x = 0.66;
	}
	else 
	{
		plane.y = 0.66;
		plane.x = 0;
	}
	return (plane);
}

void	ray_main(t_cub *cub, t_mlx *mlx)
{
	t_ray	ray;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREENW, SCREENH, "Cub3D");
	// ray.p.x = (double)cub->player.x;
	// ray.p.y = (double)cub->player.y;
	// ray.dir = find_dir(cub->player.dir);
	// ray.plane = calc_plane(cub->player.dir);
	ray.p.x = 22;
	ray.p.y = 12;
	ray.dir.x = -1;
	ray.dir.y = 0;
	ray.plane.x = 0;
	ray.plane.y = 0.66;
	ray_loop(mlx, &ray, cub);
	// mlx_do_sync(mlx->mlx);
	mlx_loop(mlx->mlx);
}