/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:32:11 by lchamard          #+#    #+#             */
/*   Updated: 2026/09/03 19:30:28 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "mlx.h"
# include "renderer.h"
# include "struct.h"
# include <SDL2/SDL_scancode.h>
# include <math.h>

# define WALL_DIST 0.2f

void	key_move(t_game *game);
void	key_escape(t_game *game);
void	key_rot(t_game *game);
void	keyup_hook(int keycode, void *game_ptr);
void	keydown_hook(int keycode, void *game_ptr);
void	window_hook(int event, void *game_ptr);

#endif
