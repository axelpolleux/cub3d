/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:40:40 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/07 16:44:25 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "array.h"
# include "libft.h"
# include "math.h"
# include "mlx_extended.h"
# include "struct.h"
# include <stdio.h>
# include <stdlib.h>

void	draw_ray_wall(t_ray *ray, t_game *game);
void	draw_sky_and_ground(t_ray *ray, t_game *game);
void	draw_line(t_ray *ray, t_game *game);
void	launch_ray(t_game *game);
void	launch_one_ray(int ray_x, t_game *game);

#endif
