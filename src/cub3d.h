/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:20:39 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/30 14:42:22 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//------------------------------INCLUDES------------------------------//
# include "../minilibx_linux/mlx.h"
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
# define Y_SEN 10
# define X_VEL 0.75
# define X_ROT 0.04
# define M_PI		3.14159265358979323846	/* pi */
# define M_PI_2		1.57079632679489661923	/* pi/2 */
# define M_PI_4		0.78539816339744830962	/* pi/4 */
# define M_1_PI		0.31830988618379067154	/* 1/pi */
# define M_2_PI		0.63661977236758134308	/* 2/pi */

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
	KEY_TAB = 65289,
	KEY_UP_ARR = 65362,
	KEY_DOWN_ARR = 65364,
	KEY_SHIFT = 65505,
	KEY_M = 109,
	KEY_E = 101
};

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
	_W,
	_A,
	_S,
	_D,
	_LA,
	_RA,
	_UA,
	_DA,
	_TAB,
	_SHIFT,
};

enum
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	D_O = 4,
	D_AO = 5,
	D_AC = 6,
	D_C = 7
};

enum
{
	MM_F = 0x00a0a0a0,
	MM_P = 0x00ffff33,
	MM_W = 0x000000ff,
	MM_DO = 0x0000ff00,
	MM_DC = 0x00ff0000,
	MM_V = 0x00202020,
	MM_FOV = 0xaaff99cc
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
	unsigned int	f_trgb;
	char			*c;
	unsigned int	c_trgb;
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

typedef struct s_all {
	ssize_t		h;
	int			line_height;
	int			door_state;
	bool		m_in_window;
	bool		w_minimised;
	bool		hit_door;
	bool		kmap[14];
	double		time_elapsed;
	double		time_door_init;
	double		time_door_now;
	t_data		tex[8];
	t_vector	mouse;
	t_play		*pl;
	t_mlx		mlx;
	t_cub		*cub;
	t_rloop		tudao;
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