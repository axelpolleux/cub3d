/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:18:30 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/05 18:19:40 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

static void	move_player(t_game *game, float move_x, float move_y)
{
	float	new_x;
	float	new_y;
	float	check_x;
	float	check_y;

	new_x = game->camera.pos_x + move_x;
	new_y = game->camera.pos_y + move_y;
	if (move_x > 0)
		check_x = new_x + WALL_DIST;
	else
		check_x = new_x - WALL_DIST;
	if (game->map.content[(int)floor(game->camera.pos_y)][(int)floor(check_x)]
		!= WALL)
		game->camera.pos_x = new_x;
	if (move_y > 0)
		check_y = new_y + WALL_DIST;
	else
		check_y = new_y - WALL_DIST;
	if (game->map.content[(int)floor(check_y)][(int)floor(game->camera.pos_x)]
		!= WALL)
		game->camera.pos_y = new_y;
}

void	key_move(t_game *game)
{
	float	move_x;
	float	move_y;

	move_x = 0.0f;
	move_y = 0.0f;
	if (game->key_table[KEY_W])
	{
		move_x += game->camera.dir_x * game->rules.mov_speed;
		move_y += game->camera.dir_y * game->rules.mov_speed;
	}
	if (game->key_table[KEY_S])
	{
		move_x -= game->camera.dir_x * game->rules.mov_speed;
		move_y -= game->camera.dir_y * game->rules.mov_speed;
	}
	if (game->key_table[KEY_A])
	{
		move_x -= game->camera.plan_x * game->rules.mov_speed;
		move_y -= game->camera.plan_y * game->rules.mov_speed;
	}
	if (game->key_table[KEY_D])
	{
		move_x += game->camera.plan_x * game->rules.mov_speed;
		move_y += game->camera.plan_y * game->rules.mov_speed;
	}
	if (move_x != 0.0f || move_y != 0.0f)
		move_player(game, move_x, move_y);
	if (move_x != 0.0f || move_y != 0.0f || game->key_table[KEY_Q]
		|| game->key_table[KEY_E])
	{
		mlx_clear_window(game->screen.mlx, game->screen.win, (mlx_color)0u);
		launch_ray(game);
		mlx_put_image_to_window(game->screen.mlx, game->screen.win,
			game->screen.img, 0, 0);
	}
}
