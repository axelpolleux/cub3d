/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:29:44 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/07 14:20:12 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

mlx_color	get_arrays(mlx_color *arrays, t_vec2 pos, int width)
{
	return (arrays[pos.y * width + pos.x]);
}

void	set_arrays(mlx_color *arrays, t_vec2 pos, int width, mlx_color value)
{
	arrays[pos.y * width + pos.x] = value;
}
