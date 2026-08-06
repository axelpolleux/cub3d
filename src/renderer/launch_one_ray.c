/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_one_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:28:37 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/06 13:28:23 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	draw_wall_line( t_game *game, t_ray *ray )
{
	float	  wall_x;
	t_image	  image;
	int		  tex_x;
	int		  tex_y;
	float	  step;
	float	  tex_pos;
	int		  y;
	mlx_color color;

	if ( ray->side == 0 && ray->step_x < 0 )
		image = game->textures.south_face;
	else if ( ray->side == 0 && ray->step_x > 0 )
		image = game->textures.north_face;
	else if ( ray->side == 1 && ray->step_y < 0 )
		image = game->textures.west_face;
	else if ( ray->side == 1 && ray->step_y > 0 )
		image = game->textures.east_face;
	if ( ray->side == 0 )
		wall_x = game->camera.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->camera.pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= (int)floor( wall_x );
	tex_x = (int)( wall_x * (float)image.width );
	if ( tex_x >= image.width )
		tex_x = image.width - 1;
	if ( ray->side == 0 && ray->dir_x < 0 )
		tex_x = image.width - tex_x - 1;
	if ( ray->side == 1 && ray->dir_y > 0 )
		tex_x = image.width - tex_x - 1;
	step = 1.0 * image.height / ray->line_height;
	tex_pos =
		( ray->draw_start - game->screen.height / 2 + ray->line_height / 2 ) *
		step;
	y = ray->draw_start;
	while ( y < ray->draw_end )
	{
		tex_y = (int)tex_pos % image.height;
		if ( tex_y < 0 )
			tex_y += image.height;
		tex_pos += step;
		color = mlx_get_image_pixel( game->screen.mlx,
									 image.content,
									 tex_x,
									 tex_y );
		set_arrays(game->screen.frame_buffer, ray->pos_x, y, game->screen.width, color);
		y++;
	}
}

void draw_ray_wall( t_ray *ray, t_game *game )
{
	int		  h;
	mlx_color color;
	int		  i;

	h = game->screen.height;
	ray->line_height = round( h / ray->perp_wall_dist );
	ray->draw_start = -1 * ray->line_height / 2 + h / 2;
	if ( ray->draw_start < 0 )
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + h / 2;
	if ( ray->draw_end < 0 )
		ray->draw_end = 0;
	if ( ray->hit == 1 )
	{
		i = 0;
		draw_wall_line( game, ray );
		while ( i < game->screen.height )
		{
			if ( i < ray->draw_start )
			{
				color = game->textures.sky_color;
				set_arrays(game->screen.frame_buffer, ray->pos_x, i, game->screen.width, color);
			}
			else if ( i > ray->draw_end )
			{
				color = game->textures.ground_color;
				set_arrays(game->screen.frame_buffer, ray->pos_x, i, game->screen.width, color);
			}
			i++;
		}
	}
}

void ray_move( t_ray *ray, t_game *game )
{
	ray->hit = 0;
	while ( !ray->hit )
	{
		if ( ray->side_dist_x < ray->side_dist_y )
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
		if ( ( ray->map_x < 0 || game->map.width <= ray->map_x ) ||
			 ( ray->map_y < 0 || game->map.height <= ray->map_y ) )
		{
			if ( ray->side_dist_x < ray->side_dist_y )
				ray->map_x -= ray->step_x;
			else
				ray->map_y -= ray->step_y;
			ray->hit = 2;
		}
		else if ( game->map.content[ ray->map_y ][ ray->map_x ] == WALL )
			ray->hit = 1;
	}
}

void launch_one_ray( int ray_x, t_game *game )
{
	t_ray ray;
	float camera_x;

	ray.pos_x = ray_x;
	camera_x = 2 * ray_x / (float)game->screen.width - 1;
	ray.dir_x = game->camera.dir_x + game->camera.plan_x * camera_x;
	ray.dir_y = game->camera.dir_y + game->camera.plan_y * camera_x;
	ray.map_x = (int)floor( game->camera.pos_x );
	ray.map_y = (int)floor( game->camera.pos_y );
	if ( ray.dir_x == 0 )
		ray.delta_dist_x = 1e30;
	else
		ray.delta_dist_x = fabsf( 1 / ray.dir_x );
	if ( ray.dir_y == 0 )
		ray.delta_dist_y = 1e30;
	else
		ray.delta_dist_y = fabsf( 1 / ray.dir_y );
	if ( ray.dir_x < 0 )
	{
		ray.step_x = -1;
		ray.side_dist_x = ( game->camera.pos_x - ray.map_x ) * ray.delta_dist_x;
	}
	else
	{
		ray.step_x = 1;
		ray.side_dist_x =
			( ray.map_x + 1.0 - game->camera.pos_x ) * ray.delta_dist_x;
	}
	if ( ray.dir_y < 0 )
	{
		ray.step_y = -1;
		ray.side_dist_y = ( game->camera.pos_y - ray.map_y ) * ray.delta_dist_y;
	}
	else
	{
		ray.step_y = 1;
		ray.side_dist_y =
			( ray.map_y + 1.0 - game->camera.pos_y ) * ray.delta_dist_y;
	}
	ray_move( &ray, game );
	if ( ray.side )
		ray.perp_wall_dist = ( ray.side_dist_y - ray.delta_dist_y );
	else
		ray.perp_wall_dist = ( ray.side_dist_x - ray.delta_dist_x );
	draw_ray_wall( &ray, game );
}
