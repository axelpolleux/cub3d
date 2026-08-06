/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/06 13:32:57 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	launch_ray(t_game *game)
{
	int	ray_x;

	ray_x = 0;
	ft_bzero(game->screen.frame_buffer, game->screen.width * game->screen.height * sizeof(mlx_color));
	while (ray_x < game->screen.width)
	{
		launch_one_ray(ray_x, game);
		ray_x++;
	}
	mlx_set_image_region(game->screen.mlx, game->screen.img, 0, 0, game->screen.width, game->screen.height, game->screen.frame_buffer);
	mlx_put_image_to_window(game->screen.mlx, game->screen.win,
		game->screen.img, 0, 0);
}
