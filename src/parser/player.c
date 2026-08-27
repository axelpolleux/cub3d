/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:27:12 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/27 13:16:33 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_player(t_game *game, char c, int x, int y)
{
	ft_bzero(&game->camera, sizeof(t_camera));
	game->camera.pos_x = (float)x + 0.5f;
	game->camera.pos_y = (float)y + 0.5f;
	if (c == 'N')
	{
		game->camera.dir_y = -1;
		game->camera.plan_x = 0.66;
	}
	else if (c == 'S')
	{
		game->camera.dir_y = 1;
		game->camera.plan_x = -0.66;
	}
	else if (c == 'E')
	{
		game->camera.dir_x = 1;
		game->camera.plan_y = 0.66;
	}
	else if (c == 'O')
	{
		game->camera.dir_x = -1;
		game->camera.plan_y = -0.66;
	}
}
