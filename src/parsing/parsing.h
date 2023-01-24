/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:46:50 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/23 17:49:17 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//------------------------------INCLUDES------------------------------//
# include "../cub3d.h"

//------------------------------CHECK_ARGS------------------------------//
int				check_args(int ac, char **av);
int				rev_strstr(char *str, char *find);

//------------------------------PARSE_FILE------------------------------//
int				parse_file(t_cub *cub, char **av);
int				file_line(char *av);
int				fill_elements(t_cub *cub, char **tmp);
void			fill_params(t_cub *cub, char *str);
int				check_elements(t_cub *cub);

//------------------------------PARSE_FILE_UTILS------------------------------//
int				valid_elements(t_cub *cub);
int				check_rgb(char *element);
int				check_image(char *element);

//------------------------------PARSE_FILE_RGB------------------------------//
void			convert_rgb(t_cub *cub);
unsigned int	create_trgb(int t, int r, int g, int b);

//------------------------------CHECK_MAP------------------------------//
int				map_checker(t_cub *cub);
int				check_closed(t_cub *cub);
int				closed_line(char **map, int y);
int				closed_border(char **map, int y);
int				check_chars(char **map);

//------------------------------CHECK_MAP_UTILS------------------------------//
int				single_player(char **map, t_cub *cub);
int				check_line_midle(char **map, int y, int x);
int				check_line_limits(char **map, int y, int x);
int				check_element(char c, int o);
int				check_door(char **map, int y, int x);

//------------------------------FILL_MAP------------------------------//
void			fill_map(t_cub *cub);
void			redo_map(t_cub *cub, int len);
char			*remake_line(char *line, int len);
int				max_x(char **map);

#endif