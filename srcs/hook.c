/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:17:47 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/09 14:13:09 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *mlx)
{


	//free_struct(mlx->item_list);
	//free_struct(mlx->door_list);
	system("leaks so_long");
	//mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
	(void)mlx;
	return (0);
}

static void	ESC_case(void)
{
	system("leaks so_long");
	exit(0);
}
int	key_press(int key, t_mlx *mlx)
{

	if (key == K_ESC)
		ESC_case();
	(void)mlx;
	return (0);
}
