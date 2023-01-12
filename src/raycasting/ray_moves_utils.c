/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:21:17 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/12 16:03:34 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	exit_handler(t_all *all)
{
	free_cub(all->cub);
	if (all->mlx.win != NULL)
		mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	mlx_destroy_display(all->mlx.mlx);
	free(all->mlx.mlx);
	exit(EXIT_SUCCESS);
}

void	hooks(t_all *all)
{
	mlx_hook(all->mlx.win, 2, 1L << 0, key_pressed, all);
	mlx_hook(all->mlx.win, 3, 1L << 1, key_released, all);
	mlx_loop_hook(all->mlx.mlx, handle_keys, all);
	mlx_hook(all->mlx.win, 17, 0, exit_handler, all);
}
