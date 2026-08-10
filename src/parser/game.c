/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:54:23 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/10 17:41:45 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"

int	init_game(t_game *game, char **file_content)
{
	// if (!set_textures(game, file_content)
	// 	|| !set_map(game, file_content)
	// 	|| !set_colors(game, file_content))
	// 	return (0);

	// test unitaires
	// if (!set_textures(game, file_content))
	// 	return (0);
	if (!set_colors(game, file_content))
		return (0);
	// if (!set_map(game, file_content))
	// 	return (0);
	return (1);
}
