/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:27:12 by lchamard          #+#    #+#             */
/*   Updated: 2026/09/03 15:11:40 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	verif_north_south(t_game *game, char c)
{
	if (c == 'N')
	{
		game->camera.dir_y = -1;
		game->camera.plan_x = 0.66;
		return (1);
	}
	else if (c == 'S')
	{
		game->camera.dir_y = 1;
		game->camera.plan_x = -0.66;
		return (1);
	}
	return (0);
}

int	verif_east_west(t_game *game, char c)
{
	if (c == 'E')
	{
		game->camera.dir_x = 1;
		game->camera.plan_y = 0.66;
		return (1);
	}
	else if (c == 'W')
	{
		game->camera.dir_x = -1;
		game->camera.plan_y = -0.66;
		return (1);
	}
	return (0);
}

int	init_player(t_game *game, char c, int x, int y)
{
	ft_bzero(&game->camera, sizeof(t_camera));
	game->camera.pos_x = (float)x + 0.5f;
	game->camera.pos_y = (float)y + 0.5f;
	if (verif_north_south(game, c))
		return (1);
	else if (verif_east_west(game, c))
		return (1);
	return (0);
}
