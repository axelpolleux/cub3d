/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:27:08 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/06 18:48:15 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	check_files(char **av)
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
				" seriously ?"));
	}
	return (1);
}
