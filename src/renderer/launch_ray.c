/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/09 15:21:36 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	launch_ray(t_game *game)
{
	int		ray_x;
	float	elapsed_time;
	char	*str_delta_time;

	ray_x = 0;
	mlx_clear_window(game->screen.mlx, game->screen.win, (mlx_color)0u);
	while (ray_x < game->screen.width)
	{
		launch_one_ray(ray_x, game);
		ray_x++;
	}
	mlx_put_image_to_window(game->screen.mlx, game->screen.win,
		game->screen.img, 0, 0);
	game->old_time = game->new_time;
	gettimeofday(&game->new_time, NULL);
	elapsed_time = (game->new_time.tv_sec - game->old_time.tv_sec) * 1000.0;
	elapsed_time += (game->new_time.tv_usec - game->old_time.tv_usec) / 1000.0;
	game->delta_time = elapsed_time / 1000.0;
	if (game->delta_time > 0)
	{
		str_delta_time = ft_itoa((int) (1 / game->delta_time));
		mlx_string_put(game->screen.mlx, game->screen.win, 100, 10,
			(mlx_color){ .rgba = 0xFFFFFFFF }, str_delta_time);
		free(str_delta_time);
	}
	else
		mlx_string_put(game->screen.mlx, game->screen.win, 100, 10,
			(mlx_color){ .rgba = 0xFFFFFFFF }, "0");
}
