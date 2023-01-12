/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:52:43 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/12 12:39:43 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

typedef struct s_draw
{
	int		x;
	uint	color;
	t_mlx	*mlx;
}				t_draw;

typedef struct s_rloop
{
	int			hit;
	int			side;
	int			stepx;
	int			stepy;
	int			draw_start;
	int			draw_end;
	int			line_height;
	double		camx;
	double		perpwdist;
	t_vector2	map;
	t_vector	rdir;
	t_vector	sdist;
	t_vector	ddist;
}				t_rloop;

//-----------------------------RAY_MAIN.C------------------------------------//
void	choose_color(t_rloop tudao, t_mlx *mlx, t_cub *cub, t_draw *draw);

//-----------------------------RAY_LOOP.C------------------------------------//
void	ray_loop(t_mlx *mlx, t_play *pl, t_cub *cub);

//-----------------------------RAY_MOVES.C-----------------------------------//
int		key_release(int key, t_all *all);
int		key_pressed(int key, t_all *all);
int		handle_hooks(t_all *all);
void	handle_keys(t_all *all);

#endif