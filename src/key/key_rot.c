/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:32:06 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/05 18:20:26 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	key_rot(t_game *game)
{
	float	old_dir_x;
	float	old_plan_x;

	if (game->key_table[KEY_Q])
	{
		old_dir_x = game->camera.dir_x;
		game->camera.dir_x = game->camera.dir_x * cos(-game->rules.rot_speed)
			- game->camera.dir_y * sin(-game->rules.rot_speed);
		game->camera.dir_y = old_dir_x * sin(-game->rules.rot_speed)
			+ game->camera.dir_y * cos(-game->rules.rot_speed);
		old_plan_x = game->camera.plan_x;
		game->camera.plan_x = game->camera.plan_x * cos(-game->rules.rot_speed)
			- game->camera.plan_y * sin(-game->rules.rot_speed);
		game->camera.plan_y = old_plan_x * sin(-game->rules.rot_speed)
			+ game->camera.plan_y * cos(-game->rules.rot_speed);
	}
	if (game->key_table[KEY_E])
	{
		old_dir_x = game->camera.dir_x;
		game->camera.dir_x = game->camera.dir_x * cos(game->rules.rot_speed)
			- game->camera.dir_y * sin(game->rules.rot_speed);
		game->camera.dir_y = old_dir_x * sin(game->rules.rot_speed)
			+ game->camera.dir_y * cos(game->rules.rot_speed);
		old_plan_x = game->camera.plan_x;
		game->camera.plan_x = game->camera.plan_x * cos(game->rules.rot_speed)
			- game->camera.plan_y * sin(game->rules.rot_speed);
		game->camera.plan_y = old_plan_x * sin(game->rules.rot_speed)
			+ game->camera.plan_y * cos(game->rules.rot_speed);
	}
}
