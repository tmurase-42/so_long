/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:16:09 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 11:22:17 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(void *arg1, void *arg2)
{
	printf("size arg1 [%lu]\n", sizeof(arg1));
	printf("size arg2[%lu]\n", sizeof(arg2));
	free(arg1);
	free(arg2);
}
