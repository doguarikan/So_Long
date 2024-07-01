/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:41 by darikan           #+#    #+#             */
/*   Updated: 2024/05/08 18:16:41 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	void	*player_img;
	void	*wall_img;
	void	*exit_img;
	void	*background_img;
	void	*coinimg;
	char	**map_line;
	int		px;
	int		py;
	int		exit_count;
	int		player_count;
	int		coin_count;
	int		playermove;
	int		map_x_line;
	int		map_y_line;
	char	*f_name;
	void	*mlx;
	void	*mlx_win;
}				t_map;

int		ber_checker(int argc, char *argv);
int		read_chars(t_map *map, char *f_name);
int		map_read_check(t_map *map, char *f_name);
void	read_map(t_map *map, char *f_name);
int		map_checker(t_map *map);
int		check_shape(t_map *map);
void	char_control(t_map *map, int x, int y);
int		char_count(t_map *map);
int		wall_check(t_map *map);
int		wall_first_end(t_map *map, int y);
int		wall_middle(t_map *map, int y);
int		char_checker(t_map *map);
void	free_map(t_map *map);
void	player_movable(t_map *map, int y, int x);
int		is_reachable(t_map *map);
int		coin_check(t_map *map);
int		exit_check(t_map *map);
int		map_init(t_map *map, char	*argc);
int		create_xpm(t_map *map);
int		put_image(t_map *map);
void	put_image_extra(t_map *map, void *img, int x, int y);
int		safe_exit(t_map *map);
int		ft_move(int key, t_map *map);
void	map_move(t_map *map, int x, int y);

#endif
