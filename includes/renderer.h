/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:33:56 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/11 14:33:57 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "libft.h"
# include <math.h>
# include "utils.h"
# include <sys/time.h>
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
