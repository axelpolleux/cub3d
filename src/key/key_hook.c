/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/04 16:16:30 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	keyup_hook(int keycode, void *game_ptr)
{
	t_game	*game;

	game = (t_game *)game_ptr;
	game->key_table[keycode] = 0;
}

void	keydown_hook(int keycode, void *game_ptr)
{
	t_game	*game;

	game = (t_game *)game_ptr;
	game->key_table[keycode] = 1;
}

void	window_hook(int event, void *game_ptr)
{
	t_game	*game;

	game = (t_game *)game_ptr;
	if (!event)
		mlx_loop_end(game->screen.mlx);
}
