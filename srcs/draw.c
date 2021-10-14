/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:02 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/14 20:43:59 by tmurase          ###   ########.fr       */
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
	int		txt_x;
	int		txt_y;
	int		*color;

	txt_x = 0;
	txt_y = 0;
	txt_x = tex->img_width / (100 / (((double)x / mlx->tex_piece_length) * 100.0));
	txt_y = tex->img_height / (100 / (((double)y / mlx->tex_piece_length) * 100.0));

	//tex_x,y は描画する長さの場所から、実際のテクスチャ画像のどれくらいの長さなのかを算出している。
	printf("tex->img_width [%d]\n",tex->img_width);
	printf("tex->img_height [%d]\n", tex->img_height);
	printf("x [%d]\n", x);
	printf("y [%d]\n", y);
	printf("tex_piece_length [%d]\n", mlx->tex_piece_length);
	printf("(x / mlx->tex_piece_length ) [%f]\n",((((double)x / mlx->tex_piece_length))));
	printf("(y / mlx->tex_piece_length ) [%f]\n",((((double)y / mlx->tex_piece_length))));
	printf("(x / mlx->tex_piece_length )*100.0 [%f]\n",((((double)x / mlx->tex_piece_length) * 100.0)));
	printf("(y / mlx->tex_piece_length )*100.0 [%f]\n",((((double)y / mlx->tex_piece_length) * 100.0)));
	printf("100 / (x / mlx->tex_piece_length )*100.0 [%f]\n",(100 / (((double)x / mlx->tex_piece_length) * 100.0)));
	printf("100 / (y / mlx->tex_piece_length )*100.0 [%f]\n",(100 / (((double)y / mlx->tex_piece_length) * 100.0)));
	printf("tex_x [%d]\n", txt_x);
	printf("txt_y [%d]\n", txt_y);
	printf("--------------------\n");
	if (OS_TYPE == LINUX)
		color = tex->data + ((tex->img_width * txt_y) + txt_x);
	else
		color = tex->data + (((tex->size_l / 4) * txt_y) + txt_x);
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
