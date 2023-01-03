/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:15:40 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/03 17:03:30 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = -1;
	printf("MAP:\n");
	while (map[++i])
		printf("%s\n", map[i]);
}

void	print_cub(t_cub *cub)
{
	printf("NO: %s\n", cub->n);
	printf("SO: %s\n", cub->s);
	printf("WE: %s\n", cub->w);
	printf("EA: %s\n", cub->e);
	printf("F: %s\n", cub->f);
	printf("C: %s\n", cub->c);
	print_map(cub->map);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(t_cub));
	if (check_args(argc, argv))
		return (1);
	if (parse_file(&cub, argv))
	{
		free_cub(&cub);
		return (1);
	}
	if (map_checker(&cub))
	{
		free_cub(&cub);
		return (1);
	}
	print_cub(&cub);
	
	free_cub(&cub);
}
