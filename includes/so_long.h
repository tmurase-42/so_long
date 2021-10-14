/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:50:49 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/14 13:08:11 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "get_next_line.h"
#include "key_macros.h"
#include "leaks.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define BUFFER_SIZE 1000
# define MAX_X 100
# define MAX_Y 100

# if defined(__linux__)
# define OS_TYPE 0
# else
# define OS_TYPE 1
# endif
typedef struct	s_map	t_map;
typedef struct s_mlx	t_mlx;
typedef struct s_texture	t_texture;
typedef struct s_composed_char t_composed_char;
typedef	enum	e_pos	t_pos;
typedef enum	e_tex	t_tex;
typedef enum	e_os	t_os;

struct s_composed_char
{
	int collectible;
	int exit_door;
	int start_point;
};

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

struct s_mlx
{
	void	*mlx;
	void	*window;
	int		window_size[2];
	int		os_window_size[2];
	int		tex_piece_length;
	t_img	img;
	t_img	player;
	t_img	door;
	t_img	item;
	t_img	wall;
	t_map	*map;
	t_list *item_list;
	t_list *door_list;
};

struct	s_map
{
	int i;
	int	postion[2];
	char	**maps;
	char	**outer_wall;
	t_composed_char *composition;
};

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

enum e_pos
{
	X,
	Y
};

enum e_os
{
	LINUX,
	APPLE
};

typedef enum e_tex
{
	PLAYER_0,
	ITEM_1,
	WALL_2,
	DOOR_3
}	t_tex;

void	map_error(int	num);
void	import_mapfile(char *mapfile, t_map *map);
int		catch_error(int	num,	int	error_num);
void	systemcall_error(char *str, int num);
void	init_struct(t_map	*map, t_mlx *mlx);
void	free_pointer(void *arg1, void *arg2, void *arg3);
void	free_double_pointer(char **arg1);
void	free_struct(t_list *list);
void	check_mapfile(t_mlx *mlx);
t_bool	so_long_strchr(t_map *map);
char	*null_error(char *str, int error_num);
void	init_outer_wall(t_map *map);
void	flood_fill(int x, int y, t_map *map, int *status);
void	get_start_position(t_map *map);
void	import_texture(t_map *map, t_mlx *mlx);
char	**get_texture_path(void);
int		close_window(t_mlx *mlx);
int		key_press(int key, t_mlx *mlx);
void	get_position(t_mlx *mlx);
void	get_items_position(t_mlx *mlx);
void	get_window_size(t_mlx *mlx);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_so_long(t_mlx *mlx);
//int		get_texture_pixel_color(t_img *tex, t_mlx *mlx, int x, int y);
char		*get_texture_pixel_color(t_img *tex, t_mlx *mlx, int x, int y);
void		action_cace(t_mlx *mlx, int key);
void		initialize_so_long(t_mlx *mlx);




//tmp
void	test_print_map(t_map *map);
void	test_printf_items(t_mlx *mlx);

#endif
