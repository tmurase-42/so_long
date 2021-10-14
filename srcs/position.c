/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:10:29 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/14 15:01:47 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*create_items_node(int x, int y)
{
	int		*position;
	t_list	*node;

	position = ft_calloc(2, sizeof(int *));
	position[X] = x;
	position[Y] = y;
	node = ft_lstnew(position);
	return (node);
}

void	get_items_position(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map->maps[y])
	{
		x = 0;
		while (mlx->map->maps[y][x])
		{
			if (mlx->map->maps[y][x] == 'C')
				ft_lstadd_back(&mlx->item_list, create_items_node(x, y));
			if (mlx->map->maps[y][x] == 'E')
				ft_lstadd_back(&mlx->door_list, create_items_node(x, y));
			x++;
		}
		x = 0;
		y++;
	}
}

void	get_start_position(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->maps[y])
	{
		x = 0;
		while (map->maps[y][x])
		{
			if (map->maps[y][x] == 'P')
			{
				map->postion[X] = x;
				map->postion[Y] = y;
			}
			x++;
		}
		y++;
	}
}

void	get_position(t_mlx *mlx)
{
	get_start_position(mlx->map);
	get_items_position(mlx);
	test_printf_items(mlx);
}
