/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:52:43 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/26 11:34:50 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

//------------------------------INCLUDES------------------------------//

# include "../cub3d.h"

//------------------------------STRUCTS------------------------------//
typedef struct s_draw
{
	int			x;
	int			tex_y;
	int			tex_x;
	double		step;
	double		texpos;
	uint		color;
}				t_draw;

typedef struct s_rloop
{
	int			side;
	int			door_state;
	int			stepx;
	int			stepy;
	int			draw_start;
	int			draw_end;
	int			line_height;
	bool		hit_door;
	bool		hit;
	double		camx;
	double		perpwdist;
	t_vector2	map;
	t_vector	rdir;
	t_vector	sdist;
	t_vector	ddist;
}				t_rloop;

//-----------------------------RAY_MAIN.C------------------------------------//
void	draw_wall(t_rloop *tudao, t_draw *d, t_all *all, int y);

//-----------------------------RAY_LOOP.C------------------------------------//
void	ray_loop(t_play *pl, t_cub *cub, t_all *all);

//-----------------------------RAY_MOVES.C-----------------------------------//
int		key_released(int key, t_all *all);
int		key_pressed(int key, t_all *all);
int		handle_hooks(t_all *all);

//-----------------------------RAY_HOOKS.C-----------------------------------//
int		exit_handler(t_all *all);
void	hooks(t_all *all);

//-------------------------------COLISION.C----------------------------------//
void	colision(t_all *all, t_vector v);
int		get_wall_dir(int side, t_vector ray_dir);

//--------------------------------IMAGES.C-----------------------------------//
void	init_images(t_all *var);
uint	*get_img_pixel(t_data *data, int x, int y);

//---------------------------------DRAW.C------------------------------------//
void	draw_all(t_rloop *tudao, t_draw *draw, t_all *all);

//--------------------------------MINIMAP-----------------------------------//
void	minimap(t_all *all, int x, int y);
void	print_minimap(t_vector p_cords, t_vector2 start, t_all *all, int x);
void	paint_minimap(t_data *data, t_vector2 start, int color);
void	put_player(t_all *all);
void	do_fov(t_all *all);

//--------------------------------MINIMAP_FOV-----------------------------------//
void	fill_fov(t_all *all, t_vector lvert, t_vector rvert, t_vector player);
int		get_min(int a, int b);
int		get_max(int a, int b);
bool	inside(t_vector p_a, t_vector p_b, t_vector p_c, t_vector target);
double	get_line_b(t_vector p_a, t_vector p_b);

//---------------------------------MOUSE.C-----------------------------------//
void	init_mouse(t_all *all);
int		mouse_pressed(int button, int x, int y, t_all *all);

//------------------------------DOOR_HANDLER.C-------------------------------//
bool	check_d(char **map, t_rloop *tudao);
void	door_handler(t_all *all);
void	open_close_door(t_all *all, int x, int y);

//-------------------------------ROTATIONS.C---------------------------------//
void	horizontal_rot(t_play *p, double angle);

#endif