/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:48:34 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/05 20:27:57 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "leaks.h"

#if LEAKS

void	end(void)
{
	system("leaks leaks_so_long");
}

#endif
