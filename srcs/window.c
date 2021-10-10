/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:13:59 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/10 19:59:03 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_y_length(t_map *map)
{
	int	length;

	length = 0;
	while (map->maps[length])
		length++;
	return (length);
}

void	decesion_texture_length(t_mlx *mlx)
{
	int	texture_length[2];

	texture_length[X] = (mlx->os_window_size[X] / (ft_strlen(*mlx->map->maps)));
	texture_length[Y] = (mlx->os_window_size[Y] / get_map_y_length(mlx->map));
	if (texture_length[X] < texture_length[Y])
		texture_length[Y] = texture_length[X];
	else
	{
		texture_length[X] = texture_length[Y];
	}
	mlx->texture_piece_length = texture_length[X];
}

void	get_window_size(t_mlx *mlx)
{
	mlx_get_screen_size(mlx->mlx, &mlx->os_window_size[X], &mlx->os_window_size[Y]);
	decesion_texture_length(mlx);
	mlx->window_size[X] = mlx->texture_piece_length * (ft_strlen(*mlx->map->maps));
	mlx->window_size[Y] = mlx->texture_piece_length * (get_map_y_length(mlx->map));
}
