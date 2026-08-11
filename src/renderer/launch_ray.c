/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:33:00 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/11 18:12:55 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	put_fps_text(t_game *game)
{
	char	*str_delta_time;

	if (game->delta_time > 0)
	{
		str_delta_time = ft_itoa((int)(1 / game->delta_time));
		mlx_string_put(game->screen.mlx, game->screen.win, 100, 10,
			complement(game->textures.sky_color), str_delta_time);
		free(str_delta_time);
	}
	else
		mlx_string_put(game->screen.mlx, game->screen.win, 100, 10,
			complement(game->textures.sky_color), "0");
}

void	launch_ray(t_game *game)
{
	int		ray_x;
	float	elapsed_time;

	ray_x = 0;
	mlx_clear_window(game->screen.mlx, game->screen.win, (mlx_color)0u);
	while (ray_x < game->screen.width)
	{
		launch_one_ray(ray_x, game);
		ray_x++;
	}
	mlx_set_image_region(game->screen.mlx, game->screen.draw_img, 0, 0,
		game->screen.height, game->screen.width, game->screen.frame_buffer);
	mlx_put_transformed_image_to_window(game->screen.mlx, game->screen.win,
		game->screen.draw_img, (game->screen.width + game->screen.height) / 2,
		(game->screen.height - game->screen.width) / 2, -1.0, 1.0, 90);
	game->old_time = game->new_time;
	gettimeofday(&game->new_time, NULL);
	elapsed_time = (game->new_time.tv_sec - game->old_time.tv_sec) * 1000.0;
	elapsed_time += (game->new_time.tv_usec - game->old_time.tv_usec) / 1000.0;
	game->delta_time = elapsed_time / 1000.0;
	put_fps_text(game);
}
