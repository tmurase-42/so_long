/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:41:42 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 15:36:31 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	import_mapfile(char *mapfile, t_map *map)
{
	int	fd;
	int	next;
	char	*line;
	char	*tmp;
	char	*mapline;
	char	*copy_mapline;

	line = NULL;
	next = 1;
	mapline = NULL;
	copy_mapline = NULL;
	fd = catch_error(open(mapfile, O_RDONLY, O_DIRECTORY), 2);
	while (next)
	{
		next = 	catch_error(get_next_line(fd, &line), 2);
		tmp = ft_strjoin(line, "|");
		if (mapline == NULL)
			mapline = ft_strdup(tmp);
		else
		{
			copy_mapline = ft_strdup(mapline);
			free(mapline);
			mapline = ft_strjoin(copy_mapline, tmp);
		}
		free_pointer(line, tmp, copy_mapline);
	}
	map->maps = ft_split(mapline, '|');
	free(mapline);
}


int	main(int argc, char *argv[])
{
	t_map	map;
	//引数が存在するかどうかのチェック
	if (argc < 2 || argc > 2)
		map_error(1);
	init_struct(&map);
	import_mapfile(argv[1], &map);
	//check_mapfile(&map);
	test_print_map(&map);
	system("leaks so_long");
	exit(0);
	// mapのエラーチェック関数の作成

}
