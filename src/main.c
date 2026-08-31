/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:09:13 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/31 17:29:37 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"
#include "key.h"
#include "libft.h"
#include "parser.h"
#include "renderer.h"
#include "struct.h"

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
	initialise_game(&game);
	main_loop(&game);
	free(game.map.content);
	return (0);
}
