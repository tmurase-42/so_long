/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:41:42 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/05 12:54:23 by tmurase          ###   ########.fr       */
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

	line = NULL;
	next = 1;
	mapline = NULL;
	fd = catch_error(open(mapfile, O_RDONLY, O_DIRECTORY ) , 2);
	while (next)
	{
		next = 	catch_error(get_next_line(fd, &line), 2);
		tmp = ft_strjoin(line, "|");
		if (mapline == NULL)
			mapline = ft_strdup(tmp);
		else
			mapline = ft_strjoin(mapline, tmp);
		free(line);
		free(tmp);
	}
		map->maps  = ft_split(mapline, '|');

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


	//引数のファイル形式が妥当かどうかのチェック
	(void)argc;
	(void)argv;
}
