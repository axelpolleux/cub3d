/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:32:06 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/05 17:09:06 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parser.h"
// #include "struct.h"

char	*fetch_path(int fd, char *str)
{
	return (0);
}


// int	set_path(t_game *game)
// {
// 	t_texture	texture;
//
// 	texture = game.textures;
// }

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("test", O_RDONLY);
	printf("Nord: %s\n", fetch_path(fd, "NO"));
	printf("Sud: %s\n", fetch_path(fd, "SO"));
	printf("Est: %s\n", fetch_path(fd, "WE"));
	printf("Ouest: %s\n", fetch_path(fd, "EA"));
}