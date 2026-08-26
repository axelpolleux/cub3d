/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:43:10 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/26 18:06:48 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"
# include "get_next_line.h"
# include <fcntl.h>

// main part for parser to get started
int		main_parser(int ac, char **av, t_game *game);
int		error(char *str);

// initialising ready-game for renderer
int		init_game(int start_map, t_game *game, char **file_content);
void	init_player(t_game *game, char str);

// checking game fundamentals
int		check_file(char **av);
int		check_folder(char **av);
int		check_keys(char **file_content, int *start);

// checking and setting graphical parts
int		set_textures(t_game *game, char **file_content);
int		set_map(int start_map, t_game *game, char **file_content);
int		set_colors(t_game *game, char **file_content);

// getting information from defined source
char	*fetch_path(char *str, char **content);
int		*fetch_colors(char *str, char **content);
char	**fetch_content(int fd);

// utils functions for my parser
void	free_tab(char ***tab);

#endif
