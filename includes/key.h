#ifndef KEY_H
# define KEY_H

# include "mlx.h"
# include "struct.h"
# include <math.h>

void	key_move(t_game *game);
void	keyup_hook(int keycode, void *game_ptr);
void	keydown_hook(int keycode, void *game_ptr);
void	window_hook(int event, void *game_ptr);

#endif
