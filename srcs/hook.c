/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:17:47 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/14 14:32:03 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *mlx)
{
	system("leaks so_long");
	exit(0);
	(void)mlx;
	return (0);
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		close_window(mlx);
	if (key == K_S || key == K_W || key == K_A || key == K_D)
		action_cace(mlx, key);
	return (0);
}

int	move_count(t_mlx *mlx)
{
	ft_putstr_fd("                                  \r", 1);
	ft_putstr_fd("move count: ", 1);
	ft_putnbr_fd(++mlx->move_count, 1);
	return (0);
}
