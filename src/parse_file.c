/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:43:43 by pcampos-          #+#    #+#             */
/*   Updated: 2022/12/27 18:25:40 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(t_cub *cub, char *av)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (error_msg("Error opening file"));
	line = get_next_line(fd);
	while (line)
	{
	}
}
