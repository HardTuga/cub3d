/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:00:22 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/19 11:20:49 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	open_close_door(t_all *all)
{
	if (all->cub->map[][] == '2')
	{
		//do_door_animation();
		all->cub->map[][] = '3';
	}
	else if (all->cub->map[][] == '3')
	{
		//do_door_animation();
		all->cub->map[][] = '2';
	}
}