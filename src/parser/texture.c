/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:03:07 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/31 19:16:45 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"
#include "mlx.h"

static char	*match_line(char *str, char *line)
{
	char	*res;
	char	**s_line;

	res = NULL;
	s_line = ft_split(line, ' ');
	if (!s_line || len_tab(s_line) != 2)
	{
		free_tab(&s_line);
		return (NULL);
	}
	if (s_line[0] && s_line[1] && ft_strlen(str) == ft_strlen(s_line[0])
		&& ft_strncmp(str, s_line[0], ft_strlen(str)) == 0)
	{
		res = ft_calloc(ft_strlen(s_line[1]) + 1, sizeof(char));
		if (res)
			ft_strlcpy(res, s_line[1], ft_strlen(s_line[1]) + 1);
	}
	free_tab(&s_line);
	return (res);
}

char	*fetch_path(char *str, char **content)
{
	int		i;
	char	*res;

	i = 0;
	while (content[i])
	{
		res = match_line(str, content[i]);
		if (res)
			return (res);
		i++;
	}
	return (NULL);
}

t_image	load(char *path, mlx_context mlx)
{
	int		fd;
	t_image	img;

	fd = open(path, O_RDONLY);
	if (fd > 0)
	{
		img.content = mlx_new_image_from_file(mlx, path,
				&img.width, &img.height);
		close(fd);
	}
	else
		img.content = 0;
	return (img);
}

int	set_image(t_game *game, t_image *img, char *search, char **file_content)
{
	char	*path;

	path = fetch_path(search, file_content);
	if (!path)
		return (0);
	*img = load(path, game->screen.mlx);
	if (!img->content)
	{
		free(path);
		return (0);
	}
	free(path);
	return (1);
}

int	set_textures(t_game *game, char **file_content)
{
	t_textures	*base;

	base = &game->textures;
	if (!set_image(game, &base->north_face, "NO", file_content))
		return (error("North texture missing !\nʕノ•ᴥ•ʔノ ︵ ┻━┻"));
	if (!set_image(game, &base->south_face, "SO", file_content))
		return (error("South texture missing !\n(︶︹︶)"));
	if (!set_image(game, &base->east_face, "EA", file_content))
		return (error("East texture missing !\n┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻"));
	if (!set_image(game, &base->west_face, "WE", file_content))
		return (error("West texture missing !\n༼つಠ益ಠ༽つ ─=≡ΣO))"));
	return (1);
}
