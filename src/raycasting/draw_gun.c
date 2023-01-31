/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:54:26 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/31 11:48:54 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_gun(t_all *all, t_data *img, t_vector2 pos, t_vector2 size)
{
	t_vector		posd;
	t_vector2		put;
	t_vector		incr;
	unsigned int	color;

	posd.y = 0;
	put.y = pos.y;
	incr.x = fabs((double)img->img_width / size.x);
	incr.y = fabs((double)img->img_height / size.y);
	while (put.y < pos.y + size.y)
	{
		posd.x = 0;
		put.x = pos.x;
		while (put.x < pos.x + size.x)
		{
			color = *get_img_pixel(img, (int)(posd.x), (int)(posd.y));
			if (color != 0x00FCFEFC)
				my_mlx_pixel_put(&all->mlx.img, put.x, put.y, color);
			posd.x += incr.x;
			put.x += 1;
		}
		posd.y += incr.y;
		put.y += 1;
	}
}

t_vector2	vector2(int x, int y)
{
	t_vector2	tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp);
}