/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:50:49 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/09 12:11:27 by tmurase          ###   ########.fr       */
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
typedef struct	s_map	t_map;
typedef struct s_mlx	t_mlx;
typedef struct s_texture	t_texture;
typedef struct s_composed_char t_composed_char;
typedef	enum	e_pos	t_pos;
typedef enum	e_tex	t_tex;

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
	t_img	img;
	t_img	player;
	t_img	door;
	t_img	item;
	t_img	wall;
	t_map	*map;
	int	**texture;
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

typedef enum e_pos
{
	X,
	Y
}	t_postion;

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
void	check_mapfile(t_map *map);
t_bool	so_long_strchr(t_map *map);
char	*null_error(char *str, int error_num);
void	init_outer_wall(t_map *map);
void	flood_fill(int x, int y, t_map *map, int *status);
void	get_start_position(t_map *map);
void	import_texture(t_map *map, t_mlx *mlx);
char	**get_texture_path(void);
int		close_window(t_mlx *mlx);
int		key_press(int key, t_mlx *mlx);
void	get_position(t_map *map);




//tmp
void	test_print_map(t_map *map);

#endif
