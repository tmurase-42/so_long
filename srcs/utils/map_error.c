/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:27:17 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 19:09:15 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	so_long_strchr(t_map *map)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map->maps[p])
	{
		if (map->maps[p][i] == 'C')
			map->composition->collectible++;
		else if (map->maps[p][i] == 'E')
			map->composition->exit_door++;
		else if (map->maps[p][i] == 'P')
			map->composition->start_point++;
		else if (map->maps[p][i] != '0' && map->maps[p][i] != '1'
				&& map->maps[p][i] != '\0')
			return (FALSE);
		else if(map->maps[p][i] == '\0')
		{
			p++;
			i = 0;
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_conposition(t_map *map)
{
	if (map->composition->collectible > 10)
		return (FALSE);
	if (map->composition->exit_door > 1)
		return (FALSE);
	if (map->composition->start_point > 1)
		return (FALSE);
	return (TRUE);
}

t_bool	check_wallissafe(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	init_outer_wall(map);
	while (map->maps[y])
	{
		x = 0;
		while (map->maps[y][x])
		{
			map->outer_wall[y + 2][x + 2] = map->maps[y][x];
			x++;
		}
		y++;
	}
	x = 0;
	while(map->outer_wall[x])
	{
		printf("outer_wall [%s]\n",map->outer_wall[x]);
		x++;
	}
	return (TRUE);
}

void	check_mapfile(t_map *map)
{
	if (so_long_strchr(map) == FALSE)
		map_error(2);
	if (check_conposition(map) == FALSE)
		map_error(3);
	if (check_wallissafe(map) == FALSE)
		map_error(4);
}
