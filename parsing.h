/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <ridamaanane@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:06:56 by rmaanane          #+#    #+#             */
/*   Updated: 2025/10/04 16:50:16 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64
# define ESC_KEY 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100


typedef struct s_textures
{
    char *no; // North texture path
    char *so; // South texture path
    char *we; // West texture path
    char *ea; // East texture path
}   t_textures;

typedef struct s_colors
{
    int floor;    // store as single int: (R << 16 | G << 8 | B)
    int ceiling;
} t_colors;

typedef struct s_game
{
    t_textures tex;
	t_colors colors;
    // later you’ll add: colors, map, player, etc
}   t_game;





#endif
