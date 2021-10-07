/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:38:03 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/07 16:08:29 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_texture_path(void)
{
	char	**path;
	int	i;

	i = 0;
	path = ft_calloc(5, sizeof(char **));
	if (path == NULL)
		systemcall_error("Error\nSo_long", 2);
	while (i <= DOOR_3)
	{
		if (i == PLAYER_0)
			path[i] = ft_strdup("./texture/player.xpm");
		if (i == ITEM_1)
			path[i] = ft_strdup("./texture/item.xpm");
		if (i == WALL_2)
			path[i] = ft_strdup("./texture/wall.xpm");
		if (i == DOOR_3)
			path[i] = ft_strdup("./texture/door.xpm");
		i++;
	}
	return (path);
}
