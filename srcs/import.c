/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:55:20 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/07 16:02:32 by tmurase          ###   ########.fr       */
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

void	load_image(t_mlx *mlx, t_img *img, int i, char *filepath)
{
	if(!(img->img = mlx_xpm_file_to_image(mlx->mlx,filepath,  &img->img_width, &img->img_height)))
		systemcall_error("Error\nso_long", 2);
	(void)i;
}


void	import_texture(t_map *map, t_mlx *mlx)
{
	t_img img;
	char	**filepath;
	int		i;

	i = 0;
	catch_error(open("./texture/player.xpm", O_RDONLY, O_DIRECTORY), 2);
	catch_error(open("./texture/door.xpm", O_RDONLY, O_DIRECTORY), 2);
	catch_error(open("./texture/item.xpm", O_RDONLY, O_DIRECTORY), 2);
	catch_error(open("./texture/wall.xpm", O_RDONLY, O_DIRECTORY), 2);
	mlx->texture = ft_calloc(sizeof(int **), 4);
	filepath = get_texture_path();

	i = 0;
	while (i <= DOOR_3)
	{
		printf("filepath [%s]\n", filepath[i]);
		i++;
	}
	while (i < DOOR_3)
	{
		load_image(mlx, &img, i, filepath[i]);
		i++;
	}
	free_double_pointer(filepath);

	(void)map;
}
