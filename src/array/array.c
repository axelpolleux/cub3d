/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:29:44 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/06 13:03:04 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

mlx_color	get_arrays(mlx_color *arrays, int x, int y, int width)
{
	return (arrays[y * width + x]);
}

void	set_arrays(mlx_color *arrays, int x, int y, int width, mlx_color value)
{
	arrays[y * width + x] = value;
}
