/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:27:21 by pcampos-          #+#    #+#             */
/*   Updated: 2022/12/29 15:31:40 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++j])
	{
		while (map[j][++i])
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'N' &&
				map[j][i] != 'S' && map[j][i] != 'E' && map[j][i] != 'W' &&
				map[j][i] != ' ')
				return (1);
		i = -1;
	}
	return (0);
}

int	closed_border(char **map, int y)
{
	int	x;

	x = -1;
	while (map[y][++x])
		if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' ||
			map[y][x] == 'E' || map[y][x] == 'W')
			return (1);
	return (0);
}

int	closed_line(char **map, int y)
{
	int	x;

	x = -1;
	while (map[y][++x])
	{
		if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' ||
			map[y][x] == 'E' || map[y][x] == 'W')
		{
			if (x == 0 || x == (int)ft_strlen(map[y]) - 1)
				return (1);
			if (check_line_limits(map, y, x))
				return (1);
			if (check_line_midle(map, y, x))
				return (1);
		}
	}
	return (0);
}

int	check_closed(t_cub *cub)
{
	int	y;
	int	control;

	y = -1;
	control = 0;
	while (cub->map[++y])
	{
		if (y == 0 || y == cub->map_y - 1)
			control += closed_border(cub->map, y);
		else
			control += closed_line(cub->map, y);
		printf("Y: %d\nLine: %s\nControl: %d\n", y, cub->map[y], control);
	}
	return (control);
}

int	map_checker(t_cub *cub)
{
	if (check_chars(cub->map))
		return (error_msg("Invalid characters in map"));
	if (single_player(cub->map))
		return (error_msg("Map must have only one player"));
	if (check_closed(cub))
		return (error_msg("Map is not closed"));
	return (0);
}
