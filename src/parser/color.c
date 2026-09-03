/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:18:29 by apolleux          #+#    #+#             */
/*   Updated: 2026/09/03 15:23:15 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static	int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	fill_base(int **res, char ***s_base)
{
	int	i;

	i = 0;
	*res = ft_calloc(3, sizeof(int));
	while ((*s_base)[i] && i < 3)
	{
		if (!check_digit((*s_base)[i]))
		{
			free(*res);
			free_tab(s_base);
			return (0);
		}
		(*res)[i] = ft_atoi((*s_base)[i]);
		if ((*res)[i] < 0 || (*res)[i] > 255)
		{
			free(*res);
			free_tab(s_base);
			return (0);
		}
		i++;
	}
	return (1);
}

int	*fetch_colors(char *str, char **content)
{
	int		*res;
	char	*base;
	char	**s_base;

	base = fetch_path(str, content);
	if (!base)
	{
		free(base);
		return (0);
	}
	s_base = ft_split(base, ',');
	free(base);
	if (!s_base || len_tab(s_base) != 3)
	{
		free_tab(&s_base);
		return (NULL);
	}
	if (!fill_base(&res, &s_base))
		return (0);
	free_tab(&s_base);
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
