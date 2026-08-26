/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:31:52 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/26 18:07:11 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"

static	int	*translate(t_game *game, char *str)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * ft_strlen(str));
	while (str && str[i])
	{
		if (str[i] == ' ')
			res[i] = VOID;
		else if (str[i] == '1')
			res[i] = WALL;
		else
		{
			res[i] = GROUND;
			if (str[i] != '0')
				init_player(game, str[i]);
		}
		i++;
	}
	return (res);
}

int	set_map(int start_map, t_game *game, char **file_content)
{
	int		i;
	t_map	map;

	i = 0;
	map = game->map;
	while (file_content[i + start_map])
	{
		map.content[i] = translate(game, file_content[i + start_map]);
		i++;
	}
	return (1);
}
