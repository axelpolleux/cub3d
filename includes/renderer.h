#ifndef RENDERER_H
# define RENDERER_H

# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include "math.h"

void	launch_ray(t_game *game);
void	launch_one_ray(int ray_x, t_game *game);

#endif
