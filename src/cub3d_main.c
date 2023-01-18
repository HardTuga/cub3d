/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:15:40 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/17 19:03:18 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map(char **map)
{
	int	i;

	i = -1;
	printf("MAP:\n");
	while (map[++i])
		printf("%s\n", map[i]);
}

static void	print_cub(t_cub *cub)
{
	printf("NO: %s\n", cub->n);
	printf("SO: %s\n", cub->s);
	printf("WE: %s\n", cub->w);
	printf("EA: %s\n", cub->e);
	printf("F: %s\n", cub->f);
	printf("F UINT: %u\n", cub->f_trgb);
	printf("C: %s\n", cub->c);
	printf("C UINT: %u\n", cub->c_trgb);
	printf("Player Stats:\nX: %d Y: %d\nOrientation: %c\n", \
cub->player.x, cub->player.y, cub->player.dir);
	print_map(cub->map);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(t_cub));
	if (check_args(argc, argv))
		return (1);
	if (parse_file(&cub, argv) || map_checker(&cub))
	{
		free_cub(&cub);
		return (1);
	}
	print_cub(&cub);
	ray_main(&cub);
	free_cub(&cub);
}
