/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:20:39 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/11 16:55:03 by lucas-ma         ###   ########.fr       */
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
# include <stdbool.h>
# include <sys/time.h>

//------------------------------DEFINES------------------------------//

# define SCREENW 1920
# define SCREENH 1080
# define X_SEN 0.9
# define X_VEL 0.75
# define X_ROT 0.02

//-------------------------------ENUMS-------------------------------//

/* LINUX KEYS */
enum
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_LFT_ARR = 65361,
	KEY_RGT_ARR = 65363,
	KEY_UP_ARR = 65362,
	KEY_DOWN_ARR = 65364,
	KEY_M = 109
};

enum
{
	_W = 0,
	_A = 1,
	_S = 2,
	_D = 3,
	_LA = 4,
	_RA = 5,
	_UA = 6,
	_DA	= 7
};


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

typedef struct s_data {
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

typedef struct s_vector2
{
	int	x;
	int	y;
}				t_vector2;

typedef struct s_play
{
	t_vector	p;
	t_vector	dir;
	t_vector	plane;
}				t_play;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	img;
}				t_mlx;

typedef struct s_all {
	double		time_elapsed;
	t_play		*pl;
	t_mlx		mlx;
	t_cub		*cub;
}				t_all;

//------------------------------CUB3D_MAIN------------------------------//
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
void	ray_main(t_cub *map);

#endif