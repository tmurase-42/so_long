/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:29:54 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/09 19:10:00 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_img img)
{
	img.img = NULL;
	img.data = NULL;
	img.bpp = 0;
	img.endian = 0;
	img.img_height = 0;
	img.img_width = 0;
	img.size_l = 0;
}

static	void	init_struct_2(t_map *map, t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->map = map;
	mlx->window_size[X] = 0;
	mlx->window_size[Y] = 0;
	init_img(mlx->img);
	init_img(mlx->player);
	init_img(mlx->door);
	init_img(mlx->item);
	init_img(mlx->wall);
	mlx->item_list = NULL;
	mlx->door_list = NULL;
}

void	init_struct(t_map	*map, t_mlx *mlx)
{
	map->i = 0;
	map->maps = NULL;
	map->outer_wall = NULL;
	map->composition = ft_calloc(sizeof(t_composed_char),1);
	map->composition->collectible = 0;
	map->composition->exit_door = 0;
	map->composition->start_point = 0;
	map->postion[X] = 0;
	map->postion[Y] = 0;
	init_struct_2(map, mlx);
}
