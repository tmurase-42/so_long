/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:27:17 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/14 13:00:07 by tmurase          ###   ########.fr       */
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
		else if (map->maps[p][i] == '\0')
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
	if (map->composition->collectible > 20)
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
	int	status;

	x = 0;
	y = 0;
	status = TRUE;
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
	flood_fill(map->postion[X] + 2, map->postion[Y] + 2, map, &status);
	if (status == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	is_rectangular(t_map *map)
{
	size_t	length;
	size_t	old_length;
	int		i;

	length = 0;
	i = 0;
	old_length = ft_strlen(map->maps[0]);
	while (map->maps[i])
	{
		length = ft_strlen(map->maps[i]);
		if (length != old_length)
			return (FALSE);
		old_length = length;
		i++;
	}
	return (TRUE);
}

void	check_mapfile(t_mlx *mlx)
{
	if (is_rectangular(mlx->map) == FALSE)
		map_error(7);
	if (so_long_strchr(mlx->map) == FALSE)
		map_error(2);
	if (check_conposition(mlx->map) == FALSE)
		map_error(3);
	get_position(mlx);
	if (check_wallissafe(mlx->map) == FALSE)
		map_error(4);
}
