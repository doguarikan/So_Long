/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:38 by darikan           #+#    #+#             */
/*   Updated: 2024/05/08 18:16:38 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_checker(int argc, char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argc != 2)
	{
		ft_printf("Error : Invalid number of arguments!\n");
		return (1);
	}
	if (argv[len - 1] != 'r' && argv[len - 2] != 'e' && \
			argv[len - 3] != 'b' && argv[len - 4] != '.')
	{
		ft_printf("Error : File extension must be .ber!\n");
		return (1);
	}
	return (0);
}

int	map_checker(t_map *game)
{
	if (check_shape(game) || char_count(game) || wall_check(game) || \
			char_checker(game) || is_reachable(game))
	{
		free_map(game);
		return (1);
	}
	free_map(game);
	return (0);
}

int	map_init(t_map *game, char *argv)
{
	int	x;

	map_read_check(game, argv);
	game->playermove = 0;
	game->mlx = mlx_init();
	x = ft_strlen(game->map_line[0]) - 1;
	game->mlx_win = mlx_new_window(game->mlx, \
		64 * x, 64 * game->map_y_line, "SO_LONG");
	if (!game->mlx || !game->mlx_win || create_xpm(game))
	{
		ft_printf("Error : mlx or mlx_win is NULL!\n");
		return (1);
	}
	put_image(game);
	mlx_string_put(game->mlx, game->mlx_win, 15, 15, 16777215, "0");
	mlx_hook(game->mlx_win, 2, 1L << 2, ft_move, game);
	mlx_hook(game->mlx_win, 17, 1L << 2, safe_exit, game);
	mlx_loop(game->mlx);
	return (0);
}

int	map_read_check(t_map *game, char *f_name)
{
	read_chars(game, f_name);
	if (!(game->map_line))
	{
		ft_printf("Error : Cannot read the map!\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	game;

	if (ber_checker(argc, argv[1]) || map_read_check(&game, argv[1]))
		return (1);
	if (map_checker(&game))
		return (1);
	if ((&game)->map_y_line > 20 || (&game)->map_x_line > 40)
	{
		ft_printf("Error : extends out!\n");
		return (1);
	}
	if (map_init(&game, argv[1]))
		return (1);
	return (0);
}
