#include "cub3d.h"

void	store_sprite_position(crd *sprites, data info)
{
	int	x;
	int	y;

	y = 0;
	g_sprite_num = 0;
	while (info.the_map[y] != NULL)
	{
		x = 0;
		while (info.the_map[y][x] != '\0')
		{
			if (info.the_map[y][x] == '2')
			{
				sprites[g_sprite_num].x = x * SQUARE_SIZE;
				sprites[g_sprite_num].y = y * SQUARE_SIZE;
				g_sprite_num++;
			}
			x++;
		}
		y++;
	}
}

void	initial_sprite_properties(crd *sprites, player plr)
{
	int	i;

	i = 0;
	g_sprite_distance = (float *)malloc(sizeof(float) * g_sprite_num);
	while (i < g_sprite_num)
	{
		g_sprite_distance[i] = sqrt(pow(plr.x - sprites[i].x, 2) + pow(plr.y - sprites[i].y, 2));
		i++;
	}
}

void	sort_sprites(crd **sprites)
{
	int	i;
	int	j;
	float	tmp_distance;
	crd	tmp_sprites;

	i = 0;
	while (i < g_sprite_num)
	{
		j = i+1;
		while (j < g_sprite_num)
		{
			if (g_sprite_distance[i] < g_sprite_distance[j])
			{
				tmp_distance = g_sprite_distance[i];
				tmp_sprites = (*sprites)[i];
				g_sprite_distance[i] = g_sprite_distance[j];
				(*sprites)[i] = (*sprites)[j];
				g_sprite_distance[j] = tmp_distance;
				(*sprites)[j] = tmp_sprites;
			}
			j++;
		}
		i++;
	}
}

void	calc_sprite_info(sprite *sprt, player plr, data info, crd *sprites)
{
	float	dpp;

	dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	sprt->height = (SQUARE_SIZE / g_sprite_distance[sprt->i]) * dpp;
	// calc where to start and end painting sprite in height
	sprt->hi_s = -sprt->height / 2 + info.wy / 2;
	sprt->hi_e = sprt->height / 2 + info.wy / 2;
	// calc where to start and end painting sprite in width
	sprt->wi_s = calc_sp_x_start(&sprt, plr, info, sprites[sprt->i]);
	sprt->wi_e = sprt->wi_s + sprt->height;
}

void	draw_sprite(player plr, data info)
{
	sprite	sprt;
	crd	*sprites;

	sprites = (crd *)malloc(sizeof(crd) * 5);
	store_sprite_position(sprites, info);
	initial_sprite_properties(sprites, plr);
	sort_sprites(&sprites);
	sprt.i = 0;
	while (sprt.i < g_sprite_num)
	{
		calc_sprite_info(&sprt, plr, info, sprites);
		draw_sprite_texture(sprt, info, sprt.i);
		sprt.i++;
	}
	free(g_sprite_distance);
	free(g_wall_distance);
	free(sprites);
}
