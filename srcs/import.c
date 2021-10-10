/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:55:20 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/10 19:43:51 by tmurase          ###   ########.fr       */
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

void	load_image(t_mlx *mlx, t_img *img, char *filepath)
{
	img->img = mlx_xpm_file_to_image(mlx->mlx,filepath,  &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	if (img->bpp == 0)
		systemcall_error("Error\nso_long", 2);
	if (img->img_height > 2000 || img->img_width > 2000)
		map_error(5);
}

void	import_texture(t_map *map, t_mlx *mlx)
{
	catch_error(open("./texture/player.xpm", O_RDONLY, O_DIRECTORY), 2);
	catch_error(open("./texture/door.xpm", O_RDONLY, O_DIRECTORY), 2);
	catch_error(open("./texture/item.xpm", O_RDONLY, O_DIRECTORY), 2);
	catch_error(open("./texture/wall.xpm", O_RDONLY, O_DIRECTORY), 2);
	load_image(mlx, &mlx->player,"./texture/player.xpm");
	load_image(mlx, &mlx->door, "./texture/door.xpm");
	load_image(mlx, &mlx->item, "./texture/item.xpm");
	load_image(mlx, &mlx->wall, "./texture/wall.xpm");

	//while (mlx->player.data != NULL)
	//	printf("mlx->palyer [%p]\n", mlx->player.data++);
	(void)map;
}
