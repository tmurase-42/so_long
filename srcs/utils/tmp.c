/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:36:12 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/09 14:11:14 by tmurase          ###   ########.fr       */
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
	printf("map->postion[X] [%d]\n", map->postion[X]);
	printf("map->postion[Y] [%d]\n", map->postion[Y]);
}


void	test_printf_items(t_mlx *mlx)
{
	int *test;
	t_list *tmp = NULL;
	while(tmp)
	{
		test = (int *)tmp->content;
		printf("items x [%d]\n", test[X]);
		printf("items y [%d]\n", test[Y]);
		tmp = mlx->item_list->next;
	}
	while(tmp)
	{
		test = (int *)tmp->content;
		printf("door x  [%d]\n", test[X]);
		printf("door y  [%d]\n", test[Y]);
		tmp = mlx->door_list->next;
	}
}
