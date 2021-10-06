/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:10:49 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/06 17:08:01 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(int	num)
{
	ft_putstr_fd("Error\n", 2);
	if (num == 1)
		ft_putstr_fd("Number of arguments is invalid\n", 2);
	if (num == 2)
		ft_putstr_fd("map information has an invalid value\n", 2);
	if (num == 3)
		ft_putstr_fd("too many or too few compositions\n", 2);
	system("leaks so_long");
	exit(2);
}

void	systemcall_error(char *str, int num)
{
	perror(str);
	exit(num);
}

int	catch_error(int	num,	int	error_num)
{
	if (num == -1)
		systemcall_error("Error\nso_long", error_num);
	return (num);
}

char	*null_error(char *str, int error_num)
{
	if (str == NULL)
		systemcall_error("Error\n", error_num);
	return (str);
}
