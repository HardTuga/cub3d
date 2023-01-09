/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:52:43 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/09 12:10:18 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

typedef struct s_rloop
{
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		draw_start;
	int		draw_end;
	int		line_height;
	double	camx;
	double	perpwdist;
	t_vector	rdir;
	t_vector	sdist;
	t_vector	ddist;
}				t_rloop;





#endif