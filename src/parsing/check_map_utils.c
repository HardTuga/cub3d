/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:30:06 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/12 16:02:35 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_element(char c, int o)
{
	if (o == 1)
	{
		if (c == '1' || c == '3' || c == '4' || c == '5' || c == '6')
			return (0);
		else
			return (1);
	}
	else
	{
		if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
			|| c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
			|| c == '6')
			return (0);
		else
			return (1);
	}
	return (0);
}

// int	check_element(char c, int o)
// {
	// if (o == 1)
	// {
		// if (c != '1')
			// return (1);
	// }
	// else
	// {
		// if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
			// || c == '1' || c == '2')
			// return (0);
		// else
			// return (1);
	// }
	// return (0);
// }

int	check_door(char **map, int y, int x)
{
	if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ' ||
		map[y + 1][x] == ' ' || map[y - 1][x] == ' ')
		return (1);
	return (0);
}

int	check_line_limits(char **map, int y, int x)
{
	if (x == 1)
	{
		if (check_element(map[y][0], 1) || check_element(map[y][2], 0) ||
			check_element(map[y + 1][1], 0) || check_element(map[y - 1][1], 0))
			return (1);
	}
	else if (x == (int)ft_strlen(map[y]) - 2)
	{
		if (check_element(map[y][x - 1], 0) || check_element(map[y][x + 1], 1)
		|| check_element(map[y + 1][x], 0) || check_element(map[y - 1][x], 0))
			return (1);
	}
	return (0);
}

int	check_line_midle(char **map, int y, int x)
{
	if (x <= 1 || x >= (int)ft_strlen(map[y]) - 2)
		return (0);
	if (check_element(map[y][x - 1], 0) || check_element(map[y][x + 1], 0) ||
		check_element(map[y + 1][x], 0) || check_element(map[y - 1][x], 0))
		return (1);
	return (0);
}

int	single_player(char **map, t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	j = -1;
	count = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' ||
				map[j][i] == 'W')
			{
				cub->player.x = i;
				cub->player.y = j;
				cub->player.dir = map[j][i];
				map[j][i] = '0';
				count++;
			}
		}
	}
	if (count == 1)
		return (0);
	return (1);
}
