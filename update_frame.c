/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:28:20 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/13 16:13:48 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// turn the color of the screen to black to refill it with a new frame
void	turn_frame_black(void)
{
	data	info;
	int		x;
	int		y;

	info = ft_data(NULL);
	y = 0;
	while (y < info.wy)
	{
		x = 0;
		while (x < info.wx)
		{
			put_pixel_img(x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img_ptr, 0 , 0);
}

// checks if the current x and y are a well
int		Awall(float x, float y, char *which1)
{
	int		i;
	int		j;
	data	info;

	info = ft_data(NULL);
	i = floor(x / SQUARE_SIZE);
	j = floor(y / SQUARE_SIZE);
	if (which1)
		*which1 = info.the_map[j][i];
	if (info.the_map[j][i] == '1')
		return (1);
	return (0);
}

// here we update x and y of the player
void	update_walk(int key, player *plr)
{
	float	wanted_x;
	float	wanted_y;

	if (key == UP_A)
		plr->walkD = 1;
	else if (key == DOWN_A)
		plr->walkD = -1;
	plr->mStep = plr->walkD * plr->moveS;
	wanted_x = plr->x + cos(plr->rotationA * RADIN) * plr->mStep;
	wanted_y = plr->y + sin(plr->rotationA * RADIN) * plr->mStep;
	if (Awall(wanted_x, wanted_y, NULL) == 0)
	{
		plr->x = wanted_x;
		plr->y = wanted_y;
	}
}

// here we update the player's view angle
void	update_turn(int key, player *plr)
{
	if (key == LEFT_A)
		plr->turnD = -1;
	else if (key == RIGHT_A)
		plr->turnD = 1;
	plr->rotationA += plr->turnD * plr->rotationS;
	plr->rotationA = (int)floor(normA(plr->rotationA));
}

// this function just redirects to the correct function depends on key
void	update_player(int key)
{
	player *plr;

	plr = myPlayer(0);
	if (key == UP_A || key == DOWN_A)
		update_walk(key, plr);
	else if (key == RIGHT_A || key == LEFT_A)
		update_turn(key, plr);
}
