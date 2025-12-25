#include "parsing.h"

void check_the_borders(t_game *game)
{
    int j;

    // Check top row
    j = 0;
    while (game->map[0][j])
    {
        if (game->map[0][j] != '1')
        {
            printf("Error\nInvalid top border in map\n");
            exit(1);
        }
        j++;
    }
    // Check bottom row
    j = 0;
    while (game->map[game->map_height - 1][j])
    {
        if (game->map[game->map_height - 1][j] != '1')
        {
            printf("Error\nInvalid bottom border in map\n");
            exit(1);
        }
        j++;
    }
}

void check_side_borders(t_game *game)
{
    int i;
    int last_index;

    i = 1; // skip first row
    while (i < game->map_height - 1) // skip last row
    {
        last_index = ft_strlen(game->map[i]) - 1;

        if (game->map[i][0] != '1' || game->map[i][last_index] != '1')
        {
            printf("Error\nInvalid side borders in map\n");
            exit(1);
        }
        i++;
    }
}
