/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/09 15:25:48 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"

void	initialise_rules(t_rules *rules)
{
	rules->mov_speed = 10.0f;
	rules->rot_speed = 3.0f;
	return ;
}

void	initialise_screen(t_screen *screen)
{
	screen->width = 720;
	screen->height = 480;
	screen->img = mlx_new_image(screen->mlx, screen->width, screen->height);
	screen->win_info = (mlx_window_create_info){0};
	screen->win_info.title = "cubi3D";
	screen->win_info.width = screen->width;
	screen->win_info.height = screen->height;
	screen->win = mlx_new_window(screen->mlx, &screen->win_info);
}

void	initialise_game(t_game *game)
{
	gettimeofday(&game->new_time, NULL);
	initialise_screen(&game->screen);
	initialise_rules(&game->rules);
	game->running = true;
	game->camera = (t_camera){.pos_x = 3, .pos_y = 3, .dir_x = -1, .dir_y = 0,
		.plan_x = 0, .plan_y = -0.66};
}
