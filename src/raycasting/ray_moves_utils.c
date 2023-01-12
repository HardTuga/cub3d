/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:21:17 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/12 14:50:00 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	exit_handler(t_all *all)
{
	
}

void	hooks(t_all *all)
{
	mlx_hook(p->mlx.win, 2, 1L << 0, key_p, all);
	mlx_hook(p->mlx.win, 3, 1L << 1, key_r, all);
	mlx_loop_hook(p->mlx.ptr, handle_keys, all);
	mlx_hook(p->mlx.win, 17, 0, exit_handler, all);
}
