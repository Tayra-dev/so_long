/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:42:14 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/11 11:24:13 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_error(int error)
{
	if (error == -1)
		ft_printf("Error\nthe elements of the map are incorrect\n");
	if (error == -2)
		ft_printf("Error\nthe map shape is not a square\n");
	if (error == -3)
		ft_printf("Error\nthe map is not surrounded by walls\n");
	if (error == -4)
		ft_printf("Error\nthe map contain wrong characters\n");
	if (error == -5)
		ft_printf("Error\nthe map can not be solved\n");
	if (error == -6)
		ft_printf("Error\nInvalid number of arguments\n");
	if (error == -7)
		ft_printf("Error\nCan't open the map\n");
	if (error == -8)
		ft_printf("Error\nCan't read the map\n");
	if (error == -9)
		ft_printf("Error\nWrong file extension\n");
	if (error == -10)
		ft_printf("Error\nThe provided map is empty\n");
	return (-1);
}

int	close_win(t_manager *manager)
{
	mlx_destroy_window(manager->mlx, manager->window);
	free(manager->mlx);
	free_map(manager->map);
	free_map(manager->testmap);
	system("leaks so_long");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_manager	manager;

	if (argc != 2)
		return (ft_error(-6));
	else
	{
		if (init_manager(&manager, argv, 0) != -1)
		{
			mlx_hook(manager.window, 2, 1L << 0, move, &manager);
			mlx_hook(manager.window, 17, 0, close_win, &manager);
			display_map(manager);
			mlx_loop(manager.mlx);
		}
		else
		{
			if (manager.mlx != 0)
				free(manager.mlx);
			if (manager.map != 0)
				free_map(manager.map);
			if (manager.testmap != 0)
				free_map(manager.testmap);
		}
	}
	system("leaks so_long");
	return (0);
}
