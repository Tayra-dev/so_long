/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:15 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/05 12:46:10 by hle-roi          ###   ########.fr       */
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

int	test_ext(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e'
		|| str[i - 2] != 'b' || str[i - 3] != '.')
		return (-1);
	return (0);
}

void	pre_init(t_manager *manager)
{
	manager->mlx = 0;
	manager->map = 0;
	manager->testmap = 0;
	manager->items = 0;
	manager->moves = 0;
	manager->keep = '0';
}

int	init_manager(t_manager *manager, char **argv, int fd)
{
	pre_init(manager);
	if (test_ext(argv[1]) == -1)
		return (ft_error(-9));
	manager->mlx = mlx_init();
	if (!manager->mlx)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(-7));
	manager->map = read_map(fd, manager->map);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	manager->testmap = read_map(fd, manager->testmap);
	close(fd);
	if (!(manager->map && manager->testmap))
		return (ft_error(-8));
	manager->total_items = get_max_items(*manager);
	manager->player_x = get_player_x(*manager);
	manager->player_y = get_player_y(*manager);
	if (test_map(*manager) == -1)
		return (-1);
	manager->window = mlx_new_window(manager->mlx, 1920, 1080, "So Long");
	if (!manager->window)
		return (-1);
	return (1);
}
