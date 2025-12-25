/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <ridamaanane@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:06:56 by rmaanane          #+#    #+#             */
/*   Updated: 2025/10/13 20:55:10 by rmaanane         ###   ########.fr       */
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

// # define TILE_SIZE 64
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
    char *no;
    char *so; 
    char *we; 
    char *ea;
}   t_textures;

typedef struct s_colors
{
    int floor;
    int ceiling;
} t_colors;

typedef struct s_player
{
    int x;      // column in the map
    int y;      // row in the map
    char dir;   // 'N', 'S', 'E', 'W'
} t_player;

typedef struct s_game
{
    char **map;
    int map_started; 
    int map_height;
    t_textures tex;
	t_colors colors;
    t_player player;
}   t_game;

//parse_color
int is_number(char *str);
int ft_arrlen(char **arr);
int parse_color(char *path);

//parse_map
int	is_map_line(char *line);
void store_map_line(t_game *game, char *line);
void check_allowed_characters(t_game *game);
void parse_map(t_game *game, int fd);

//check_file_extension
int	ft_strcmp(char *s1, char *s2);
void check_file_extension(char *filename);

//utils
char *clean_line(char *line);
char **resize_map(char **map, int map_height);
void find_player_pos(t_game *game);

//utils2
int	is_empty_line(char *line);
int	is_identifier(char *line);
int	is_valid_map_char(char c);
void parse_identifier(t_game *game, char *line);

//utils3
void check_the_borders(t_game *game);
void check_side_borders(t_game *game);

#endif
