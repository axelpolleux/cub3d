/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/10 19:19:46 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"

int	init_game(t_game *game, char **file_content)
{
	if (!set_textures(game, file_content)
		|| !set_map(game, file_content)
		|| !set_colors(game, file_content))
		return (0);
	return (1);
}
