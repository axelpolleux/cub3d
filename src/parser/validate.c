/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:59:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/12 14:57:45 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../includes/parser.h"
#include "../../lib/libft/libft.h"

// static	int	find_map_part(int start, char **file_content)
// {
//
// }

int	check_keys(char **file_content, int *start)
{
	int		line_i;
	char	**flags;
	char	**s_line;

	(void)start;
	line_i = 0;
	flags = (char *[]){"NO", "SO", "WE", "EA", "F", "C"};

	while (file_content[line_i])
	{
		printf("Map parser : %s\n", file_content[line_i]);
		s_line = ft_split(file_content[line_i], ' ');
		if (!s_line)
			return (0);
		line_i++;
	}
	free_tab(&s_line);
	return (1);
}
