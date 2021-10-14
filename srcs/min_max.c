/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 02:52:01 by tdofuku           #+#    #+#             */
/*   Updated: 2021/10/14 13:33:34 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

t_bool	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
