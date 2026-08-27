/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:18:30 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/27 12:50:09 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

bool	is_wall(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (true);
	return (game->map.content[y * game->map.width + x] == WALL);
}

void	move_player(t_game *game, float move_x, float move_y)
{
	float	new_x;
	float	new_y;
	float	margin;

	margin = 0.2f;
	new_x = game->camera.pos_x + move_x;
	if (move_x > 0)
		new_x += margin;
	else if (move_x < 0)
		new_x -= margin;
	if (!is_wall(game, (int)new_x, (int)game->camera.pos_y))
		game->camera.pos_x += move_x;
	new_y = game->camera.pos_y + move_y;
	if (move_y > 0)
		new_y += margin;
	else if (move_y < 0)
		new_y -= margin;
	if (!is_wall(game, (int)game->camera.pos_x, (int)new_y))
		game->camera.pos_y += move_y;
}

static void	add_key_to_move(t_game *game, float *move_x, float *move_y)
{
	float	frame_mov_speed;

	frame_mov_speed = game->rules.mov_speed * game->delta_time;
	if (game->key_table[KEY_W])
	{
		*move_x += game->camera.dir_x * frame_mov_speed;
		*move_y += game->camera.dir_y * frame_mov_speed;
	}
	if (game->key_table[KEY_S])
	{
		*move_x -= game->camera.dir_x * frame_mov_speed;
		*move_y -= game->camera.dir_y * frame_mov_speed;
	}
	if (game->key_table[KEY_A])
	{
		*move_x -= game->camera.plan_x * frame_mov_speed;
		*move_y -= game->camera.plan_y * frame_mov_speed;
	}
	if (game->key_table[KEY_D])
	{
		*move_x += game->camera.plan_x * frame_mov_speed;
		*move_y += game->camera.plan_y * frame_mov_speed;
	}
}

void	key_move(t_game *game)
{
	float	move_x;
	float	move_y;

	move_x = 0.0f;
	move_y = 0.0f;
	add_key_to_move(game, &move_x, &move_y);
	if (move_x != 0.0f || move_y != 0.0f)
		move_player(game, move_x, move_y);
}
