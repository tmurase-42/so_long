/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:50:49 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 18:13:21 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "get_next_line.h"
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
typedef struct s_composed_char t_composed_char;


struct s_composed_char
{
	int collectible;
	int exit_door;
	int start_point;
};

struct	s_map
{
	int i;
	char	**maps;
	char	**outer_wall;
	t_composed_char *composition;
};

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;


void	map_error(int	num);
void	import_mapfile(char *mapfile, t_map *map);
int	catch_error(int	num,	int	error_num);
void	systemcall_error(char *str, int num);
void	init_struct(t_map	*map);
void	free_pointer(void *arg1, void *arg2, void *arg3);
void	free_double_pointer(char **arg1, char **arg2, char **arg3);
void	check_mapfile(t_map *map);
t_bool	so_long_strchr(t_map *map);
char	*null_error(char *str, int error_num);
void	init_outer_wall(t_map *map);




//tmp

void	test_print_map(t_map *map);

#endif
