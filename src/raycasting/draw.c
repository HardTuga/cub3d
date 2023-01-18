/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:28:25 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/18 17:47:17 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_walls(t_rloop *tudao, t_draw d, t_all *all)
{
	d.mlx = &all->mlx;
	choose_color(*tudao, all, &d);
	while (tudao->draw_start < tudao->draw_end)
	{
		my_mlx_pixel_put(&(d.mlx->img), SCREENW - d.x - 1, \
		tudao->draw_start, d.color);
		tudao->draw_start++;
	}
}
