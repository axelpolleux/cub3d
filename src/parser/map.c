/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:31:52 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/13 15:59:45 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"

static	int	*translate(char *str)
{
	int	*res;

	res = malloc(sizeof(int) * ft_strlen(str));
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
		map.content[i] = translate(file_content[i + start_map]);
		i++;
	}
	return (1);
}
