/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:38:03 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/08 17:19:15 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <SDL2/SDL_scancode.h>
# include <stdbool.h>
# include "mlx.h"

typedef enum e_cell
{
	VOID,
	WALL
}	t_cell;

typedef struct	s_map
{
	int				**content;
	unsigned int	width;
	unsigned int	height;
}	t_map;

typedef	struct	s_rules
{
	float	mov_speed;
	float	rot_speed;
}	t_rules;

typedef	struct s_image
{
	mlx_image	content;
	int			width;
	int			height;
}	t_image;

typedef struct s_texture
{
	mlx_color	ground_color;
	mlx_color	sky_color;
	t_image		north_face;
	t_image		south_face;
	t_image		west_face;
	t_image		east_face;
}	t_texture;

typedef struct	s_camera
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plan_x;
	float	plan_y;
}	t_camera;

typedef struct s_screen
{
	mlx_context					mlx;
	mlx_window_create_info		win_info;
	mlx_window					win;
	mlx_image					img;
	int							height;
	int							width;
	mlx_color					*frame_buffer;
}	t_screen;

typedef struct	s_game
{
	bool			key_table[SDL_NUM_SCANCODES];
	bool			running;
	float			new_time;
	float			old_time;
	t_map			map;
	t_rules			rules;
	t_texture		textures;
	t_camera		camera;
	t_screen		screen;
}	t_game;

#endif
