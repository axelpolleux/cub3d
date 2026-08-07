/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:32:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/07 18:51:14 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"

char	*fetch_path(char *str, char **content)
{
	int		i;
	char	*line;
	char	*res;
	char	**s_line;

	i = 0;
	res = 0;
	while (content[i])
	{
		line = content[i];
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
		i++;
	}
	return (res);
}

t_image	*set_texture(char *str, char **content)
{
	char	*path;
	t_image	res;

	path = fetch_path(str, content);
	res->content = path;
	return (res);
}