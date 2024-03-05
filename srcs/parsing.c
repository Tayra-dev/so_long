/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:51 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/05 12:25:36 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	get_player_y(t_manager manager)
{
	int	x;
	int	y;

	y = 0;
	while (manager.map[y])
	{
		x = 0;
		while (manager.map[y][x])
		{
			if (manager.map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}

int	get_player_x(t_manager manager)
{
	int	x;
	int	y;

	y = 0;
	while (manager.map[y])
	{
		x = 0;
		while (manager.map[y][x])
		{
			if (manager.map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

char	**array_join(char **array, char *str)
{
	int		i;
	int		k;
	char	**new_array;

	i = 0;
	while (array[i])
		i++;
	new_array = malloc((i + 2) * sizeof(char *));
	if (!new_array)
		return (NULL);
	k = 0;
	while (k < i)
	{
		new_array[k] = array[k];
		k++;
	}
	new_array[k] = str;
	new_array[k + 1] = 0;
	free(array);
	return (new_array);
}

char	**read_map(int fd, char **map)
{
	char	*str;

	map = malloc(1 * sizeof(char *));
	if (!map)
		return (map);
	map[0] = NULL;
	str = get_next_line(fd);
	while (str)
	{
		map = array_join(map, str);
		str = get_next_line(fd);
	}
	free(str);
	return (map);
}
