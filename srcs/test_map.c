/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:09 by hle-roi           #+#    #+#             */
/*   Updated: 2024/01/24 16:18:43 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	test_comp(t_manager manager)
{
	int	y;
	int	x;

	y = 0;
	while (manager.map[y])
	{
		x = 0;
		while (manager.map[y][x])
		{
			if (manager.map[y][x] != 'E' && manager.map[y][x] != 'P'
				&& manager.map[y][x] != 'C' && manager.map[y][x] != '1'
					&& manager.map[y][x] != '0')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	test_map(t_manager manager)
{
	if (test_shape(manager))
		return (-2);
	if (test_elts(manager, 0))
		return (-1);
	if (test_walls(manager))
		return (-3);
	if (test_comp(manager))
		return (-4);
	return (0);
}
