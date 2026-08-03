#ifndef STRUCT_H
# define STRUCT_H

# include "stdbool.h"

typedef enum e_map
{
	VOID,
	WALL
}			t_map;

typedef struct	s_map
{
	int				**content;
	unsigned int	width;
	unsigned int	height;
}				t_map;

typedef	struct	s_rules
{
	float	mov_speed;
	float	rot_speed;
}

typedef struct	s_camera
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}				t_camera;

typedef struct	s_game
{
	t_map			map;
	unsigned int	swidth;
	unsigned int	sheight;
	t_rules			rules;
	float			delta_time;
	bool			running;
}				t_game;

#endif
