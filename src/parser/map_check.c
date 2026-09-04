/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:16:41 by apolleux          #+#    #+#             */
/*   Updated: 2026/09/04 14:11:51 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"

static int	is_valid_tile(char tile)
{
	return (tile == GROUND || tile == WALL);
}

void	fill_void(t_game *game, int *x, int *y)
{
	while ((*x) < game->map.width)
	{
		game->map.content[(*y) * game->map.width + (*x)] = VOID;
		(*x)++;
	}
}

static int	verif_cell(t_map *map, int *x, int *y)
{
	if (*x == 0 || *y == 0 || *x == map->width - 1
		|| *y == map->height - 1)
		return (0);
	if (!is_valid_tile(map->content[(*y - 1) * map->width + (*x)])
		|| !is_valid_tile(map->content[*y * map->width + (*x - 1)])
		|| !is_valid_tile(map->content[*y * map->width + *x])
		|| !is_valid_tile(map->content[*y * map->width + (*x + 1)])
		|| !is_valid_tile(map->content[(*y + 1) * map->width + *x]))
		return (0);
	return (1);
}

int	define_cell(t_game *game, char c, int x, int y)
{
	if (c == ' ')
	{
		game->map.content[y * game->map.width + x] = VOID;
		return (1);
	}
	else if (c == '1')
	{
		game->map.content[y * game->map.width + x] = WALL;
		return (1);
	}
	else if (c == '0')
	{
		game->map.content[y * game->map.width + x] = GROUND;
		return (1);
	}
	return (0);
}

int	map_is_close(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->content[y * map->width + x] == GROUND)
			{
				if (!verif_cell(map, &x, &y))
					return (error("Map isn't close"));
			}
			x++;
		}
		y++;
	}
	return (1);
}
