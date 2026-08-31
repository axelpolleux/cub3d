/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:26:59 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/31 15:39:37 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"

static int	define_cell(t_game *game, char c, int x, int y)
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

static int	translate(t_game *game, char *str, int *player_is_define, int y)
{
	int	x;

	x = 0;
	while (str && str[x])
	{
		if (!*player_is_define && !define_cell(game, str[x], x, y))
		{
			game->map.content[y * game->map.width + x] = GROUND;
			*player_is_define = 1;
			init_player(game, str[x], x, y);
		}
		else if (!define_cell(game, str[x], x, y))
		{
			free(game->map.content);
			return (0);
		}
		x++;
	}
	while (x < game->map.width)
	{
		game->map.content[y * game->map.width + x] = VOID;
		x++;
	}
	return (1);
}

static int	allocate_map(int start_map, t_game *game, char **file_content)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (file_content[height + start_map])
	{
		if (ft_strlen(file_content[height + start_map]) > (unsigned long)width)
			width = ft_strlen(file_content[height + start_map]);
		height++;
	}
	game->map = (t_map){.width = width, .height = height,
		.content = malloc(width * height * sizeof(int))};
	if (!game->map.content)
		return (0);
	return (1);
}

int	set_map(int start_map, t_game *game, char **file_content)
{
	int		y;
	int		player_is_define;

	y = 0;
	player_is_define = 0;
	if (!allocate_map(start_map, game, file_content))
		return (0);
	while (file_content[y + start_map])
	{
		if (ft_strlen(file_content[y + start_map]) <= 0)
		{
			free(game->map.content);
			return (error("Empty line in your map\n╭(ʘ̆~◞౪◟~ʘ̆)╮"));
		}
		if (!translate(game, file_content[y + start_map], &player_is_define, y))
			return (0);
		y++;
	}
	if (!map_is_close(&game->map))
	{
		free(game->map.content);
		return (0);
	}
	return (1);
}
