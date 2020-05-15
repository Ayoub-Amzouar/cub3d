/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:32:11 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/13 16:51:24 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ????
float	pnret(float x, float a, float b, float c)
{
	if (x > 0)
		return (a);
	else if (x == 0)
		return (b);
	return (c);
}

// when checking x and y coordinates don't go out of the map
int		max_crd(crd intersect)
{
	data		info;
	static int	*x;
	static int	y;
	int		i;

	if (x == NULL || y == 0)
	{
		i = -1;
		info = ft_data(NULL);
		y = count_items(info.the_map);
		x = (int *)malloc(sizeof(int) * y);
		while (++i < y)
			x[i] =  ft_strlen(info.the_map[i]) * SQUARE_SIZE;
		y *= SQUARE_SIZE;
	}
	i = (int)(intersect.y / SQUARE_SIZE);
	if (intersect.y > y || intersect.y < 0 || intersect.x > x[i] || intersect.x < 0)
		return (0);
	return (1);
}

// calculate horizantal_intersection
crd		h_intersect(float ray_angle, player plr)
{
	crd		intersect;
	crd		next;
	float	of_y;

	ray_angle *= RADIN;
	of_y = sin(ray_angle) > 0 ? 0.1 : -0.1;
	intersect.y = floor(plr.y / SQUARE_SIZE + (sin(ray_angle) > 0 ? 1 : 0)) * SQUARE_SIZE;
	intersect.x = tan(ray_angle) ? (intersect.y - plr.y + tan(ray_angle) * plr.x) / tan(ray_angle) : 0;
	next.y = SQUARE_SIZE * pnret(sin(ray_angle), 1, 0, -1);
	next.x = tan(ray_angle) ? next.y / tan(ray_angle) : 0;
	while (max_crd(intersect) && !Awall(intersect.x, intersect.y + of_y))
	{
		intersect.x += next.x;
		intersect.y += next.y;
	}
	return(intersect);
}

// calculate vertical_intersection
crd		v_intersect(float ray_angle, player plr)
{
	crd		intersect;
	crd		next;
	float	of_x;

	ray_angle *= RADIN;
	of_x = cos(ray_angle) > 0 ? 0.1 : -0.1;
	intersect.x = floor(plr.x / SQUARE_SIZE + (cos(ray_angle) > 0 ? 1 : 0)) * SQUARE_SIZE;
	intersect.y = tan(ray_angle) * (intersect.x - plr.x) + plr.y;
	next.x = SQUARE_SIZE * pnret(cos(ray_angle), 1, 0, -1);
	next.y = next.x * tan(ray_angle);
	while (max_crd(intersect) && !Awall(intersect.x + of_x, intersect.y))
	{
		intersect.x += next.x;
		intersect.y += next.y;
	}
	return (intersect);
}

// calc the distance between the ray intersect and the player position
float	calc_distance(player plr, crd hi, crd vi, float ray_angle)
{
	float	res1;
	float	res2;
	float	ret;

	res1 = sqrt(pow(plr.x - hi.x, 2) + pow(plr.y - hi.y, 2));
	res2 = sqrt(pow(plr.x - vi.x, 2) + pow(plr.y - vi.y, 2));
	if (res1 < res2)
	{
		select_texture('h', ray_angle);
		g_offset_x = (int)hi.x % SQUARE_SIZE; // we'll use this value for the texture thing
		ret = res1 * cos((ray_angle - plr.rotationA) * RADIN);
	}
	else
	{
		select_texture('v', ray_angle);
		g_offset_x = (int)vi.y % SQUARE_SIZE;
		ret = res2 * cos((ray_angle - plr.rotationA) * RADIN);
	}
	return (ret);
}

// initial each ray then it goes in a while for a check
void	rays(player plr, data info)
{
	int		ray_num;
	float	ray_angle;
	float	dst;

	ray_angle = plr.rotationA - (FOV_ANGLE / 2);
	ray_angle = normA(ray_angle);
	ray_num = 0;
	g_wall_distance = (float*)malloc(sizeof(float) * info.wx);
	while (ray_num < info.wx)
	{
		dst = calc_distance(plr, h_intersect(ray_angle, plr), v_intersect(ray_angle, plr), ray_angle);
		g_wall_distance[ray_num] = dst;
		wall_rendering(dst, ray_num, info);
		ray_angle += FOV_ANGLE / (float)info.wx;
		ray_angle = normA(ray_angle);
		ray_num++;
	}
}
