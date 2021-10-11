/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:02 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/11 14:38:55 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	//dst = (char *)data->data + (y * data->size_l + x * (data->bpp / 8));
	//data->addr[y * data->width + x]
	dst = (char *)data->data + (y * (data->size_l) + x * (data->bpp / 8));
	//dst = (char *)data->data + (y * (data->size_l) + x);
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

char	*get_texture_pixel_color(t_img *tex, t_mlx *mlx, int x, int y)
{
	int		txt_x;
	int		txt_y;
	char		*color;

	txt_x = 0;
	txt_y = 0;
	txt_x = tex->img_width / (100 / (((double)x / mlx->texture_piece_length) * 100.0));
	txt_y = tex->img_height / (100 / (((double)y / mlx->texture_piece_length) * 100.0));

	// Linux OS
	//color = (char *)tex->data + ((4 * tex->img_width * txt_y) + (4 * txt_x));

	// Mac OS
	color = (char *)tex->data + ((4 * (tex->size_l / 4) * txt_y) + (4 * txt_x));
	return (color);
}

void	draw_one_texture(t_mlx *mlx, int map_x, int map_y)
{
	int x;
	int y;
	char	*color;
	t_img *texture;

	y = 0;
	texture = pickup_texturetype(mlx->map, mlx ,map_x, map_y);
	while (y < mlx->texture_piece_length)
	{
		x = 0;
		while (x < mlx->texture_piece_length)
		{
			//*(int *)color = 0x008fff;
			if (texture != NULL)
				color = get_texture_pixel_color(texture, mlx, x, y);
			my_mlx_pixel_put(&mlx->img, (map_x * mlx->texture_piece_length) + x,
			(map_y * mlx->texture_piece_length) + y, *(int *)color);
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
