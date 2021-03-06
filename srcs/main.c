/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:41:42 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/19 18:29:40 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_so_long(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		systemcall_error("Error\nso_long", 2);
	get_window_size(mlx);
	mlx->img.img = mlx_new_image(mlx->mlx,
			mlx->window_size[X], mlx->window_size[Y]);
	mlx->window = mlx_new_window(mlx->mlx,
			mlx->window_size[X], mlx->window_size[Y], "so_long");
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img,
			&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	import_texture(mlx->map, mlx);
}

int	draw(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
	return (0);
}

void	so_long(t_mlx *mlx)
{
	initialize_so_long(mlx);
	draw_so_long(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
	mlx_key_hook(mlx->window, key_press, mlx);
	mlx_expose_hook(mlx->window, draw, mlx);
	ft_putstr_fd("move count: 0", 1);
	mlx_hook(mlx->window, X_EVENT_KEY_EXIT, (1L << 17), &close_window, &mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		map_error(1);
	init_struct(&map, &mlx);
	import_mapfile(argv[1], &map);
	check_mapfile(&mlx);
	so_long(&mlx);
}
