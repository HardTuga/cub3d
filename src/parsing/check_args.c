/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:25:04 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/19 11:47:49 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

int	check_args(int ac, char **av)
{
	if (ac != 2)
		return (error_msg("Wrong number of arguments"));
	if (rev_strstr(av[1], ".cub"))
		return (error_msg("Invalid file extension"));
	return (0);
}
