/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:20:20 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/27 12:58:04 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"

void	initialise_rules(t_rules *rules)
{
	rules->mov_speed = 7.0f;
	rules->rot_speed = 3.0f;
}

void	initialise_screen(t_screen *screen)
{
	screen->width = 1920;
	screen->height = 1080;
	screen->draw_img = mlx_new_image(screen->mlx, screen->height,
			screen->width);
	screen->win_info = (mlx_window_create_info){0};
	screen->win_info.title = "cubi3D";
	screen->win_info.width = screen->width;
	screen->win_info.height = screen->height;
	screen->frame_buffer = ft_calloc(screen->width * screen->height,
			sizeof(mlx_color));
	screen->win = mlx_new_window(screen->mlx, &screen->win_info);
}

void	initialise_game(t_game *game)
{
	gettimeofday(&game->new_time, NULL);
	initialise_screen(&game->screen);
	initialise_rules(&game->rules);
	game->running = true;
}
