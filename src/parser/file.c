/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:27:08 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/31 14:47:58 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

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

char	**fetch_content(int fd)
{
	char	*base;
	char	*line;
	char	**res;

	res = 0;
	base = ft_strdup("");
	if (!base)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		base = ft_strjoin(base, line);
		base = ft_strjoin(base, "\n");
		if (!base)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	res = ft_split(base, '\n');
	free(base);
	return (res);
}
