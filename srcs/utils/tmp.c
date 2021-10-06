/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:36:12 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 16:35:00 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_print_map(t_map *map)
{
	char **tmp = map->maps;
	while (*tmp)
	{
		printf("maps[%s]\n", *tmp);
		tmp++;
	}
	printf("map->composition->collectible [%d]\n", map->composition->collectible);
	printf("map->composition->exit_door [%d]\n", map->composition->exit_door);
	printf("map->composition->start_point [%d]\n", map->composition->start_point);
}
