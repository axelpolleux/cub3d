/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/08 17:43:58 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	launch_ray(t_game *game)
{
	int	ray_x;

	ray_x = 0;
	mlx_clear_window(game->screen.mlx, game->screen.win, (mlx_color)0u);
	while (ray_x < game->screen.width)
	{
		launch_one_ray(ray_x, game);
		ray_x++;
	}
	mlx_put_image_to_window(game->screen.mlx, game->screen.win,
		game->screen.img, 0, 0);
}
