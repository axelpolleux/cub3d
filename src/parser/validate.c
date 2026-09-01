/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:59:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/09/01 18:07:57 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

// static int	is_flag(char *str, char **flags)
// {
// 	int	i;
//
// 	i = 0;
// 	while (flags[i])
// 	{
// 		if (ft_strlen(str) == ft_strlen(flags[i])
// 			&& ft_strncmp(str, flags[i], ft_strlen(str)) == 0)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
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

/*static int	is_map(char **file_content)
{
	// checker les lignes où il y a uniquement des '1' et/ou '0'
	(void)file_content;
	return (1);
}*/

static int	is_double(char **file_content)
{
	int		i;
	int		j;
	char	**s_line;
	char	**sj_line;

	i = 0;
	while (file_content[i])
	{
		s_line = ft_split(file_content[i], ' ');
		if (!s_line)
			return (1);
		j = i + 1;
		while (file_content[j])
		{
			sj_line = ft_split(file_content[j], ' ');
			if (!sj_line)
				return (0);
			if (!ft_strncmp(s_line[0], sj_line[0], ft_strlen(s_line[0])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_keys(char **file_content, int *start)
{
	(void)start;
	if (!is_double(file_content))
		return (error("A keyword is duplicated in your file\n(-_(-_-)_-)"));
	/*if (!is_map(file_content))
		return (error("Where is your map ?\nò_ô"));*/
	return (1);
}
