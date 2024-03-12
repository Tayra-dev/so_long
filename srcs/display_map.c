/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:22:05 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/12 17:39:13 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	setexit(void *mlx, void *window, int x, int y)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	img = NULL;
	relative_path = "./textures/tiles/exit.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		return (-1);
	mlx_put_image_to_window(mlx, window, img,
		(x * (WIDTH / 2)) - y * (WIDTH / 2) + OFFSET,
		((y * WIDTH) + (x * WIDTH / 4)) - y * (WIDTH / 1.33) + OFFSET);
	mlx_destroy_image(mlx, img);
	return (0);
}

int	setwall(void *mlx, void *window, int x, int y)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	img = NULL;
	relative_path = "./textures/tiles/wall.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		return (-1);
	mlx_put_image_to_window(mlx, window, img,
		(x * (WIDTH / 2)) - y * (WIDTH / 2) + OFFSET,
		((y * WIDTH) + (x * WIDTH / 4)) - y * (WIDTH / 1.33) + OFFSET);
	mlx_destroy_image(mlx, img);
	return (0);
}

int	setpath(void *mlx, void *window, int x, int y)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	img = NULL;
	relative_path = "./textures/tiles/path.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		return (-1);
	mlx_put_image_to_window(mlx, window, img,
		(x * (WIDTH / 2)) - y * (WIDTH / 2) + OFFSET,
		((y * WIDTH) + (x * WIDTH / 4)) - y * (WIDTH / 1.33) + OFFSET);
	mlx_destroy_image(mlx, img);
	return (0);
}

int	setitem(void *mlx, void *window, int x, int y)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	img = NULL;
	relative_path = "./textures/items/item.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		return (-1);
	mlx_put_image_to_window(mlx, window, img,
		(x * (WIDTH / 2)) - y * (WIDTH / 2) + OFFSET,
		((y * WIDTH) + (x * WIDTH / 4)) - y * (WIDTH / 1.33) + OFFSET - 10);
	mlx_destroy_image(mlx, img);
	return (0);
}

void	display_map(t_manager manager)
{
	int	x;
	int	y;

	y = -1;
	while (manager.map[++y])
	{
		x = -1;
		while (manager.map[y][++x])
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
		}
	}
}
