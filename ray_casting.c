/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:32:11 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/01 15:55:14 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// initial each ray then it goes in a while for a check
void	rays(player plr, data info)
{
	float	x;
	float	y;
	int		i;
	float	rayAngle;

	rayAngle = plr.rotationA - (FOV_ANGLE / 2);
	i = 0;
	while (i < 1)
	{
		x = plr.x;
		y = plr.y;
		while (Awall(x, y) == 0)
		{
			x += cos(rayAngle * RADIN);
			y += sin(rayAngle * RADIN);
			put_pixel_img(x, y, 0xFFFFFF);
		}
		rayAngle += FOV_ANGLE / 1.0;
		i++;
	}
}