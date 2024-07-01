/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:46 by darikan           #+#    #+#             */
/*   Updated: 2024/05/08 18:16:46 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_shape(t_map *map)
{
	int	y;
	int	x;
	int	len;

	len = ft_strlen(map->map_line[0]);
	map->map_x_line = len;
	y = 0;
	while (y < map->map_y_line)
	{
		x = 0;
		while (map->map_line[y] && map->map_line[y][x] != '\n' && \
			x < (int)(ft_strlen(map->map_line[y])))
			x++;
		if (x != len -1)
		{
			ft_printf("Error : The map is not a rectangle!\n");
			return (1);
		}
		y++;
	}
	return (0);
}

int	read_chars(t_map *game, char *f_name)
{
	int	fd;
	int	i;

	read_map(game, f_name);
	if (!(game->map_line) || game->map_y_line <= 0)
	{
		game->map_line = NULL;
		return (1);
	}
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		free(game->map_line);
		return (1);
	}
	i = 0;
	game->map_line[i] = get_next_line(fd);
	while (game->map_line[i])
	{
		i++;
		game->map_line[i] = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void	read_map(t_map *game, char *f_name)
{
	int		len;
	int		fd;
	char	c;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		game->map_y_line = 0;
		return ;
	}
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			len++;
	}
	len++;
	close(fd);
	game->map_line = malloc(sizeof(char *) * len + 1);
	if (!game->map_line)
		return ;
	game->map_line[len + 1] = NULL;
	game->map_y_line = len;
}

void	free_map(t_map *game)
{
	int	i;

	i = 0;
	while (i < game->map_y_line)
	{
		free(game->map_line[i]);
		i++;
	}
	free(game->map_line);
}

int	safe_exit(t_map *game)
{
	mlx_destroy_image(game->mlx, game->background_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->coinimg);
	mlx_clear_window(game->mlx, game->mlx_win);
	free_map(game);
	exit(0);
	return (0);
}
