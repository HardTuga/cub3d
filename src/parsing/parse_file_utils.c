/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:50:26 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/12 16:00:15 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	n_chars(char *str, char c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == c)
			j++;
	}
	return (j);
}

int	check_rgb(char *element)
{
	char	**tmp;

	tmp = ft_split(element, ',');
	if (matrix_size(tmp) != 3 || n_chars(element, ',') != 2)
	{
		free_matrix(tmp);
		return (1);
	}
	if (ft_atoi(tmp[0]) < 0 || ft_atoi(tmp[1]) < 0 || ft_atoi(tmp[2]) < 0
		|| ft_atoi(tmp[0]) > 255 || ft_atoi(tmp[1]) > 255
		|| ft_atoi(tmp[2]) > 255)
	{
		free_matrix(tmp);
		return (1);
	}
	free_matrix(tmp);
	return (0);
}

int	check_image(char *element)
{
	int	fd;

	if (rev_strstr(element, ".xpm"))
		return (1);
	fd = open(element, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	valid_elements(t_cub *cub)
{
	if (check_rgb(cub->f) || check_rgb(cub->c))
		return (1);
	//if (check_image(cub->n) || check_image(cub->s) || check_image(cub->w)
	//	|| check_image(cub->e))
	//	return (1);
	return (0);
}
