/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:26:59 by apolleux          #+#    #+#             */
/*   Updated: 2026/09/04 16:02:22 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"

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
			if (!init_player(game, str[x], x, y))
			{
				free(game->map.content);
				return (error("Invalid character on the map"));
			}
		}
		else if (!define_cell(game, str[x], x, y))
		{
			free(game->map.content);
			return (error("Invalid character on the map"));
		}
		x++;
	}
	fill_void(game, &x, &y);
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
		return (error("Malloc fail on map allocation"));
	return (1);
}

static int	fill_map(int *defined, int *map, char ***content,
	t_game **game)
{
	int	y;

	y = 0;
	while ((*content)[y + (*map)])
	{
		if (!translate((*game), (*content)[y + (*map)],
			&(*defined), y))
			return (0);
		if (ft_strlen((*content)[y + (*map)]) <= 0)
		{
			free((*game)->map.content);
			return (error("Empty line in your map\n╭(ʘ̆~◞౪◟~ʘ̆)╮"));
		}
		y++;
	}
	return (1);
}

int	set_map(int start_map, t_game *game, char **file_content)
{
	int		player_is_define;

	player_is_define = 0;
	if (!allocate_map(start_map, game, file_content))
		return (0);
	if (!fill_map(&player_is_define, &start_map, &file_content, &game))
		return (0);
	if (!player_is_define || !map_is_close(&game->map))
	{
		free(game->map.content);
		return (0);
	}
	return (1);
}
