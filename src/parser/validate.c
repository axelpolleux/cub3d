/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:59:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/12 17:04:14 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../includes/parser.h"
#include "../../lib/libft/libft.h"

static	int	find_map_part(char **file_content)
{
	(void)file_content;
	return (0);
}

static int	is_twice(char **file_content)
{
	(void)file_content;
	return (0);
}

static int	is_flag(char *str, char **flags)
{
	int	i;

	(void)str;
	i = 0;
	while (flags[i])
	{
		i++;
	}
	return (1);
}

int	check_keys(char **file_content, int *start)
{
	int		line_i;
	int		used[6];
	char	**flags;
	char	**s_line;

	(void)used;
	line_i = 0;
	*start = find_map_part(file_content);
	flags = (char *[]){"NO", "SO", "WE", "EA", "F", "C"};
	if (is_twice(file_content))
		return (error("Double flag detected"));
	while (file_content[line_i])
	{
		s_line = ft_split(file_content[line_i], ' ');
		if (!s_line)
		{
			free_tab(&s_line);
			return (error("Malloc has failed"));
		}
		if (!is_flag(s_line[0], flags))
		{
			free_tab(&s_line);
			return (error("Invalid string detected"));
		}
		line_i++;
	}
	free_tab(&s_line);
	return (1);
}
