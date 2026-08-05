/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:06:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/05 17:27:32 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"
#include "key.h"
#include "libft.h"
#include "renderer.h"
#include "struct.h"

void	bruteforce_map(t_game *game)
{
	game->map = (t_map){.width = 20, .height = 20};
	game->map.content = malloc(20 * sizeof(int *));
	for (int y = 0; y < 20; y++)
	{
		game->map.content[y] = malloc(20 * sizeof(int));
		for (int x = 0; x < 20; x++)
		{
			if (x == 0 || y == 0 || x == game->map.width - 1
				|| y == game->map.height - 1)
				game->map.content[y][x] = WALL;
			else
				game->map.content[y][x] = VOID;
		}
	}
}

void	update(void *ptr_game)
{
	t_game	*game;

	game = (t_game *)ptr_game;
	key_move(game);
	key_rot(game);
	key_escape(game);
}

int	main(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	bruteforce_map(&game);
	initialise_game(&game);
	mlx_clear_window(game.screen.mlx, game.screen.win, (mlx_color)0u);
	launch_ray(&game);
	mlx_put_image_to_window(game.screen.mlx, game.screen.win, game.screen.img,
		0, 0);
	mlx_add_loop_hook(game.screen.mlx, update, &game);
	mlx_on_event(game.screen.mlx, game.screen.win, MLX_KEYDOWN, keydown_hook,
		&game);
	mlx_on_event(game.screen.mlx, game.screen.win, MLX_KEYUP, keyup_hook,
		&game);
	mlx_on_event(game.screen.mlx, game.screen.win, MLX_WINDOW_EVENT,
		window_hook, &game);
	mlx_loop(game.screen.mlx);
	return (0);
}
