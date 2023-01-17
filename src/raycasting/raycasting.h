/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:52:43 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/17 19:16:01 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

//------------------------------INCLUDES------------------------------//

# include "../cub3d.h"

//------------------------------STRUCTS------------------------------//
typedef struct s_draw
{
	int		x;
	int		tex_num;
	int		tex_y;
	int		tex_x;
	int		draw_start;
	int		draw_end;
	double	tex_pos;
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
	double		wallx;
	double		camx;
	double		perpwdist;
	uint		buffer[SCREENH][SCREENW];
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
int		key_released(int key, t_all *all);
int		key_pressed(int key, t_all *all);
int		handle_hooks(t_all *all);

//---------------------------RAY_MOVES_UTILS.C-------------------------------//
int		exit_handler(t_all *all);
void	hooks(t_all *all);

//-------------------------------COLISION.C----------------------------------//
void	colision(t_all *all, t_vector v);
int		get_wall_dir(int side, t_vector ray_dir);

//--------------------------------IMAGES.C-----------------------------------//
void	init_images(t_all *var);

#endif