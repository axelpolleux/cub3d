/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:32:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/08 13:31:33 by apolleux         ###   ########.fr       */
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

void	set_textures(t_game *game, char **file_content)
{
	t_texture	*base;

	base->north_face.content = fetch_path("NO", file_content);

}