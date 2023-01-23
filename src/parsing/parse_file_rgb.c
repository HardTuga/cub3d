/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:19 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/19 17:35:00 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	convert_rgb(t_cub *cub)
{
	char	**tmp;

	tmp = ft_split(cub->c, ',');
	cub->c_trgb = create_trgb(0, ft_atoi(tmp[0]), ft_atoi(tmp[1]),
			ft_atoi(tmp[2]));
	free_matrix(tmp);
	tmp = ft_split(cub->f, ',');
	cub->f_trgb = create_trgb(0, ft_atoi(tmp[0]), ft_atoi(tmp[1]),
			ft_atoi(tmp[2]));
	free_matrix(tmp);
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
