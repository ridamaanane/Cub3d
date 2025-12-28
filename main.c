#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_game game;
    int fd;

    if (argc != 2)
    {
        printf("Usage: %s <map_file.cub>\n", argv[0]);
        return 1;
    }

    // Initialize struct
    game.map = NULL;
    game.map_height = 0;
    game.map_started = 0;
    game.tex.no = NULL;
    game.tex.so = NULL;
    game.tex.we = NULL;
    game.tex.ea = NULL;
    game.colors.floor = -1;
    game.colors.ceiling = -1;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
    check_file_extension(argv[1]);
    parse_map(&game, fd);
    close(fd);

    printf("Textures:\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n",
           game.tex.no, game.tex.so, game.tex.we, game.tex.ea);
    printf("Colors: Floor: %d, Ceiling: %d\n", 
           game.colors.floor, game.colors.ceiling);
    printf("Player: x=%d, y=%d, dir=%c\n", 
           game.player.x, game.player.y, game.player.dir);
    printf("Map (%d lines):\n", game.map_height);
    for (int i = 0; i < game.map_height; i++)
        printf("%s\n", game.map[i]);
    free_game(&game);   
}
