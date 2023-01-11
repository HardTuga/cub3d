/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:36:40 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/11 16:19:37 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static t_vector	find_dir(char dir)
{
	t_vector	d;

	ft_memset(&d, 0, sizeof(t_vector));
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
		if (dir == 'W')
			d.x = -1;
		else
			d.x = 1;
	}
	return (d);
}

static t_vector	calc_plane(t_vector dir, int sign)
{
	t_vector	plane;

	plane.x = (0.66 * dir.y) * sign;
	plane.y = (0.66 * dir.x) * sign;
	return (plane);
}

void	choose_color(t_rloop tudao, t_mlx *mlx, t_cub *cub, t_draw *draw)
{
	if (cub->map[tudao.map.y][tudao.map.x] == '1')
		draw->color = mlx_get_color_value(mlx->mlx, 0xFFFF0000);
	else if (cub->map[tudao.map.y][tudao.map.x] == '6')
		draw->color = mlx_get_color_value(mlx->mlx, 0xFF00FF00);
	else if (cub->map[tudao.map.y][tudao.map.x] == '3')
		draw->color = mlx_get_color_value(mlx->mlx, 0xFF0000FF);
	else if (cub->map[tudao.map.y][tudao.map.x] == '4')
		draw->color = mlx_get_color_value(mlx->mlx, 0xFFFFFFFF);
	else if (cub->map[tudao.map.y][tudao.map.x] == '5')
		draw->color = mlx_get_color_value(mlx->mlx, 0xFFFFFF00);
	if (tudao.side == 1)
		draw->color = (int)((draw->color & 0x0000FF) * 0.70)
					| (int)(((draw->color >> 8) & 0x0000FF) * 0.70) << 8
					| (int)((draw->color >> 16) * 0.70) << 16;
}

static void	init_player(t_play *player, t_cub *cub)
{
	player->p.x = cub->player.x + 0.5;
	player->p.y = cub->player.y + 0.5;
	player->dir = find_dir(cub->player.dir);
	if (cub->player.dir == 'N' || cub->player.dir == 'S')
		player->plane = calc_plane(player->dir, 1);
	else
		player->plane = calc_plane(player->dir, -1);
}

void	ray_main(t_cub *cub)
{
	t_play	pl;
	t_all	var;

	ft_memset(&var, 0, sizeof(var));
	var.cub = cub;
	var.mlx.mlx = mlx_init();
	var.mlx.win = mlx_new_window(var.mlx.mlx, SCREENW, SCREENH, "Cub3D");
	init_player(&pl, cub);
	var.pl = &pl;
	// mlx_loop_hook(var->mlx.ptr, handlers, vars);
	handle_hooks(&var);
	mlx_loop(var.mlx.mlx);
}
