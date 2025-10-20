#include "parsing.h"

void init_game(t_game *game)
{
    game->map = malloc(sizeof(char *) * 1000); // reserve space for up to 1000 map lines (adjust later)
    game->map_count = 0;
    game->map_height = 0;
    game->map_width = 0;
}