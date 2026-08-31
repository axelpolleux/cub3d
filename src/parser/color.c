/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:18:29 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/31 18:20:36 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int	*fetch_colors(char *str, char **content)
{
	int		i;
	int		*res;
	char	*base;
	char	**s_base;

	i = 0;
	res = ft_calloc(3, sizeof(int));
	base = fetch_path(str, content);
	if (!base)
	{
		free(base);
		free(res);
		return (0);
	}
	s_base = ft_split(base, ',');
	if (!s_base || len_tab(s_base) != 3)
		return (NULL);
	while (s_base[i] && i < 3)
	{
		res[i] = ft_atoi(s_base[i]);
		if (res[i] < 0 || res[i] > 255)
			return (NULL);
		i++;
	}
	free_tab(&s_base);
	free(base);
	return (res);
}

int	set_colors(t_game *game, char **file_content)
{
	int			*color;
	t_textures	*base;

	base = &game->textures;
	color = fetch_colors("F", file_content);
	if (!color)
		return (error("Not found floor color\n/ᐠ ╥ ˕ ╥マ"));
	base->ground_color = (mlx_color){.r = color[0],
		.g = color[1], .b = color[2], .a = 0xff};
	free(color);
	color = fetch_colors("C", file_content);
	if (!color)
		return (error("Not  found sky color\n(⌐⊙_⊙)"));
	base->sky_color = (mlx_color){.r = color[0], .g = color[1], .b = color[2],
		.a = 0xff};
	free(color);
	return (1);
}
