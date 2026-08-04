/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:38:08 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/04 16:17:13 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"
#include "libft.h"

int	error(char *str)
{
	ft_putstr_fd("Error !\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	main_parser(int ac, char **av, t_game *game)
{
	int	height;
	int	width;

	(void)height;
	(void)width;
	(void)game;
	if (ac > 2)
		return (error("ヽ༼ຈʖ̯ຈ༽ﾉ\nWOW calm down !!\nI just need one argument"));
	else if (ac < 2)
		return (error("You don't wanna talk ?\n⊙ω⊙\nGive me one argument"));
	if (ft_strlen(av[1]) <= 4 || ft_strncmp(av[1] + (ft_strlen(av[1])
				- 4), ".cub", 4) != 0)
		return (error("x⸑x how can you miss it ?\nOnly .cub files"));
	return (1);
}