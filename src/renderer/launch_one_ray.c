/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_one_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:50:11 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/05 17:59:07 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	give_ray_color(t_ray *ray, mlx_color *color)
{
	if (ray->side == 0 && ray->step_x < 0) // EAST FACE
		color->rgba = 0x00FF00FF;
	else if (ray->side == 0 && ray->step_x > 0) // WEST FACE
		color->rgba = 0xFF0000FF;
	else if (ray->side == 1 && ray->step_y < 0) // SOUTH FACE
		color->rgba = 0x0000FFFF;
	else if (ray->side == 1 && ray->step_y > 0) // NORTH FACE
		color->rgba = 0xFFFF00FF;
}

void	draw_ray_wall(t_ray *ray, t_game *game)
{
	int			h;
	int			draw_start;
	int			draw_end;
	mlx_color	color;
	int			i;

	h = game->screen.height;
	ray->line_height = round(h / ray->perp_wall_dist);
	draw_start = -1 * ray->line_height / 2 + h / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = ray->line_height / 2 + h / 2;
	if (draw_end < 0)
		draw_end = 0;
	give_ray_color(ray, &color);
	if (ray->hit)
	{
		i = 0;
		while (i < game->screen.height)
		{
			if (i < draw_start)
				color.rgba = 0x000000FF;
			else if (i > draw_end)
				color.rgba = 0xFFFFFFFF;
			else
				give_ray_color(ray, &color);
			mlx_set_image_pixel(game->screen.mlx, game->screen.img, ray->pos_x,
				i, color);
			i++;
		}
	}
}

void	ray_move(t_ray *ray, t_game *game)
{
	ray->hit = 0;
	while (!ray->hit)
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
		if (ray->map_x < 0 || game->map.width < ray->map_x || ray->map_y < 0
			|| game->map.height < ray->map_y)
		{
			if (ray->side_dist_x < ray->side_dist_y)
				ray->map_x -= ray->step_x;
			else
				ray->map_y -= ray->step_y;
			ray->hit = 2;
		}
		else if (game->map.content[ray->map_y][ray->map_x] == WALL)
			ray->hit = 1;
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
	if (ray.dir_x < 0)
	{
		ray.step_x = -1;
		ray.side_dist_x = (game->camera.pos_x - ray.map_x) * ray.delta_dist_x;
	}
	else
	{
		ray.step_x = 1;
		ray.side_dist_x = (ray.map_x + 1.0 - game->camera.pos_x)
			* ray.delta_dist_x;
	}
	if (ray.dir_y < 0)
	{
		ray.step_y = -1;
		ray.side_dist_y = (game->camera.pos_y - ray.map_y) * ray.delta_dist_y;
	}
	else
	{
		ray.step_y = 1;
		ray.side_dist_y = (ray.map_y + 1.0 - game->camera.pos_y)
			* ray.delta_dist_y;
	}
	ray_move(&ray, game);
	if (ray.side)
		ray.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y);
	else
		ray.perp_wall_dist = (ray.side_dist_x - ray.delta_dist_x);
	draw_ray_wall(&ray, game);
}
