/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:01:46 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 19:09:01 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_outer_wall(t_map *map)
{
	int	i;
	i = 0;
	map->outer_wall = ft_calloc(sizeof(char **), MAX_Y + 1);
	while (i < MAX_Y)
	{
		map->outer_wall[i] = null_error(ft_calloc(sizeof(char *), MAX_X + 1), 2);
		i++;
	}
	i = 0;
	while (i < MAX_Y)
	{
		ft_memset(map->outer_wall[i], ' ', MAX_X);
		if (i == 0 || i == MAX_Y - 1)
			ft_memset(map->outer_wall[i],'X',MAX_X);
		else
		{
			ft_memset(map->outer_wall[i], 'X', 1);
			ft_memset(map->outer_wall[i] + MAX_X, 'X', 1);
		}
		i++;
	}
}
