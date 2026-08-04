/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:06:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/04 13:06:44 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "renderer.h"
#include "key.h"
#include "struct.h"

int main(int argc, char *argv[])
{
	t_game	game;
	
	initialise_game(&game);

	// Parsing here, he define the map
	
	// Key hook here, he look the key, logic
	
	launch_ray(game);
	

}
