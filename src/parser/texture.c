/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:03:07 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/09 19:39:17 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "struct.h"
#include "mlx.h"

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
			return (NULL);
		if (!s_line[0])
		{
			free_tab(&s_line);
			i++;
			continue ;
		}
		if (s_line[1] && (ft_strlen(str) == ft_strlen(s_line[0]))
			&& ft_strncmp(str, s_line[0], ft_strlen(str)) == 0)
		{
			res = ft_calloc(ft_strlen(s_line[1]) + 1, sizeof(char));
			if (!res)
			{
				free_tab(&s_line);
				break ;
			}
			ft_strlcpy(res, s_line[1], ft_strlen(s_line[1]) + 1);
			free_tab(&s_line);
			break ;
		}
		free_tab(&s_line);
		i++;
	}
	return (res);
}

t_image	load(char *path, mlx_context mlx)
{
	int			fd;
	t_image		img;

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
	char		*path;
	mlx_context	context;

	path = fetch_path(search, file_content);
	if (!path)
	{
		ft_putstr_fd("ʕノ•ᴥ•ʔノ ︵ ┻━┻\n"
			"You were the chosen one\n", 2);
		return (0);
	}
	context = game->screen.mlx;
	*img = load(path, context);
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
	t_texture	*base;

	base = &game->textures;
	if (!set_image(game, &base->north_face, "NO", file_content))
		return (error("North texture missing !"));
	if (!set_image(game, &base->south_face, "SO", file_content))
		return (error("South texture missing !"));
	if (!set_image(game, &base->east_face, "EA", file_content))
		return (error("East texture missing !"));
	if (!set_image(game, &base->west_face, "WE", file_content))
		return (error("West texture missing !"));
	return (1);
}
