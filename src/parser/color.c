/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:18:29 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/10 18:27:48 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

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
	while (s_base[i] && i < 3)
	{
		res[i] = ft_atoi(s_base[i]);
		i++;
	}
	free_tab(&s_base);
	free(base);
	return (res);
}

int	set_colors(t_game *game, char **file_content)
{
	int			*color;
	t_texture	*base;

	base = &game->textures;
	color = fetch_colors("F", file_content);
	if (!color)
		return (error("Not found floor color\n/ᐠ ╥ ˕ ╥マ"));
	base->sky_color = (mlx_color){.r = color[0], .g = color[1],
		.b = color[2], .a = 0xff};
	free(color);
	color = fetch_colors("C", file_content);
	if (!color)
		return (error("Not  found sky color\n(⌐⊙_⊙)\n凸  凸"));
	base->sky_color = (mlx_color){.r = color[0], .g = color[1],
		.b = color[2], .a = 0xff};
	free(color);
	return (1);
}
