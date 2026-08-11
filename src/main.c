/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:09:13 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/11 18:09:14 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"
#include "key.h"
#include "libft.h"
#include "parser.h"
#include "renderer.h"
#include "struct.h"

void	bruteforce_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->map = (t_map){.width = 200, .height = 200};
	game->map.content = malloc(game->map.height * sizeof(int *));
	while (y < game->map.height)
	{
		x = 0;
		game->map.content[y] = malloc(game->map.width * sizeof(int));
		while (x < game->map.width)
		{
			if (x == 0 || y == 0 || x == game->map.width - 1
				|| y == game->map.height - 1)
				game->map.content[y][x] = WALL;
			else
				game->map.content[y][x] = VOID;
			x++;
		}
		y++;
	}
}

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		free(game->map.content[y]);
		y++;
	}
	free(game->map.content);
}

void	update(void *ptr_game)
{
	t_game	*game;

	game = (t_game *)ptr_game;
	key_move(game);
	key_rot(game);
	key_escape(game);
	launch_ray(game);
}

void	main_loop(t_game *game)
{
	mlx_add_loop_hook(game->screen.mlx, update, game);
	mlx_on_event(game->screen.mlx, game->screen.win, MLX_KEYDOWN, keydown_hook,
		game);
	mlx_on_event(game->screen.mlx, game->screen.win, MLX_KEYUP, keyup_hook,
		game);
	mlx_on_event(game->screen.mlx, game->screen.win, MLX_WINDOW_EVENT,
		window_hook, game);
	mlx_loop(game->screen.mlx);
	mlx_destroy_image(game->screen.mlx, game->screen.draw_img);
	free(game->screen.frame_buffer);
	mlx_destroy_image(game->screen.mlx, game->textures.north_face.content);
	mlx_destroy_image(game->screen.mlx, game->textures.south_face.content);
	mlx_destroy_image(game->screen.mlx, game->textures.east_face.content);
	mlx_destroy_image(game->screen.mlx, game->textures.west_face.content);
	mlx_destroy_window(game->screen.mlx, game->screen.win);
	mlx_destroy_context(game->screen.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.screen.mlx = mlx_init();
	if (!game.screen.mlx)
		return (1);
	if (!main_parser(argc, argv, &game))
		return (1);
	bruteforce_map(&game);
	initialise_game(&game);
	launch_ray(&game);
	main_loop(&game);
	free_map(&game);
	return (0);
}
