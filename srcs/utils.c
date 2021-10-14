/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:49:17 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/09 19:10:17 by tmurase          ###   ########.fr       */
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

void	free_double_pointer(char **arg1)
{
	int i;

	i = 0;
	if (arg1)
	{
		while (arg1[i])
		{
			free(arg1[i]);
			i++;
		}
		free(arg1);
	}
}

void	free_struct(t_list *list)
{
	while(list)
	{
		free(list->content);
		free(list);
		list = list->next;
	}
}
