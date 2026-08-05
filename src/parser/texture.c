/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:32:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/05 19:10:11 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"


char	*fetch_path(int fd, char *str)
{
	int		len;
	char	*line;

	len = ft_strlen(str);
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) <= len)
		{

		}
	}
	return (0);
}
