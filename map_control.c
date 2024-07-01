/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:51 by darikan           #+#    #+#             */
/*   Updated: 2024/05/08 18:16:51 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	is_reachable(t_map *game)
{
	player_movable(game, game->py, game->px);
	if (coin_check(game) || exit_check(game))
		return (1);
	return (0);
}

void	player_movable(t_map *game, int y, int x)
{
	if (game->map_line[y][x + 1] == '0' || game->map_line[y][x + 1] == 'C')
	{
		game->map_line[y][x + 1] = 'P';
		player_movable(game, y, x + 1);
	}
	if (game->map_line[y][x - 1] == '0' || game->map_line[y][x - 1] == 'C')
	{
		game->map_line[y][x - 1] = 'P';
		player_movable(game, y, x - 1);
	}
	if (game->map_line[y + 1][x] == '0' || game->map_line[y + 1][x] == 'C')
	{
		game->map_line[y + 1][x] = 'P';
		player_movable(game, y + 1, x);
	}
	if (game->map_line[y - 1][x] == '0' || game->map_line[y - 1][x] == 'C')
	{
		game->map_line[y - 1][x] = 'P';
		player_movable(game, y - 1, x);
	}
}

int	coin_check(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_line[y])
	{
		x = 0;
		while (game->map_line[y][x] != 0 && game->map_line[y][x] != '\n')
		{
			if (game->map_line[y][x] == 'C')
			{
				ft_printf("Error : Player can't reach the collectible");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_check(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_line[y] != 0)
	{
		x = 0;
		while (game->map_line[y][x] != '\n')
		{
			if (game->map_line[y][x] == 'E')
				break ;
			x++;
		}
		if (game->map_line[y][x] == 'E')
			break ;
		y++;
	}
	if (game->map_line[y][x + 1] == 'P' || game->map_line[y][x - 1] == 'P' || \
			game->map_line[y + 1][x] == 'P' || game->map_line[y - 1][x] == 'P')
		return (0);
	ft_printf("Error : Player can't reach the exit\n");
	return (1);
}
