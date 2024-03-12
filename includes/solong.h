/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:42:34 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/11 15:08:39 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_manager
{
	void	*mlx;
	void	*window;
	char	**map;
	char	**testmap;
	int		moves;
	int		items;
	int		test_item;
	int		test_exit;
	int		total_items;
	int		player_x;
	int		player_y;
	char	keep;
}	t_manager;

# define WALL 1
# define PATH 0
# define WIDTH 32
# define OFFSET 400

void	display_map(t_manager manager);
int		init_manager(t_manager *manager, char **argv, int fd);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
char	**read_map(int fd, char **map);
int		move(int keycode, t_manager *manager);
int		close_win(t_manager *manager);
int		test_map(t_manager *manager);
int		get_player_x(t_manager manager);
int		get_player_y(t_manager manager);
int		get_max_items(t_manager manager);
void	free_map(char **map);

int		test_shape(t_manager manager);
int		test_walls(t_manager manager);
int		test_elts(t_manager manager, int y);

void	solver(t_manager *manager, int y, int x);

int		setpath(void *mlx, void *window, int x, int y);
int		setexit(void *mlx, void *window, int x, int y);

int		ft_error(int error);

#endif