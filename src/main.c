/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:06:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/04 16:17:01 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"

int main(int argc, char *argv[])
{
	t_game	game;

	(void)game;
	// Parsing here, he define the map
	
	// Key hook here, he look the key, logic
	if (!main_parser(argc, argv, &game))
		return (1);
	return (0);


}
