/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:21:17 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/12 15:03:16 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	exit_handler(t_all *all)
{
	(void)all;
	exit(EXIT_SUCCESS);
}

void	hooks(t_all *all)
{
	mlx_hook(all->mlx.win, 2, 1L << 0, key_pressed, all);
	mlx_hook(all->mlx.win, 3, 1L << 1, key_released, all);
	mlx_loop_hook(all->mlx.mlx, handle_hooks, all);
	mlx_hook(all->mlx.win, 17, 0, exit_handler, all);
}
