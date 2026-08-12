/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/12 17:04:37 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"

int	init_game(int start_map, t_game *game, char **file_content)
{
	if (!set_textures(game, file_content)
		|| !set_colors(game, file_content)
		|| !set_map(start_map, game, file_content))
		return (0);
	return (1);
}
