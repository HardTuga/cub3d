/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:43:43 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/12 16:00:10 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_elements(t_cub *cub)
{
	if (cub->n == NULL || cub->s == NULL || cub->w == NULL || cub->e == NULL
		|| cub->f == NULL || cub->c == NULL)
		return (error_msg("Wrong number of elements"));
	if (valid_elements(cub))
		return (error_msg("Invalid value of one or more elements"));
	return (0);
}

void	fill_params(t_cub *cub, char *str)
{
	if (!ft_strncmp(str, "NO ", 3) && cub->n == NULL)
		cub->n = ft_strdup(str + 3);
	else if (!ft_strncmp(str, "SO ", 3) && cub->s == NULL)
		cub->s = ft_strdup(str + 3);
	else if (!ft_strncmp(str, "WE ", 3) && cub->w == NULL)
		cub->w = ft_strdup(str + 3);
	else if (!ft_strncmp(str, "EA ", 3) && cub->e == NULL)
		cub->e = ft_strdup(str + 3);
	else if (!ft_strncmp(str, "F ", 2) && cub->f == NULL)
		cub->f = ft_strdup(str + 2);
	else if (!ft_strncmp(str, "C ", 2) && cub->c == NULL)
		cub->c = ft_strdup(str + 2);
}

int	fill_elements(t_cub *cub, char **tmp)
{
	int	i;

	i = -1;
	cub->map_y = matrix_size(tmp) - 6;
	while (++i <= 5)
		fill_params(cub, tmp[i]);
	if (check_elements(cub))
	{
		free_matrix(tmp);
		return (error_msg("Error parsing elements"));
	}
	cub->map = malloc(sizeof(char **) * (cub->map_y + 1));
	if (!cub->map)
		return (error_msg("Error allocating memory"));
	cub->map[cub->map_y] = NULL;
	while (tmp[i] && i < cub->map_y + 6)
	{
		cub->map[i - 6] = ft_strdup(tmp[i]);
		i++;
	}
	free_matrix(tmp);
	return (0);
}

int	file_line(char *av)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		error_msg("Error opening file");
		exit(2);
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (tmp[0] != '\n')
			i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close (fd);
	return (i);
}

int	parse_file(t_cub *cub, char **av)
{
	int		fd;
	int		i;
	char	**tmp;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_msg("Error opening file"));
	cub->map_y = file_line(av[1]);
	tmp = malloc(sizeof(char *) * (cub->map_y + 1));
	tmp[cub->map_y] = NULL;
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n' && cub->map_y > 0)
		{
			tmp[++i] = ft_strdup_map(line);
			cub->map_y--;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (fill_elements(cub, tmp));
}
