/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:32:06 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/09 15:20:00 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

static void    key_rot_q(t_game *game)
{
    float    old_dir_x;
    float    old_plan_x;
    float    rot_speed;

    if (game->key_table[KEY_Q])
    {
        rot_speed = -game->rules.rot_speed * game->delta_time;
        old_dir_x = game->camera.dir_x;
        game->camera.dir_x = game->camera.dir_x * cos(rot_speed)
            - game->camera.dir_y * sin(rot_speed);
        game->camera.dir_y = old_dir_x * sin(rot_speed)
            + game->camera.dir_y * cos(rot_speed);
        old_plan_x = game->camera.plan_x;
        game->camera.plan_x = game->camera.plan_x * cos(rot_speed)
            - game->camera.plan_y * sin(rot_speed);
        game->camera.plan_y = old_plan_x * sin(rot_speed)
            + game->camera.plan_y * cos(rot_speed);
    }
}

static void    key_rot_e(t_game *game)
{
    float    old_dir_x;
    float    old_plan_x;
    float    rot_speed;

    if (game->key_table[KEY_E])
    {
        rot_speed = game->rules.rot_speed * game->delta_time;
        old_dir_x = game->camera.dir_x;
        game->camera.dir_x = game->camera.dir_x * cos(rot_speed)
            - game->camera.dir_y * sin(rot_speed);
        game->camera.dir_y = old_dir_x * sin(rot_speed)
            + game->camera.dir_y * cos(rot_speed);
        old_plan_x = game->camera.plan_x;
        game->camera.plan_x = game->camera.plan_x * cos(rot_speed)
            - game->camera.plan_y * sin(rot_speed);
        game->camera.plan_y = old_plan_x * sin(rot_speed)
            + game->camera.plan_y * cos(rot_speed);
    }
}

void	key_rot(t_game *game)
{
	key_rot_e(game);
	key_rot_q(game);
}
