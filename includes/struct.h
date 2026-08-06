/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:38:03 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/06 12:36:38 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <SDL2/SDL_scancode.h>
# include "mlx.h"

typedef enum e_cell
{
	VOID,
	WALL
}	t_cell;

typedef struct	s_map
{
	int				**content;
	int	width;
	int	height;
}	t_map;

typedef	struct	s_rules
{
	float	mov_speed;
	float	rot_speed;
}	t_rules;

typedef struct s_ray
{
	int		pos_x;
	float	dir_x;
	float	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	perp_wall_dist;
	float	line_height;
	int		draw_start;
	int		draw_end;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_image
{
	mlx_image	content;
	int			width;
	int			height;
}	t_image;

typedef struct s_textures
{
	mlx_color	ground_color;
	mlx_color	sky_color;
	t_image		north_face;
	t_image		south_face;
	t_image		west_face;
	t_image		east_face;
}	t_textures;

typedef struct s_screen
{
	mlx_context				mlx;
	mlx_window_create_info	win_info;
	mlx_window				win;
	mlx_image				img;
	int						height;
	int						width;
	mlx_color				*frame_buffer;
}	t_screen;

typedef struct	s_camera
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plan_x;
	float	plan_y;
}	t_camera;

typedef struct	s_game
{
	bool			key_table[SDL_NUM_SCANCODES];
	bool			running;
	int				new_time;
	int				old_time;
	t_map			map;
	t_rules			rules;
	t_textures		textures;
	t_camera		camera;
	t_screen		screen;
}	t_game;

#endif
