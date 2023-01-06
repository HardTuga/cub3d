/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:20:39 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/06 10:25:04 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//------------------------------INCLUDES------------------------------//
# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

//------------------------------DEFINES------------------------------//

# define SCREENW 1920
# define SCREENH 1080

//------------------------------STRUCTS------------------------------//
typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}				t_player;

typedef struct s_cub
{
	t_player	player;
	char		*n;
	char		*s;
	char		*w;
	char		*e;
	char		*f;
	char		*c;
	char		**map;
	int			map_y;
}				t_cub;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_ray
{
	t_vector	p;
	t_vector	dir;
	t_vector	plane;
}				t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	img;
}				t_mlx;


//------------------------------CUB3D_MAIN------------------------------//
void	print_cub(t_cub *cub);
void	print_map(char **map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//------------------------------ERRORS------------------------------//
int		error_msg(char *str);

//------------------------------FREE_UTILS------------------------------//
void	free_str(char *str);
void	free_matrix(char **matrix);
void	free_cub(t_cub *cub);

//------------------------------UTILS------------------------------//
int		matrix_size(char **matrix);
char	*ft_strdup_map(const char *src);

//------------------------------CHECK_ARGS------------------------------//
int		check_args(int ac, char **av);
int		rev_strstr(char *str, char *find);

//------------------------------PARSE_FILE------------------------------//
int		parse_file(t_cub *cub, char **av);
int		file_line(char *av);
int		fill_elements(t_cub *cub, char **tmp);
void	fill_params(t_cub *cub, char *str);
int		check_elements(t_cub *cub);

//------------------------------PARSE_FILE_UTILS------------------------------//
int		valid_elements(t_cub *cub);
int		check_rgb(char *element);
int		check_image(char *element);

//------------------------------CHECK_MAP------------------------------//
int		map_checker(t_cub *cub);
int		check_closed(t_cub *cub);
int		closed_line(char **map, int y);
int		closed_border(char **map, int y);
int		check_chars(char **map);

//------------------------------CHECK_MAP_UTILS------------------------------//
int		single_player(char **map, t_cub *cub);
int		check_line_midle(char **map, int y, int x);
int		check_line_limits(char **map, int y, int x);
int		check_element(char c, int o);
int		check_door(char **map, int y, int x);

//--------------------------------RAY_MAIN.C---------------------------------//
void	ray_main(t_cub *map, t_mlx *mlx);

//-----------------------------RAY_LOOP.C------------------------------------//
void	ray_loop(t_mlx *mlx, t_ray *r, t_cub *cub);

#endif