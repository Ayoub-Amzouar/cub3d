/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/18 08:30:34 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define BUFFER_SIZE 10000

# include <mlx.h>
# include "libft.h"
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct
{
	char 	**NO;
	char 	**EA;
	char 	**SO;
	char 	**WE;
	char	**S;
	char 	*map;
	char	**fre;
}				data;

int			get_next_line(int fd, char **line);
char		**get_resolution(char *data_file);
char		**get_path(char *data_file, char *identifier);
int			get_color(char *data_file, char *identifier);
char		**get_map(char *data_file, int *sign);
char		**allocate(char	*data_file);
void		free_2D(char **array);
int			size_xy(char *data_file, char id, int state);
char		*path(char *data_file, int id, int state);

#endif
