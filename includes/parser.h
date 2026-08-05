/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:43:10 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/05 17:24:32 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"
# include "get_next_line.h"
# include <fcntl.h>

int		main_parser(int ac, char **av, t_game *game);
char	*fetch_path(int fd, char *str);

#endif
