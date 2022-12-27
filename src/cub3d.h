/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:20:39 by pcampos-          #+#    #+#             */
/*   Updated: 2022/12/27 18:25:30 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//------------------------------INCLUDES------------------------------//
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

//------------------------------DEFINES------------------------------//

//------------------------------STRUCTS------------------------------//
typedef struct s_cub
{
	char	*n;
	char	*s;
	char	*w;
	char	*e;
	char	*f;
	char	*c;	
	char	**map;
	int		map_y;
	int		tmp;
}				t_cub;
//------------------------------CUB3D_MAIN------------------------------//

//------------------------------ERRORS------------------------------//
int		error_msg(char *str);

//------------------------------FREE_UTILS------------------------------//
void	free_str(char *str);

//------------------------------CHECK_ARGS------------------------------//
int		check_args(int ac, char *av);
int		rev_strstr(char *str, char *find);

//------------------------------FILL_STRUCT------------------------------//
int		parse_file(t_cub *cub, char *av);

#endif