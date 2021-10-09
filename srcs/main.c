/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:41:42 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/08 17:33:06 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	loop_function(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

void	so_long(t_mlx *mlx)
{
	//mlxのループ

	//色塗り
	//テクスチャの貼り付け
	//移動
	//閉じる処理
	mlx->window = mlx_new_window(mlx->mlx, 1000, 1000, "so_long");
	mlx_loop_hook(mlx->mlx, &loop_function, mlx);
	mlx_hook(mlx->window, X_EVENT_KEY_PRESS, (1L << 2), &key_press, &mlx);
	mlx_hook(mlx->window, X_EVENT_KEY_EXIT, (1L << 17), &close_window, &mlx);
	mlx_loop(mlx->mlx);
	//mlx_destroy_window(mlx->mlx, mlx->window);

}

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
	mlx.img.img = mlx_new_image(mlx.mlx, 1000, 1000);
	//texture読み込み関数
	import_texture(&map, &mlx);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	test_print_map(&map);
	so_long(&mlx);
	system("leaks so_long");
	exit(0);
	// mapのエラーチェック関数の作成
}
