/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:02:36 by pcampos-          #+#    #+#             */
/*   Updated: 2022/12/29 13:15:49 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	*ft_strdup_map(const char *src)
{
	char	*str;
	int		len;
	int		index;

	index = 0;
	len = ft_strlen(src);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (src[index] != '\0' && src[index] != '\n')
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
