#include "parsing.h"

char *clean_line(char *line)
{
    int     i;
    char    *new;

    new = malloc(ft_strlen(line) + 1);
    if (!new)
        return (NULL);
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        new[i] = line[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char **resize_map(char **map, int map_height) //make space for the new line + NULL
{
    char **tmp;

    // 1 new line (We reserved the line) + 1 NULL
    tmp = realloc(map, sizeof(char *) * (map_height + 2));
    if (!tmp)
        exit_error("Error\nMemory allocation failed");
    tmp[map_height + 1] = NULL; //tmp[map_height] → this is where we store the new line so + 1 for the NULL
    return tmp;
}

void find_player_pos(t_game *game)
{
    int (i), (j), (player_found);

	player_found = 0;
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
                game->map[i][j] == 'E' || game->map[i][j] == 'W')
            {
                if (player_found)
                    exit_error("Error\nMultiple players!");
                game->player.x = j;
                game->player.y = i;
                game->player.dir = game->map[i][j];
                player_found = 1;
            }
            j++;
        }
        i++;
    }
    if (!player_found)
        exit_error("Error\nNo player found!");
}

void exit_error(char *msg)
{
    ft_putendl_fd(msg, 2);
    exit(1);
}
