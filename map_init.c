/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:49 by darikan           #+#    #+#             */
/*   Updated: 2024/05/08 18:16:49 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_xpm(t_map *game)
{
	int	x;
	int	y;

	game->exit_img = mlx_xpm_file_to_image(game->mlx, \
					"./textures/goat.xpm", &x, &y);
	game->coinimg = mlx_xpm_file_to_image(game->mlx, \
					"./textures/crown.xpm", &x, &y);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, \
					"./textures/wall.xpm", &x, &y);
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
					"./textures/lebron.xpm", &x, &y);
	game->background_img = mlx_xpm_file_to_image(game->mlx, \
					"./textures/back.xpm", &x, &y);
	if (!game->background_img || !game->coinimg || !game->exit_img || \
		!game->player_img || !game->wall_img)
		return (1);
	return (0);
}

int	put_image(t_map *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map_line[y][x])
	{
		if (game->map_line[y] && game->map_line[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		if (game->map_line[y][x] == 'E')
			put_image_extra(game, game->exit_img, x, y);
		if (game->map_line[y][x] == 'C')
			put_image_extra(game, game->coinimg, x, y);
		if (game->map_line[y][x] == 'P')
			put_image_extra(game, game->player_img, game->px, game->py);
		if (game->map_line[y][x] == '0')
			put_image_extra(game, game->background_img, x, y);
		if (game->map_line[y][x] == '1')
			put_image_extra(game, game->wall_img, x, y);
		x++;
	}
	return (0);
}

void	put_image_extra(t_map *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, 64 * x, 64 * y);
}

int	ft_move(int key, t_map *game)
{
	int		x;
	int		y;
	char	*move;

	x = game->px;
	y = game->py;
	if (key == 13)
		y--;
	else if (key == 1)
		y++;
	else if (key == 2)
		x++;
	else if (key == 0)
		x--;
	else if (key == 53)
		safe_exit(game);
	else
		return (0);
	mlx_clear_window(game->mlx, game->mlx_win);
	map_move(game, x, y);
	put_image(game);
	move = ft_itoa(game->playermove);
	mlx_string_put(game->mlx, game->mlx_win, 15, 15, 16777215, move);
	free(move);
	return (0);
}

void	map_move(t_map *game, int x, int y)
{
	if (game->map_line[y][x] != '1' && game->map_line[y][x] != 'E')
	{
		ft_printf("Move Count: %d\n", ++game->playermove);
		if (game->map_line[y][x] == 'C')
			game->coin_count--;
		game->map_line[game->py][game->px] = '0';
		game->map_line[y][x] = 'P';
		game->py = y;
		game->px = x;
	}
	else if (game->map_line[y][x] == 'E' && game->coin_count == 0)
	{
		ft_printf("Move Count: %d\n", ++game->playermove);
		safe_exit(game);
	}
}
