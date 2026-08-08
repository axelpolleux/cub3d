/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:38:08 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/08 12:35:43 by apolleux         ###   ########.fr       */
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

static	int	check_args(int ac)
{
	if (ac > 2)
		return (error("ヽ༼ຈʖ̯ຈ༽ﾉ\nWOW calm down !!\nI just need one argument"));
	else if (ac < 2)
		return (error("You don't wanna talk ?\n⊙ω⊙\nGive me one argument"));
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main_parser(int ac, char **av, t_game *game)
{
	int		fd;
	char	**file_content;

	if (!check_args(ac) || !check_file(av) || !check_folder(av))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error("I can't open your file\nskill issue !\n(ง •̀_•́)ง"));
	file_content = fetch_content(fd);
	close(fd);
	if (!init_game(game, file_content))
		return (0);
	free_tab(file_content);
	return (1);
}
