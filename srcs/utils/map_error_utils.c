/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:01:46 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/09 13:08:06 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_outer_wall(t_map *map)
{
	int	i;
	i = 0;
	map->outer_wall = ft_calloc(sizeof(char **), MAX_Y );
	while (i < MAX_Y)
	{
		map->outer_wall[i] = null_error(ft_calloc(sizeof(char *), MAX_X ), 2);
		i++;
	}
	i = 0;
	while (i < MAX_Y)
	{
		ft_memset(map->outer_wall[i], ' ', MAX_X);
		if (i == 0 || i == MAX_Y -1)
			ft_memset(map->outer_wall[i],'X',MAX_X);
		else
		{
			ft_memset(map->outer_wall[i], 'X', 1);
			ft_memset(map->outer_wall[i] + MAX_X - 1, 'X', 1);
		}
		i++;
	}
}


void	flood_fill(int x, int y, t_map *map, int *status)
{
	if (map->outer_wall[y - 1][x] == 'X' || map->outer_wall[y + 1][x] == 'X' || map->outer_wall[y][x - -1] == 'X' || map->outer_wall[y][x + 1] == 'X')
	{
		*status = FALSE;
		return ;
	}
	if (map->outer_wall[y][x] == '#')
		return ;
	map->outer_wall[y][x] = '#';
	if (map->outer_wall[y - 1][x] == '0' || map->outer_wall[y - 1][x] == 'C' || map->outer_wall[y - 1][x] == 'E' || map->outer_wall[y - 1][x] == ' ')
		flood_fill(x, y - 1, map, status);
	if (map->outer_wall[y + 1][x] == '0' || map->outer_wall[y + 1][x] == 'C' || map->outer_wall[y + 1][x] == 'E' || map->outer_wall[y + 1][x] == ' ')
		flood_fill(x, y + 1, map, status);
	if (map->outer_wall[y][x - 1] == '0' || map->outer_wall[y][x - 1] == 'C' || map->outer_wall[y][x - 1] == 'E' || map->outer_wall[y][x - 1] == ' ')
		flood_fill(x - 1, y, map, status);
	if (map->outer_wall[y][x + 1] == '0' || map->outer_wall[y][x + 1] == 'C' || map->outer_wall[y][x + 1] == 'E' || map->outer_wall[y][x + 1] == ' ')
		flood_fill(x + 1, y, map, status);
}
