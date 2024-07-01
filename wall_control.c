/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:43 by darikan           #+#    #+#             */
/*   Updated: 2024/05/08 18:16:43 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check(t_map *map)
{
	int	y;
	int	firstend;
	int	middle;

	y = 0;
	firstend = wall_first_end(map, y);
	if (firstend != 0)
	{
		ft_printf("Error : Wall Error!");
		return (1);
	}
	y = 1;
	middle = wall_middle(map, y);
	if (middle != 0)
	{
		ft_printf("Error : Wall Error!");
		return (1);
	}
	return (0);
}

int	wall_first_end(t_map *map, int y)
{
	int	x;
	int	len;

	len = map->map_y_line;
	if (y == 0 || y == (len - 1))
	{
		x = 0;
		while (map->map_line[y][x] != '\n')
		{
			if (map->map_line[0][x] != '1')
				return (1);
			if (map->map_line[len - 1][x] != '1')
				return (1);
			x++;
		}
	}
	return (0);
}

int	wall_middle(t_map *map, int y)
{
	int	len;

	len = ft_strlen(map->map_line[0]) - 2;
	while (map->map_line[y] != 0)
	{
		if (map->map_line[y][0] != '1'
				|| map->map_line[y][len] != '1')
			return (y + 1);
		y++;
	}
	return (0);
}
