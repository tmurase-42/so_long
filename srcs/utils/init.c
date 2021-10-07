/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:29:54 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/07 14:31:27 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	init_struct_2(t_map *map, t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->map = map;
	mlx->img.img = NULL;
	mlx->img.data = NULL;
	mlx->img.bpp = 0;
	mlx->img.endian = 0;
	mlx->img.img_height = 0;
	mlx->img.img_width = 0;
	mlx->img.size_l = 0;
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
