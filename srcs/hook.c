/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:17:47 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/08 17:34:32 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *mlx)
{
	system("leaks so_long");
	//mlx_destroy_window(mlx->mlx, mlx->window);
	exit(2);
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
