/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:06:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/05 10:34:29 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!main_parser(argc, argv, &game))
		return (1);
	return (0);
}
