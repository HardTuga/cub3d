/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:52:43 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/04 16:57:13 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef	struct s_ray
{
	t_vector	p;
	t_vector	dir;
	t_vector	plane;
}				t_ray;




#endif