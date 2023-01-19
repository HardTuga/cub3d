/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:14:15 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/19 11:11:40 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str(char *str)
{
	if (str && *str)
		free(str);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free_str(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

void	free_cub(t_cub *cub)
{
	free_str(cub->n);
	free_str(cub->s);
	free_str(cub->w);
	free_str(cub->e);
	free_str(cub->f);
	free_str(cub->c);
	free_matrix(cub->map);
}

void	free_imgs(t_all *all)
{
	int	i;

	i = -1;
	while (++i < 6)
		mlx_destroy_image(all->mlx.mlx, all->tex[i].img);
}
