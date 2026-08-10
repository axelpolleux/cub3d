/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:43:10 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/09 19:11:16 by apolleux         ###   ########.fr       */
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
int		init_game(t_game *game, char **file_content);

// checking game fundamentals
int		check_file(char **av);
int		check_folder(char **av);

// checking and setting graphical parts
int		set_textures(t_game *game, char **file_content);
int		set_map(t_game *game, char **file_content);
int		set_colors(t_game *game, char **file_content);

// getting information from defined source
char	*fetch_path(char *str, char **content);
int		*fetch_colors(char *str, char **content);
char	**fetch_content(int fd);

// utils functions for my parser
void	free_tab(char ***tab);

#endif
