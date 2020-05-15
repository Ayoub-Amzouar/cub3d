/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:51:34 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/13 11:50:01 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// draw the cell and floor
void	draw_background(data info)
{
	int		x;
	int		y;

	y = 0;
	while (y < info.wy / 2)
	{
		x = 0;
		while (x < info.wx)
		{
			put_pixel_img(x, y, info.cell);
			x++;
		}
		y++;
	}
	while (y < info.wy)
	{
		x = 0;
		while (x < info.wx)
		{
			put_pixel_img(x, y, info.floor);
			x++;
		}
		y++;
	}
}

// this which draws the whole frame in the screen
void	frame_render(int argc, char *argv)
{
	data	f;
	player	plr;

	f = ft_data(NULL);
	plr = *myPlayer(0);
	draw_background(f);
	rays(plr, f);
	draw_sprite(plr, f);
	if (argc == 3)
		export_bmp(argv, argc, f.wx, f.wy);
	else
		mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img_ptr, 0, 0);
}
