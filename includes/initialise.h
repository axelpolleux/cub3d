/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:40:34 by lchamard          #+#    #+#             */
/*   Updated: 2026/08/11 17:07:59 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALISE_H
# define INITIALISE_H

# include "mlx.h"
# include "struct.h"
# include "libft.h"
# include <sys/time.h>

void	initialise_screen(t_screen *screen);
void	initialise_rules(t_rules *rules);
void	initialise_game(t_game *game);

#endif
