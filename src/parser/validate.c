/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:59:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/09/03 14:37:48 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	test_line(char ***sj_line, char ***s_line)
{
	if (!(*sj_line))
	{
		free_tab(s_line);
		return (0);
	}
	if (!ft_strncmp((*s_line)[0], (*sj_line)[0], ft_strlen((*s_line)[0])))
	{
		free_tab(s_line);
		free_tab(sj_line);
		return (0);
	}
	return (1);
}

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
			if (!test_line(&sj_line, &s_line))
				return (0);
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
	if (!is_double(file_content, *start))
		return (error("A keyword is duplicated in your file\n(-_(-_-)_-)"));
	*start = 6;
	if (!file_content[*start])
		return (error("Where is your map ?\n¯\\(°_o)/¯"));
	return (1);
}
