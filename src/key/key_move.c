/* ************************************************************************** */
/*                                                                            */
/*                                                        ::      ::::::::   */
/*   key_move.c                                         +:      :+:    :+:   */
/*                                                    ++ +:+         +:+     */
/*   By lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created 2026/08/04 17:18:38 by lchamard          #+#    #+#             */
/*   Updated 2026/08/04 17:31:19 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	key_move(t_game *game)
{
	float	oldDirX;
	float	oldPlaneX;

	if (game->key_table['q'])
	{
		oldDirX = game->camera.dir_x;
		game->camera.dir_x = game->camera.dir_x * cos(-game->rules.rot_speed) - game->camera.dir_y * sin(-1 * game->rules.rot_speed);
		game->camera.dir_y = oldDirX * sin(-game->rules.rot_speed) + game->camera.dir_y * cos(-game->rules.rot_speed);
		oldPlaneX = game->camera.plan_x;
		game->camera.plan_x = game->camera.plan_x * cos(-game->rules.rot_speed) - game->camera.plan_y * sin(-1 * game->rules.rot_speed);
		game->camera.plan_y = oldPlaneX * sin(-game->rules.rot_speed) + game->camera.plan_y * cos(-game->rules.rot_speed);
	}
	if (game->key_table['e'])
	{
		oldDirX = game->camera.dir_x;
		game->camera.dir_x = game->camera.dir_x * cos(game->rules.rot_speed) - game->camera.dir_y * sin(game->rules.rot_speed);
		game->camera.dir_y = oldDirX * sin(game->rules.rot_speed) + game->camera.dir_y * cos(game->rules.rot_speed);
		oldPlaneX = game->camera.plan_x;
		game->camera.plan_x = game->camera.plan_x * cos(game->rules.rot_speed) - game->camera.plan_y * sin(game->rules.rot_speed);
		game->camera.plan_y = oldPlaneX * sin(game->rules.rot_speed) + game->camera.plan_y * cos(game->rules.rot_speed);
	}

	if (game->key_table['w'])
	{
		if (game->map.content[(int)floor(game->camera.pos_x + game->rules.mov_speed * game->camera.dir_x)][(int)floor(game->camera.pos_y)] == 0)
			game->camera.pos_x += game->rules.mov_speed * game->camera.dir_x;
		if (game->map.content[(int)floor(game->camera.pos_x)][(int)floor(game->camera.pos_y + game->rules.mov_speed * game->camera.dir_y)] == 0)
			game->camera.pos_y += game->rules.mov_speed * game->camera.dir_y;
	}
	if (game->key_table['s'])
	{
		if (game->map.content[(int)floor(game->camera.pos_x - game->rules.mov_speed * game->camera.dir_x)][(int)floor(game->camera.pos_y)] == 0)
			game->camera.pos_x -= game->rules.mov_speed * game->camera.dir_x;
		if (game->map.content[(int)floor(game->camera.pos_x)][(int)floor(game->camera.pos_y - game->rules.mov_speed * game->camera.dir_y)] == 0)
			game->camera.pos_y -= game->rules.mov_speed * game->camera.dir_y;
	}
	if (game->key_table['a'])
	{
		if (game->map.content[(int)floor(game->camera.pos_x - game->rules.mov_speed * game->camera.plan_x)][(int)floor(game->camera.pos_y)] == 0)
			game->camera.pos_x -= game->rules.mov_speed * game->camera.plan_x;
		if (game->map.content[(int)floor(game->camera.pos_x)][(int)floor(game->camera.pos_y - game->rules.mov_speed * game->camera.plan_y)] == 0)
			game->camera.pos_y -= game->rules.mov_speed * game->camera.plan_y;
	}
	if (game->key_table['d'])
	{
		if (game->map.content[(int)floor(game->camera.pos_x + game->rules.mov_speed * game->camera.plan_x)][(int)floor(game->camera.pos_y)] == 0)
			game->camera.pos_x += game->rules.mov_speed * game->camera.plan_x;
		if (game->map.content[(int)floor(game->camera.pos_x)][(int)floor(game->camera.pos_y + game->rules.mov_speed * game->camera.plan_y)] == 0)
			game->camera.pos_y += game->rules.mov_speed * game->camera.plan_y;
	}
}
