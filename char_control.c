/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:53 by darikan           #+#    #+#             */
/*   Updated: 2024/05/08 18:16:53 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_control(t_map *game, int x, int y)
{
	game->player_count = 0;
	game->exit_count = 0;
	game->coin_count = 0;
	y = 0;
	while (game->map_line[y])
	{
		x = 0;
		while (game->map_line[y][x])
		{
			if (game->map_line[y][x] == 'E')
				game->exit_count++;
			if (game->map_line[y][x] == 'C')
				game->coin_count++;
			if (game->map_line[y][x] == 'P')
			{
				game->py = y;
				game->px = x;
				game->player_count++;
			}
			x++;
		}
		y++;
	}
}

int	char_count(t_map *game)
{
	char_control(game, 0, 0);
	if (game->exit_count != 1)
	{
		ft_printf("Error : Exit count is not 1!");
		return (1);
	}
	if (game->player_count != 1)
	{
		ft_printf("Error : Player count is not 1!");
		return (1);
	}
	if (game->coin_count == 0)
	{
		ft_printf("Error : Coin count is 0!");
		return (1);
	}
	return (0);
}

int	char_checker(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_line[y])
	{
		x = 0;
		while (game->map_line[y][x] != '\n' && game->map_line[y][x] != '\0')
		{
			if (ft_strchr("01CEP", game->map_line[y][x]))
				x++;
			else
			{
				ft_printf("Error : There is invalid character in map!");
				return (1);
			}
		}
		y++;
	}
	return (0);
}

void	e_map(t_map *game)
{
	if (game->map_y_line == 1)
	{
		ft_printf("Error : empty map or invalid map!\n");
		exit (0);
	}
}
