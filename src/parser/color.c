/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:18:29 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/08 12:34:59 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	*fetch_colors(char *str, char **content)
{
	int		i;
	int		*res;
	char	*base;
	char	**s_base;

	i = 0;
	res = NULL;
	base = fetch_path(str, content);
	s_base = ft_split(base, ',');
	while (s_base[i])
	{
		res[i] = ft_atoi(s_base[i]);
		i++;
	}
	return (res);
}
