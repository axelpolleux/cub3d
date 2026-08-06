/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:43:10 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/06 18:51:23 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"
# include "get_next_line.h"
# include <fcntl.h>

int		main_parser(int ac, char **av, t_game *game);
int		error(char *str);
char	*fetch_path(int fd, char *str);
int		check_files(char **av);
int		check_folder(char **av);
int		set_textures(t_game *game, char **av);

#endif
