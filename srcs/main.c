/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:41:42 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/07 14:55:41 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_mlx	mlx;
	//引数が存在するかどうかのチェック
	if (argc < 2 || argc > 2)
		map_error(1);
	init_struct(&map, &mlx);
	import_mapfile(argv[1], &map);
	check_mapfile(&map);

	if (!(mlx.mlx = mlx_init()))
		systemcall_error("Error\nso_long", 2);
	mlx.img.img = mlx_new_image(mlx.mlx, 100, 100);
	//texture読み込み関数
	import_texture(&map, &mlx);
	test_print_map(&map);
	system("leaks so_long");
	exit(0);
	// mapのエラーチェック関数の作成
}
