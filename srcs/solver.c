/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:26:47 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/05 11:32:40 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	solver(t_manager *manager, int y, int x)
{
	if (manager->testmap[y][x] == 'E')
	{
		(manager->test_exit)++;
		manager->testmap[y][x] = '1';
	}
	if (manager->testmap[y][x] == 'C')
	{
		(manager->test_item)++;
		manager->testmap[y][x] = '1';
	}
	if (manager->total_items <= manager->test_item && manager->test_exit == 1)
		return ;
	manager->testmap[y][x] = '1';
	if (manager->testmap[y + 1][x] != '1')
		solver(manager, y + 1, x);
	if (manager->testmap[y][x + 1] != '1')
		solver(manager, y, x + 1);
	if (manager->testmap[y - 1][x] != '1')
		solver(manager, y - 1, x);
	if (manager->testmap[y][x - 1] != '1')
		solver(manager, y, x - 1);
}
