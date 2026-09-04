/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/09/04 17:25:34 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"

void	destroy_textures(t_game *game)
{
	if (game->textures.south_face.content)
		mlx_destroy_image(game->screen.mlx, game->textures.south_face.content);
	if (game->textures.east_face.content)
		mlx_destroy_image(game->screen.mlx, game->textures.east_face.content);
	if (game->textures.north_face.content)
		mlx_destroy_image(game->screen.mlx, game->textures.north_face.content);
	if (game->textures.west_face.content)
		mlx_destroy_image(game->screen.mlx, game->textures.west_face.content);
}

int	init_game(int start_map, t_game *game, char **file_content)
{
	if (!set_textures(game, file_content)
		|| !set_colors(game, file_content)
		|| !set_map(start_map, game, file_content))
	{
		destroy_textures(game);
		return (0);
	}
	return (1);
}
