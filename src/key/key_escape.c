/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_escape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:31:56 by lchamard          #+#    #+#             */
/*   Updated: 2026/09/03 19:31:21 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	key_escape(t_game *game)
{
	if (game->key_table[SDL_SCANCODE_ESCAPE])
		mlx_loop_end(game->screen.mlx);
}
