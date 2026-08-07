/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:06:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/07 15:53:06 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"
#include "key.h"
#include "libft.h"
#include "renderer.h"
#include "struct.h"

void	bruteforce_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->map = (t_map){.width = 200, .height = 200};
	game->map.content = malloc(200 * sizeof(int *));
	while (y < 200)
	{
		x = 0;
		game->map.content[y] = malloc(200 * sizeof(int));
		while (x < 200)
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

void	bruteforce_textures(char **argv, t_game *game)
{
	game->textures.north_face.content
		= mlx_new_image_from_file(game->screen.mlx, argv[1], NULL, NULL);
	game->textures.north_face.width = 2000;
	game->textures.north_face.height = 2000;
	game->textures.south_face.content
		= mlx_new_image_from_file(game->screen.mlx, argv[2], NULL, NULL);
	game->textures.south_face.width = 2000;
	game->textures.south_face.height = 2000;
	game->textures.east_face.content
		= mlx_new_image_from_file(game->screen.mlx, argv[3], NULL, NULL);
	game->textures.east_face.width = 2000;
	game->textures.east_face.height = 2000;
	game->textures.west_face.content
		= mlx_new_image_from_file(game->screen.mlx, argv[4], NULL, NULL);
	game->textures.west_face.width = 2000;
	game->textures.west_face.height = 2000;
	game->textures.sky_color = (mlx_color){.r = 0, .g = 125, .b = 60, .a = 255};
	game->textures.ground_color.rgba = 0xFFFFFFFF;
}

void	update(void *ptr_game)
{
	t_game	*game;

	game = (t_game *)ptr_game;
	key_move(game);
	key_rot(game);
	key_escape(game);
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
	mlx_destroy_image(game->screen.mlx, game->screen.img);
	mlx_destroy_image(game->screen.mlx, game->textures.north_face.content);
	mlx_destroy_image(game->screen.mlx, game->textures.south_face.content);
	mlx_destroy_image(game->screen.mlx, game->textures.east_face.content);
	mlx_destroy_image(game->screen.mlx, game->textures.west_face.content);
	mlx_destroy_window(game->screen.mlx, game->screen.win);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 5)
		return (1);
	ft_bzero(&game, sizeof(t_game));
	game.screen.mlx = mlx_init();
	bruteforce_map(&game);
	bruteforce_textures(argv, &game);
	initialise_game(&game);
	launch_ray(&game);
	main_loop(&game);
	return (0);
}
