/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:29:54 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 18:34:05 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_map	*map)
{
	map->i = 0;
	map->maps = NULL;
	map->outer_wall = NULL;
	map->composition = ft_calloc(sizeof(t_composed_char),1);
	map->composition->collectible = 0;
	map->composition->exit_door = 0;
	map->composition->start_point = 0;
}
