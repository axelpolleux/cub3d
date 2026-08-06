#ifndef ARRAY_H
# define ARRAY_H

# include "mlx.h"
# include "struct.h"

mlx_color	get_arrays(mlx_color *arrays, int x, int y, int width);
void		set_arrays(mlx_color *arrays, int x, int y, int width, mlx_color value);

#endif
