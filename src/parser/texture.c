/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:32:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/06 18:57:54 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"

char	*fetch_path(int fd, char *str)
{
	char	*line;
	char	*res;
	char	**s_line;

	res = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		s_line = ft_split(line, ' ');
		if (!s_line)
			return ((char *)(size_t)error("Malloc has failed\n"
				"Everything is fine\n☉ ‿ ⚆"));
		if (!s_line[0] && !s_line[1])
			continue ;
		if (ft_strncmp(str, s_line[0], ft_strlen(s_line[0])) == 0)
		{
			res = ft_calloc(ft_strlen(s_line[1]) + 1, sizeof(char));
			ft_strlcpy(res, s_line[1], ft_strlen(s_line[1]) + 1);
		}
	}
	return (res);
}

int	set_textures(t_game *game, char **av)
{
	(void)game;
	(void)av;
	return (1);
}
