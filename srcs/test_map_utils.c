/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:39:49 by hle-roi           #+#    #+#             */
/*   Updated: 2024/02/05 11:44:36 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	get_max_y(t_manager manager)
{
	int	y;

	y = 0;
	while (manager.map[y])
		y++;
	return (y);
}

int	test_shape(t_manager manager)
{
	int	y;
	int	size;

	size = 0;
	y = 0;
	while (manager.map[y])
	{
		if (y == 0)
			size = get_length(manager.map[y]);
		else
			if (size != get_length(manager.map[y]))
				return (1);
		y++;
	}
	return (0);
}

int	test_walls(t_manager manager)
{
	int	x;
	int	max_x;
	int	max_y;

	x = 0;
	while (manager.map[0][++x] != 0)
		if (manager.map[0][x] != '1')
			return (1);
	x = 0;
	while (manager.map[++x])
		if (manager.map[x][0] != '1')
			return (1);
	x = 0;
	max_y = get_max_y(manager) - 1;
	while (manager.map[max_y][++x] != 0)
		if (manager.map[max_y][x] != '1')
			return (1);
	x = 0;
	max_x = get_length(manager.map[0]) - 1;
	while (manager.map[++x])
		if (manager.map[x][max_x] != '1')
			return (1);
	return (0);
}

int	test_elts(t_manager manager, int y)
{
	int	exit;
	int	items;
	int	start;
	int	x;

	exit = 0;
	items = 0;
	start = 0;
	while (manager.map[++y])
	{
		x = 0;
		while (manager.map[y][++x])
		{
			if (manager.map[y][x] == 'E')
				exit++;
			if (manager.map[y][x] == 'P')
				start++;
			if (manager.map[y][x] == 'C')
				items++;
		}
	}
	if (exit == 1 && items > 0 && start == 1)
		return (0);
	return (1);
}
