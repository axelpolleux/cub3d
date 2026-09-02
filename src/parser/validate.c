/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:59:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/09/02 17:21:19 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

// int	not_this_char(char **map, char *chars)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			j++;
// 			if (ft_strchr(chars, map[i][j]) == 0)
// 				return (error("Character not accepted"));
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// static int	is_map(char **file_content)
// {
// 	int	i;
//
// 	i = 0;
// 	while (file_content[i])
// 	{
// 		printf("line %d\n[%s]", i, file_content[i]);
// 		if (ft_strchr(file_content[i], '0') || ft_strchr(file_content[i], '1'))
// 			return (i+1);
// 		i++;
// 	}
// 	return (1);
// }

// static int	is_blank(char *line)
// {
// 	int	i;
//
// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] != ' ' && line[i] != '\t')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

static int	is_double(char **file_content, int start_map)
{
	int		i;
	int		j;
	char	**s_line;
	char	**sj_line;

	i = 0;
	while (file_content[i] && i < start_map)
	{
		s_line = ft_split(file_content[i], ' ');
		if (!s_line)
			return (0);
		j = i + 1;
		while (file_content[j] && j < start_map)
		{
			sj_line = ft_split(file_content[j], ' ');
			if (!sj_line)
			{
				free_tab(&s_line);
				return (0);
			}
			if (!ft_strncmp(s_line[0], sj_line[0], ft_strlen(s_line[0])))
			{
				free_tab(&s_line);
				free_tab(&sj_line);
				return (0);
			}
			free_tab(&sj_line);
			j++;
		}
		free_tab(&s_line);
		i++;
	}
	return (1);
}

int	check_keys(char **file_content, int *start)
{
	*start = 6;
	if (!file_content[])
	if (!is_double(file_content, *start))
		return (error("A keyword is duplicated in your file\n(-_(-_-)_-)"));
	return (1);
}
