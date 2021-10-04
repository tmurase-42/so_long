/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:41:42 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/04 19:43:13 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	import_mapfile(char *mapfile, t_map *map)
{
	int	fd;

	fd = catch_error(open(mapfile, O_RDONLY, O_DIRECTORY ) , 2);
	(void)map;
}


int	main(int argc, char *argv[])
{
	t_map	*map;
	//引数が存在するかどうかのチェック
	map = NULL;
	if (argc < 2 || argc > 2)
		map_error(1);
	init_struct(map);
	import_mapfile(argv[1], map);
	// 引数のマップファイルの情報を取込むする関数


	//引数のファイル形式が妥当かどうかのチェック
	(void)argc;
	(void)argv;
}
