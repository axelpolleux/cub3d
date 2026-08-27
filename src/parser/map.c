/* ************************************************************************** */
/*																			*/
/*														:::		::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*													+:+ +:+			+:+	 */
/*   By: apolleux <apolleux@student.1337.ma>		+#+  +:+		+#+		*/
/*												+#+#+#+#+#+   +#+			*/
/*   Created: 2026/08/05 14:31:52 by apolleux			#+#	#+#			 */
/*   Updated: 2026/08/27 13:12:10 by lchamard         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"

static int	is_valid_tile(char tile)
{
	return (tile == GROUND || tile == WALL);
}

static int	map_is_close(t_map *map)
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
				if (x == 0 || y == 0 || x == map->width - 1 || y == map->height
					- 1)
					return (0);
				if (!is_valid_tile(map->content[(y - 1) * map->width + (x - 1)])
					|| !is_valid_tile(map->content[(y - 1) * map->width + x])
					|| !is_valid_tile(map->content[(y - 1) * map->width + (x
							+ 1)]) || !is_valid_tile(map->content[y * map->width
						+ (x - 1)]) || !is_valid_tile(map->content[y
						* map->width + x]) || !is_valid_tile(map->content[y
						* map->width + (x + 1)])
					|| !is_valid_tile(map->content[(y + 1) * map->width + (x
							- 1)]) || !is_valid_tile(map->content[(y + 1)
						* map->width + x]) || !is_valid_tile(map->content[(y
							+ 1) * map->width + (x + 1)]))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	translate(t_game *game, char *str, bool *player_is_define, int y)
{
	int	x;
	int	*res;

	x = 0;
	res = game->map.content;
	while (str && str[x])
	{
		if (str[x] == ' ')
			res[y * game->map.width + x] = VOID;
		else if (str[x] == '1')
			res[y * game->map.width + x] = WALL;
		else
		{
			res[y * game->map.width + x] = GROUND;
			if (str[x] != '0' && !*player_is_define)
			{
				*player_is_define = true;
				init_player(game, str[x], x, y);
			}
			else if (str[x] != '0')
			{
				free(game->map.content);
				return (0);
			}
		}
		x++;
	}
	while (x < game->map.width)
	{
		res[y * game->map.width + x] = VOID;
		x++;
	}
	return (1);
}

static bool	allocate_map(int start_map, t_game *game, char **file_content)
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
	bool	player_is_define;

	y = 0;
	player_is_define = false;
	if (!allocate_map(start_map, game, file_content))
		return (0);
	while (file_content[y + start_map])
	{
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
