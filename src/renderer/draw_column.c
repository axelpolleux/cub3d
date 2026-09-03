/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 16:30:44 by lchamard          #+#    #+#             */
/*   Updated: 2026/09/03 11:07:44 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	draw_wall(t_game *game, t_ray *ray, int tex_x, t_image image)
{
	float		tex_pos;
	int			y;
	mlx_color	color;
	int			tex_y;
	float		step;

	step = 1.0 * image.height / ray->line_height;
	tex_pos = (ray->draw_start - game->screen.height / 2 + ray->line_height / 2)
		* step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos % image.height;
		if (tex_y < 0)
			tex_y += image.height;
		tex_pos += step;
		color = mlx_get_image_pixel(game->screen.mlx, image.content, tex_x,
				tex_y);
		game->screen.frame_buffer[ray->pos_x * game->screen.height + y] = color;
		y++;
	}
}

void	load_good_texture(t_game *game, t_ray *ray, t_image *image)
{
	if (ray->side == 0 && ray->step_x < 0)
		*image = game->textures.east_face;
	else if (ray->side == 0 && ray->step_x > 0)
		*image = game->textures.west_face;
	else if (ray->side == 1 && ray->step_y < 0)
		*image = game->textures.south_face;
	else if (ray->side == 1 && ray->step_y > 0)
		*image = game->textures.north_face;
}

void	calculate_and_draw_wall(t_game *game, t_ray *ray)
{
	float	wall_x;
	t_image	image;
	int		tex_x;

	load_good_texture(game, ray, &image);
	if (ray->side == 0)
		wall_x = game->camera.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->camera.pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= (int)floor(wall_x);
	tex_x = (int)(wall_x * (float)image.width);
	if (tex_x >= image.width)
		tex_x = image.width - 1;
	if (ray->side == 0 && ray->dir_x < 0)
		tex_x = image.width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		tex_x = image.width - tex_x - 1;
	draw_wall(game, ray, tex_x, image);
}

void	draw_sky_and_ground(t_ray *ray, t_game *game)
{
	int			i;
	mlx_color	color;

	i = 0;
	while (i < game->screen.height)
	{
		if (i < ray->draw_end)
		{
			color = game->textures.sky_color;
			game->screen.frame_buffer[ray->pos_x * game->screen.height
				+ i] = color;
		}
		else if (i >= ray->draw_end)
		{
			color = game->textures.ground_color;
			game->screen.frame_buffer[ray->pos_x * game->screen.height
				+ i] = color;
		}
		i++;
	}
}

void	draw_line(t_ray *ray, t_game *game)
{
	int	h;

	h = game->screen.height;
	ray->line_height = round(h / ray->perp_wall_dist);
	ray->draw_start = -1 * ray->line_height / 2 + h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + h / 2;
	if (ray->draw_end > game->screen.height)
		ray->draw_end = game->screen.height - 1;
	draw_sky_and_ground(ray, game);
	if (ray->hit == 1)
		calculate_and_draw_wall(game, ray);
}
