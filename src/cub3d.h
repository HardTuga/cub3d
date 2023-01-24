/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:20:39 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/24 11:13:59 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//------------------------------INCLUDES------------------------------//
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/time.h>

//------------------------------DEFINES------------------------------//

# define SCREENW 1080
# define SCREENH 720
# define X_SEN 0.9
# define X_VEL 0.75
# define X_ROT 0.04

//-------------------------------ENUMS-------------------------------//
#ifdef __APPLE__
# include "../mlx/mlx.h"
typedef unsigned int uint;
/* MAC KEYS */
enum
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LFT_ARR = 123,
	KEY_RGT_ARR = 124,
	KEY_TAB = 48,
	KEY_UP_ARR = 126,
	KEY_DOWN_ARR = 125,
	KEY_M = 46,
	KEY_E = 14
};
#else
# include "../minilibx_linux/mlx.h"
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
	KEY_TAB = 65289,
	KEY_UP_ARR = 65362,
	KEY_DOWN_ARR = 65364,
	KEY_M = 109,
	KEY_E = 101
};

#endif

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_ENTER = 9,
	ON_LEAVE = 10,
	ON_DESTROY = 17
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
	_DA = 7,
	_TAB = 8
};

enum
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	D_O = 4,
	D_C = 5
};

enum
{
	MM_F = 0xffa0a0a0,
	MM_P = 0xffff66b2,
	MM_W = 0xff0000ff,
	MM_DO = 0xff00ff00,
	MM_DC = 0xffff0000,
	MM_V = 0xff202020
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
	t_player		player;
	char			*n;
	char			*s;
	char			*w;
	char			*e;
	char			*f;
	uint			f_trgb;
	char			*c;
	uint			c_trgb;
	char			**map;
	int				map_y;
	int				map_x;
}					t_cub;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
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
	bool		m_in_window;
	bool		w_minimised;
	double		time_elapsed;
	bool		kmap[13];
	t_data		tex[6];
	t_vector	mouse;
	t_play		*pl;
	t_mlx		mlx;
	t_cub		*cub;
}				t_all;

//------------------------------CUB3D_MAIN------------------------------//
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

//------------------------------ERRORS------------------------------//
int				error_msg(char *str);

//------------------------------FREE_UTILS------------------------------//
void			free_str(char *str);
void			free_matrix(char **matrix);
void			free_cub(t_cub *cub);
void			free_imgs(t_all *all);

//------------------------------UTILS------------------------------//
int				matrix_size(char **matrix);
char			*ft_strdup_map(const char *src);

//------------------------------PARSING------------------------------//
int				check_args(int ac, char **av);
int				parse_file(t_cub *cub, char **av);
int				map_checker(t_cub *cub);

//--------------------------------TIME.C---------------------------------//
unsigned long	get_timer(void);
int				get_fps(void);

//--------------------------------RAY_MAIN.C---------------------------------//
void			ray_main(t_cub *map);

#endif