/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:42:34 by hle-roi           #+#    #+#             */
/*   Updated: 2024/01/24 16:15:35 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_manager
{
	void	*mlx;
	void	*window;
	char	**map;
	int		moves;
	int		items;
	int		total_items;
	int		player_x;
	int		player_y;
}	t_manager;

# define WALL 1
# define PATH 0
# define WIDTH 32

void	display_map(t_manager manager);
int		init_manager(t_manager *manager, int argc, char **argv);
char	*get_next_line(int fd);
int		read_map(int fd, t_manager *manager);
int		move(int keycode, t_manager *manager);
int		close_win(t_manager *manager);

#endif