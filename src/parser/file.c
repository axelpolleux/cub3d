/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:27:08 by apolleux          #+#    #+#             */
/*   Updated: 2026/09/04 11:49:39 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	check_empty_line_map(char *base)
{
	int		is_in_map;
	char	*str;

	is_in_map = 0;
	str = base;
	while (*str)
	{
		if (!is_in_map && *str == '\n')
		{
			str++;
			if (*str == ' ' || *str == '1')
				is_in_map = 1;
		}
		if (is_in_map && *str == '\n' && *(str + 1) == '\n')
		{
			free(base);
			return (error("Empty line on the map"));
		}
		str++;
	}
	return (1);
}

int	check_file(char **av)
{
	if (ft_strlen(av[1]) <= 4 || ft_strncmp(av[1] + (ft_strlen(av[1])
				- 4), ".cub", 4) != 0)
		return (error("x⸑x how can you miss it ?\nOnly .cub files"));
	return (1);
}

int	check_folder(char **av)
{
	int	fd;

	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (error("(ᕗ ͠° ਊ ͠° )ᕗ a folder ?\n"
				"seriously ?"));
	}
	return (1);
}

int	get_file_content(char **base, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		*base = ft_strjoin(*base, line);
		*base = ft_strjoin(*base, "\n");
		if (!(*base))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

char	**fetch_content(int fd)
{
	char	*base;
	char	**res;

	res = 0;
	base = ft_strdup("");
	if (!base)
		return (0);
	if (!get_file_content(&base, fd))
		return (0);
	if (!check_empty_line_map(base))
		return (0);
	res = ft_split(base, '\n');
	free(base);
	return (res);
}
