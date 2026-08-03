/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/03 18:34:47 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"

void	initialise_camera(t_game *game)
{

}

void	initialise_rules(t_game *game)
{

}

void	initialise_map(t_game *game)
{

}

void	initialise_game(t_game *game)
{
	initialise_camera(game->camera);
	initialise_rules(game->camera);
	initialise_map(game->camera);
}
