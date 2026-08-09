/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:18:29 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/09 19:58:38 by apolleux         ###   ########.fr       */
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
	s_base = ft_split(base, ',');
	while (s_base[i] && i < 3)
	{
		res[i] = ft_atoi(s_base[i]);
		i++;
	}
	return (res);
}

int	set_colors(t_game *game, char **file_content)
{
	int	*base;

	base = fetch_colors("F", file_content);
	printf("---Floor color---\n"
					"Red: %d\n"
					"Green: %d\n"
					"Blue: %d\n", base[0], base[1], base[2]);

	base = fetch_colors("C", file_content);
	printf("---Sky color---\n"
					"Red: %d\n"
					"Green: %d\n"
					"Blue: %d\n", base[0], base[1], base[2]);

	(void)game;
	(void)file_content;
	return (1);
}
