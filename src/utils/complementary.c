/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complementary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:13:40 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/31 15:57:10 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	hilo(int a, int b, int c)
{
	int	tmp;

	if (c < b)
	{
		tmp = b;
		b = c;
		c = tmp;
	}
	if (b < a)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (c < a)
	{
		tmp = c;
		a = c;
		c = tmp;
	}
	return (a + c);
}

mlx_color	complement(mlx_color color)
{
	int			k;
	mlx_color	comp_color;

	k = hilo(color.r, color.g, color.b);
	comp_color = (mlx_color){.r = k - color.r, .g = k - color.g, .b = k
		- color.b, .a = 0xFF};
	return (comp_color);
}
