/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/13 16:30:00 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define BUFFER_SIZE 10000
#define SQUARE_SIZE 64 
#define RADIN (M_PI / 180)
#define FOV_ANGLE 60
#define WALL_WIDTH 1
#define Ystep -SQUARE_SIZE

# include <mlx.h>
# include "libft.h"
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

/* ##### KEYS ##### */
#define UP_A 65362
#define DOWN_A 65364
#define LEFT_A 65361
#define RIGHT_A 65363
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define ESC_KEY 65307

void	*g_mlx_ptr;
void	*g_win_ptr;
void	*g_img_ptr;
int		*g_img_data;
int		g_line;
int		g_offset_x;
int		*g_texture;
float	*g_wall_distance;
int	g_sprite_num;
float	*g_sprite_distance;
int	*g_x_len;

typedef struct
{
	int		wx;
	int		wy;
	int 	*NO;
	int 	*EA;
	int 	*SO;
	int 	*WE;
	int		*S;
	int		floor;
	int		cell;
	char	**the_map;
}			data;

typedef struct
{
	float	x;
	float	y;
	int		walkD;
	int		turnD;
	int		moveS;
	int		rotationA;
	int		rotationS;
	int		mStep;
}			player;

typedef struct
{
	int	height;
	int	hi_s;
	int	hi_e;
	int	wi_s;
	int	wi_e;
	int	i;
}	sprite;

typedef struct
{
	float	x;
	float	y;
}			crd;

typedef	struct
{
	float	dpp;
	float	bottom;
	int		top;
	int		offset_y;
	int	dst_ftop;
}			wall;

int			get_next_line(int fd, char **line);
int			check_errors(char *stored_data);
void		free_2D(char **splited);
int			count_items(char **str);
int			check_map(char **s, char *d);
void		if_fail(void *state);
int		check_file_name(char *file_name, int fd);
data		ft_data(char *data_file);
void		open_window(void);
void		frame_render(int argc, char *argv);
void		init_frame(int argc, char *argv);
void		put_pixel_img(int x, int y, int color);
player		*myPlayer(int state);
void		update_player(int key);
int			Awall(float x, float y);
void		rays(player plr, data info);
int			map_complete(int i, int ret);
float		normA(float angle);
int			max_crd(crd intersect);
void		wall_rendering(float ray_d, int x, data info);
void		select_texture(char c, float ray_angle);
void		sprite_rendering(player plr, float ray_angle, data info, int x);
void		draw_sprite(player plr, data info);
float		calc_sp_x_start(player plr, data info, crd sprite);
void		draw_sprite_texture(sprite sprt, data info, int i);
void		export_bmp(char *flag, int argc, int width, int height);
int		check_start_line(char **lines, int id, int max);
int		check_end_line(char **lines, int id, int max, int ret);
int		horizontal_check(char *line, int id, int max, int ret);
int		vertical_check(char **lines, int max_y, int ret);
int		check_empty_line(char *map_data, int ret);
int		only_nbr(char **rgb);

#endif
