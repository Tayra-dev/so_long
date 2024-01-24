/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:06:06 by hle-roi           #+#    #+#             */
/*   Updated: 2024/01/24 16:15:49 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	move_player_pos(t_manager *manager, int x, int y)
{
	if (manager->map[y][x] != '1')
	{
		if (manager->map[y][x] == 'C')
			manager->items++;
		if (manager->map[y][x] == 'E' && manager->items == manager->total_items)
			close_win(manager);
		manager->map[y][x] = 'P';
		manager->map[manager->player_y][manager->player_x] = '0';
		manager->player_x = x;
		manager->player_y = y;
	}
}

int	move(int keycode, t_manager *manager)
{
	int	x;
	int	y;

	x = manager->player_x;
	y = manager->player_y;
	if (keycode == 13)
		move_player_pos(manager, x, y - 1);
	if (keycode == 0)
		move_player_pos(manager, x - 1, y);
	if (keycode == 2)
		move_player_pos(manager, x + 1, y);
	if (keycode == 1)
		move_player_pos(manager, x, y + 1);
	if (keycode == 53)
		close_win(manager);
	manager->moves++;
	printf("%d moves", manager->moves);
	display_map(*manager);
	return (0);
}
