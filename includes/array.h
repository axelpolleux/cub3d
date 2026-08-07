/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:40:32 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/07 16:46:37 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "mlx.h"
# include "struct.h"

mlx_color	get_arrays(mlx_color *arrays, t_vec2 pos, int width);
void		set_arrays(mlx_color *arrays, t_vec2 pos, int width,
				mlx_color value);

#endif
