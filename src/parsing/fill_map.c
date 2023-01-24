/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:48:41 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/23 17:51:15 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	max_x(char **map)
{
	int	y;
	int	i;

	y = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > ft_strlen(map[y]))
			y = i;
	}
	return (ft_strlen(map[y]));
}

char	*remake_line(char *line, int len)
{
	int		i;
	char	*new_line;

	i = -1;
	new_line = malloc(sizeof(char) * (len + 1));
	new_line[len] = '\0';
	while (line[++i])
		new_line[i] = line[i];
	while (i < len)
	{
		new_line[i] = ' ';
		i++;
	}
	return (new_line);
}

void	redo_map(t_cub *cub, int len)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = malloc(sizeof(char *) * (cub->map_y + 1));
	tmp[cub->map_y] = NULL;
	while (cub->map[++i])
		tmp[i] = remake_line(cub->map[i], len);
	free_matrix(cub->map);
	cub->map = tmp;
}

void	fill_map(t_cub *cub)
{
	cub->map_x = max_x(cub->map);
	redo_map(cub, cub->map_x);
}
