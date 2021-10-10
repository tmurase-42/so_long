/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:02 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/10 19:52:38 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->data + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_one_texture(t_mlx *mlx, int map_x, int map_y)
{
	int x;
	int y;
	int	color;

	y = 0;
	//一枚のテクスチャ分のピクセルの色付けを行う。
	while (y < mlx->texture_piece_length)
	{
		x = 0;
		while (x < mlx->texture_piece_length)
		{
			color = 0x0080ff;
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
			printf("map x [%d]\n", x);
			printf("map y [%d]\n", y);
			draw_one_texture(mlx, x, y);
			x++;
		}
		y++;
	}
}
