/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:22:05 by hle-roi           #+#    #+#             */
/*   Updated: 2024/01/24 13:16:14 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	setexit(void *mlx, void *window, int x, int y)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/tiles/exit.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, window, img,
		(x * (WIDTH / 2)) - y * (WIDTH / 2) + 500,
		((y * WIDTH) + (x * WIDTH / 4)) - y * (WIDTH / 1.4) + 500);
}

void	setwall(void *mlx, void *window, int x, int y)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/tiles/wall.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, window, img, 
		(x * (WIDTH / 2)) - y * (WIDTH / 2) + 500,
		((y * WIDTH) + (x * WIDTH / 4)) - y * (WIDTH / 1.4) + 500);
}

void	setpath(void *mlx, void *window, int x, int y)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/tiles/path.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, window, img,
		(x * (WIDTH / 2)) - y * (WIDTH / 2) + 500,
		((y * WIDTH) + (x * WIDTH / 4)) - y * (WIDTH / 1.4) + 500);
}

void	setitem(void *mlx, void *window, int x, int y)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/items/item.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, window, img,
		(x * (WIDTH / 2)) - y * (WIDTH / 2) + 500,
		((y * WIDTH) + (x * WIDTH / 4)) - y * (WIDTH / 1.3) + 500);
}

void	display_map(t_manager manager)
{
	int	x;
	int	y;

	y = 0;
	while (manager.map[y])
	{
		x = 0;
		while (manager.map[y][x])
		{
			if (manager.map[y][x] == '0')
				setpath(manager.mlx, manager.window, x, y);
			if (manager.map[y][x] == '1')
				setwall(manager.mlx, manager.window, x, y);
			if (manager.map[y][x] == 'E')
				setexit(manager.mlx, manager.window, x, y);
			if (manager.map[y][x] == 'P')
				setexit(manager.mlx, manager.window, x, y);
			if (manager.map[y][x] == 'C')
			{
				setpath(manager.mlx, manager.window, x, y);
				setitem(manager.mlx, manager.window, x, y);
			}
			x++;
		}
		y++;
	}
}
