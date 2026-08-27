/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_one_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:28:37 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/27 12:34:35 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	detect_collision(t_ray *ray, t_game *game)
{
	if ((ray->map_x < 0 || game->map.width <= ray->map_x) || (ray->map_y < 0
			|| game->map.height <= ray->map_y))
	{
		if (ray->side_dist_x < ray->side_dist_y)
			ray->map_x -= ray->step_x;
		else
			ray->map_y -= ray->step_y;
		ray->hit = 0;
	}
	else if (game->map.content[ray->map_y * game->map.width + ray->map_x]
		== WALL)
		ray->hit = 1;
}

void	ray_move(t_ray *ray, t_game *game)
{
	int	distance_player;

	distance_player = 256;
	ray->hit = 0;
	while (distance_player-- && !ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		detect_collision(ray, game);
	}
}

static void	define_ray_step(t_ray *ray, t_game *game)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->camera.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->camera.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->camera.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->camera.pos_y)
			* ray->delta_dist_y;
	}
}

void	launch_one_ray(int ray_x, t_game *game)
{
	t_ray	ray;
	float	camera_x;

	ray.pos_x = ray_x;
	camera_x = 2 * ray_x / (float)game->screen.width - 1;
	ray.dir_x = game->camera.dir_x + game->camera.plan_x * camera_x;
	ray.dir_y = game->camera.dir_y + game->camera.plan_y * camera_x;
	ray.map_x = (int)floor(game->camera.pos_x);
	ray.map_y = (int)floor(game->camera.pos_y);
	if (ray.dir_x == 0)
		ray.delta_dist_x = 1e30;
	else
		ray.delta_dist_x = fabsf(1 / ray.dir_x);
	if (ray.dir_y == 0)
		ray.delta_dist_y = 1e30;
	else
		ray.delta_dist_y = fabsf(1 / ray.dir_y);
	define_ray_step(&ray, game);
	ray_move(&ray, game);
	if (ray.side)
		ray.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y);
	else
		ray.perp_wall_dist = (ray.side_dist_x - ray.delta_dist_x);
	draw_line(&ray, game);
}
