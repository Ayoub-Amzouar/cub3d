/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_p4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:24:28 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/17 10:32:02 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_empty_line(char *map_data, int ret)
{
	int	i;
	int	map_len;

	map_len = ft_strlen(map_data);
	i = 0;
	if (ret)
	{
		while (map_data[i] != '\n' || map_data[i + 1] != '1')
			i++;
		while (map_data[i] != '\0')
		{
			i++;
			if (i + 2 <= (map_len - 2) && map_data[i] == '1'
				&& map_data[i + 1] == '\n' && map_data[i + 2] == '\n')
			{
				ft_putstr_fd("Error: Map's Content Is Wrong !\n", 2);
				return (0);
			}
		}
	}
	return (ret);
}

int	only_nbr(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (rgb[i][j] < '0' || rgb[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
