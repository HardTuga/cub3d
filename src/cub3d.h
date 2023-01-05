/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:20:39 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/05 12:36:04 by pcampos-         ###   ########.fr       */
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

//------------------------------STRUCTS------------------------------//
typedef struct s_player
{
	int		x;
	int		y;
	char	spawn;
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

//------------------------------CUB3D_MAIN------------------------------//
void	print_cub(t_cub *cub);
void	print_map(char **map);

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

#endif