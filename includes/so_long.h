/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:50:49 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/04 19:35:42 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_map	t_map;

struct	s_map
{
	char	**map;
};

void	map_error(int	num);
void	import_mapfile(char *mapfile, t_map *map);
int	catch_error(int	num,	int	error_num);
void	systemcall_error(char *str, int num);
void	init_struct(t_map	*map);

#endif
