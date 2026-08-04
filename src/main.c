/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:06:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/04 18:03:50 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "initialise.h"
#include "key.h"
#include "struct.h"

void bruteforce_map(t_game *game)
{
	game->map = (t_map){.width = 5, .height = 3};
	game->map.content = malloc(3 * sizeof(int *));
	for (int i = 0; i < 4; i++)
	{
		game->map.content[i] = malloc(5 * sizeof(int));
	}
	game->map.content[0][0] = WALL;
	game->map.content[0][1] = WALL;
	game->map.content[0][2] = WALL;
	game->map.content[0][3] = WALL;
	game->map.content[0][4] = WALL;
	game->map.content[1][0] = WALL;
	game->map.content[1][1] = VOID;
	game->map.content[1][2] = VOID;
	game->map.content[1][3] = VOID;
	game->map.content[1][4] = WALL;
	game->map.content[2][0] = WALL;
	game->map.content[2][1] = WALL;
	game->map.content[2][2] = WALL;
	game->map.content[2][3] = WALL;
	game->map.content[2][4] = WALL;
	
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			printf("%d", game->map.content[y][x]);
		}
		printf("\n");
	}
}

void	update(void *ptr_game)
{
	t_game	*game;

	game = (t_game *)ptr_game;
	launch_ray(game);
}

int main()
{
	t_game	game;
	
	bruteforce_map(&game);
	initialise_game(&game);
	mlx_add_loop_hook(game.screen.mlx, update, &game);
	mlx_on_event(game.screen.mlx, game.screen.win, MLX_KEYDOWN, keydown_hook, &game);
	mlx_on_event(game.screen.mlx, game.screen.win, MLX_KEYUP, keyup_hook, &game);
	mlx_on_event(game.screen.mlx, game.screen.win, MLX_WINDOW_EVENT, window_hook, &game);
	mlx_loop(game.screen.mlx);
	return (0);
}
