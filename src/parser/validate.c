/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:59:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/26 15:04:11 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "../../includes/parser.h"

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

static int is_flag(char *str, char **flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (ft_strlen(str) == ft_strlen(flags[i])
			&& ft_strncmp(str, flags[i], ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int is_blank(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
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

	line_i = 0;
	*start = find_map_part(file_content);
	flags = (char *[]){"NO", "SO", "WE", "EA", "F", "C", NULL};
	if (is_twice(file_content))
		return (error("Double flag detected"));
	while (file_content[line_i])
	{
		if (is_blank(file_content[line_i]))
		{
			line_i++;
			continue ;
		}
		s_line = ft_split(file_content[line_i], ' ');
		if (!s_line)
			return (error("Malloc has failed"));
		if (!is_flag(s_line[0], flags))
		{
			free_tab(&s_line);
			return (error("Invalid string detected"));
		}
		line_i++;
		free_tab(&s_line);
	}
	return (1);
}
