/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:15 by hle-roi           #+#    #+#             */
/*   Updated: 2024/01/24 11:49:30 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	get_max_items(t_manager manager)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (manager.map[y])
	{
		x = 0;
		while (manager.map[y][x])
		{
			if (manager.map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	init_manager(t_manager *manager, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (0);
	manager->mlx = mlx_init();
	manager->window = mlx_new_window(manager->mlx, 1920, 1080, "So Long");
	fd = open(argv[1], O_RDONLY);
	read_map(fd, manager);
	manager->items = 0;
	manager->moves = 0;
	manager->total_items = get_max_items(*manager);
	return (1);
}
