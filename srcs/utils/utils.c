/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:49:17 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 14:55:39 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pointer(void *arg1, void *arg2, void *arg3)
{
	if (arg1)
		free(arg1);
	if (arg2)
		free(arg2);
	if (arg3)
		free(arg3);
}

void	free_double_pointer(char **arg1, char **arg2, char **arg3)
{
	if (arg1)
	{
		while (*arg1)
		{
			free(arg1);
			arg1++;
		}
		free(arg1);
	}
	if (arg2)
	{
		while (*arg2)
		{
			free(arg2);
			arg2++;
		}
		free(arg2);
	}
	if (arg3)
	{
		while (*arg3)
		{
			free(arg3);
			arg3++;
		}
		free(arg3);
	}
}
