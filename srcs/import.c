/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:55:20 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/07 16:47:04 by tmurase          ###   ########.fr       */
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
	img->img = mlx_xpm_file_to_image(mlx->mlx,filepath,  &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	if (img->bpp == 0)
		systemcall_error("Error\nso_long", 2);
//	printf("img->bpp [%d]\n", img->bpp);
//	printf("img->size_l [%d]\n", img->size_l);
//	printf("img->endian [%d]\n", img->endian);
//	printf("img->width [%d]\n", img->img_width);
//	printf("img->img_height [%d]\n", img->img_height);

	if (img->img_height > 2000 || img->img_width > 2000)
		map_error(5);
//	if (img->img_width != img->img_height)
//		map_error(6);
	mlx->texture[i] = (int *)ft_calloc(sizeof(int), (img->img_height * img->img_width));

	(void)i;
}
static void	save_image(t_mlx *mlx, int i, t_img *img)
{
	int	x;
	int	y;
	int	k;

	k = 0;
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (img->img_width > x)
		{
			mlx->texture[i][img->img_width * y + x] = img->data[k];
			x++;
			k++;
		}
		x = 0;
		while (x < (img->size_l - (img->img_width * 4)) / 4)
		{
			x++;
			k++;
		}
		y++;
	}
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

	while (i <= DOOR_3)
	{
		load_image(mlx, &img, i, filepath[i]);
		save_image(mlx, i, &img);
		mlx_destroy_image(mlx->mlx, img.img);
		i++;
	}
	free_double_pointer(filepath);

	(void)map;
}
