/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:42:14 by hle-roi           #+#    #+#             */
/*   Updated: 2024/02/01 10:16:56 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_win(t_manager *manager)
{
	mlx_destroy_window(manager->mlx, manager->window);
	free(manager->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_manager	manager;

	if (init_manager(&manager, argc, argv))
	{
		mlx_hook(manager.window, 2, 1L << 0, move, &manager);
		mlx_hook(manager.window, 17, 0, close_win, &manager);
		display_map(manager);
		mlx_loop(manager.mlx);
	}
}
