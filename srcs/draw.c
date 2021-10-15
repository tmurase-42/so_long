/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:02 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/15 17:40:46 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->data + (y * (data->size_l) + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_img	*pickup_texturetype(t_map *map, t_mlx *mlx, int x, int y)
{
	if (map->maps[y][x] == '1')
		return (&mlx->wall);
	if (map->maps[y][x] == 'E')
		return (&mlx->door);
	if (map->maps[y][x] == 'C')
		return (&mlx->item);
	if (map->maps[y][x] == 'P')
		return (&mlx->player);
	return (NULL);
}

int	*get_texture_pixel_color(t_img *tex, t_mlx *mlx, int x, int y)
{
	int		x_basedon_tex;
	int		y_basedon_tex;
	int		*color;
	double	percentage_basedon_100_x;
	double	percentage_basedon_100_y;

	percentage_basedon_100_x
		= 100 / (((double)x / mlx->tex_piece_length) * 100.0);
	percentage_basedon_100_y
		= 100 / (((double)y / mlx->tex_piece_length) * 100.0);
	x_basedon_tex = tex->img_width / percentage_basedon_100_x;
	y_basedon_tex = tex->img_height / percentage_basedon_100_y;
	if (OS_TYPE == LINUX)
		color = tex->data + ((tex->img_width * y_basedon_tex) + x_basedon_tex);
	else
		color = tex->data
			+ (((tex->size_l / 4) * y_basedon_tex) + x_basedon_tex);
	return (color);
}

void	draw_one_texture(t_mlx *mlx, int map_x, int map_y)
{
	int		x;
	int		y;
	int		*color;
	t_img	*texture;

	y = 0;
	texture = pickup_texturetype(mlx->map, mlx, map_x, map_y);
	while (y < mlx->tex_piece_length)
	{
		x = 0;
		while (x < mlx->tex_piece_length)
		{
			if (texture != NULL)
				color = get_texture_pixel_color(texture, mlx, x, y);
			else
				*color = 0xFFFFFF;
			my_mlx_pixel_put(&mlx->img, (map_x * mlx->tex_piece_length) + x,
				(map_y * mlx->tex_piece_length) + y, *color);
			x++;
		}
		y++;
	}
}

void	draw_so_long(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->map->maps[y])
	{
		x = 0;
		while (mlx->map->maps[y][x])
		{
			draw_one_texture(mlx, x, y);
			x++;
		}
		y++;
	}
}
