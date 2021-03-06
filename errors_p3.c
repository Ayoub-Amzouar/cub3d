/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_p3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 07:30:15 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/01 16:29:59 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// and here we'll check the map file has the correct extension
int		extension_check(char *file_name)
{
	int		i;
	int		j;
	char	*set;

	j = 0;
	set = ".cub";
	i = 0;
	while (file_name[i] != '.')
		i++;
	while (file_name[i] != '\0' || set[j] != '\0')
	{
		if (file_name[i] != set[j])
		{
			ft_putstr_fd("Wrong File Extension\n", 2);
			return (0);
		}
		j++;
		i++;
	}
	return (1);
}

// this checks if the given file is exist with the help of the return value of open function
int		file_existence(int fd)
{
	if (fd < 0)
	{
		perror("Error ");
		return (0);
	}
	return (1);
}

// if the allocation fails then exit and return an erron message
void	if_fail(void *state)
{
	if (state == NULL)
	{
		perror("Error ");
		mlx_destroy_window(g_mlx_ptr, g_win_ptr);
		exit(1);
	}
}

// here we check either if the map isn't complete or it's more than complete hah
int		map_complete(int i, int ret)
{
	if (i != 9 && ret != 0)
	{
		if (i < 9)
			ft_putstr_fd("The Map's Elements Are Not Complete\n", 2);
		else if (i > 9)
			ft_putstr_fd("There's More Than Required Number Of Elements\n", 2);
		return (0);
	}
	return (ret);
}
