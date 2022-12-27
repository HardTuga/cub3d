/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:25:04 by pcampos-          #+#    #+#             */
/*   Updated: 2022/12/27 11:39:54 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rev_strstr(char *str, char *find)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = ft_strlen(find);
	while (i >= 0 && j >= 0)
	{
		if (str[i] != find[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

int	check_args(int ac, char *av)
{
	if (ac > 1)
		return (error_msg("Too many arguments"));
	if (rev_strstr(av, ".cub"))
		return (error_msg("Invalid file extension"));
}
