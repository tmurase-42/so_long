/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:38:40 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/11 17:21:23 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_in_map(t_map *map, int pos_x, int pos_y)
{
	if (map->maps[pos_y][pos_x] != '1')
	{
		return (TRUE);
	}
	return (FALSE);
}

void	move_player(t_mlx *mlx, int pos_x, int pos_y)
{
	t_bool	is_in_wall;
	t_bool	is_door;

	is_door = FALSE;
	if (mlx->map->maps[pos_y][pos_x] == 'E')
		is_door = TRUE;
	is_in_wall = check_in_map(mlx->map, pos_x, pos_y);
	if (is_in_wall)
	{
		mlx->map->maps[mlx->map->postion[Y]][mlx->map->postion[X]] = '0';
		mlx->map->maps[pos_y][pos_x] = 'P';
		mlx->map->postion[X] = pos_x;
		mlx->map->postion[Y] = pos_y;
		draw_so_long(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0 , 0);
		if (is_door)
			close_window(mlx);
	}
}

void	action_cace(t_mlx *mlx, int key)
{
	int	current_position[2];

	current_position[X] = mlx->map->postion[X];
	current_position[Y] = mlx->map->postion[Y];
	if (key == K_A)
		current_position[X] = current_position[X] - 1;
	else if (key == K_D)
		current_position[X] = current_position[X] + 1;
	else if (key == K_W)
		current_position[Y] = current_position[Y] - 1;
	else if (key == K_S)
		current_position[Y] = current_position[Y] + 1;
	move_player(mlx, current_position[X], current_position[Y]);
}
