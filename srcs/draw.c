/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:02 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/10 20:49:27 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->data + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
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

int get_texture_pixel_color(t_img *tex, t_mlx *mlx, int x, int y)
{
	int		txt_x;
	int		txt_y;
	int		*color;

	txt_x = 0;
	txt_y = 0;
	txt_x = tex->img_width / (100 / (((double)x / mlx->texture_piece_length) * 100.0));
	txt_y = tex->img_height / (100 / (((double)y / mlx->texture_piece_length) * 100.0));
	//printf("before\n");
	//color = tex->data + ((4 * tex->img_width * txt_y) + (4 * txt_x));
	//printf("after\n");
	//printf("color [%d]\n", *color);
	//color = tex->data + ((4 * tex->img_height * txt_y) + (4 * txt_x));
	color = tex->data + ((tex->img_width * txt_y) + (txt_x));
	return (*color);
}

void	draw_one_texture(t_mlx *mlx, int map_x, int map_y)
{
	int x;
	int y;
	int	color;
	t_img *texture;

	y = 0;
	//一枚のテクスチャ分のピクセルの色付けを行う。
	texture = pickup_texturetype(mlx->map, mlx ,map_x, map_y);
	while (y < mlx->texture_piece_length)
	{
		x = 0;
		while (x < mlx->texture_piece_length)
		{
			color = 0x008fff;
			if (texture != NULL)
				color = get_texture_pixel_color(texture, mlx, x, y);
			//printf("color [%x]\n", color);
			//printf("count [%d]\n", x);
			//printf("count [%d]\n", y);
			//printf("texture_piece_length [%d]\n", mlx->texture_piece_length);
			my_mlx_pixel_put(&mlx->img, (map_x * mlx->texture_piece_length) + x,
			(map_y * mlx->texture_piece_length) + y, color);
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
		while(mlx->map->maps[y][x])
		{
			draw_one_texture(mlx, x, y);
			x++;
		}
		y++;
	}
}
