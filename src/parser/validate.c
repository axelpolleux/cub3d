/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:59:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/26 16:54:59 by apolleux         ###   ########.fr       */
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
//
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

int	check_keys(char **file_content, int *start)
{
	(void)file_content;
	(void)start;
	/*int		i;
	char	**flags;

	i = 0;
	flags = (char *[]){"NO", "SO", "WE", "EA", "F", "C", NULL};
	(void)start;
	while (file_content[i])
	{
		printf("%s", file_content[i]);
		i++;
	}*/
	return (1);
}
