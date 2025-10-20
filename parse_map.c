#include "parsing.h"

int	line_not_empty(char *line)
{
	int	i = 0;

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (1); //mean “This line is not empty.”
		i++;
	}
	return (0);
}
void add_map_line(t_game *game, char *line)
{
    game->map[game->map_count] = ft_strdup(line);
    game->map_count++;
}

void parse_color_line(char *line, t_game *game)
{
    if (ft_strncmp(line, "F ", 2) == 0)
    {
        game->colors.floor = parse_color(line + 2); // store in t_colors
    }
    else if (ft_strncmp(line, "C ", 2) == 0)
    {
        game->colors.ceiling = parse_color(line + 2); // store in t_colors
    }
    else
    {
        printf("Error\nInvalid color line\n");
        exit(1);
    }
}


void parse_map(t_game *game, int fd, char *line)
{
    int capacity = 64; // initial capacity
    game->map = malloc(sizeof(char *) * capacity);
    if (!game->map)
    {
        perror("malloc");
        exit(1);
    }
    add_map_line(game, line);
    free(line); // free the original

    //Read rest of lines until EOF
    while ((line = get_next_line(fd)) != NULL)
    {
        // Skip empty lines (only spaces/newline)
        if (!line_not_empty(line))
        {
            free(line); // free GNL buffer for empty line
            continue;   // skip to next line
        }

        //Grow array if needed
        if (game->map_count + 1 >= capacity) // +1 for final NULL
        {
            capacity *= 2; // double the capacity
            char **tmp = realloc(game->map, sizeof(char *) * capacity); //we do realloc to resize existing memory
            if (!tmp)
            {
                perror("realloc failed");
                exit(1);
            }
            game->map = tmp;
        }

        //Store this line in the map array
        add_map_line(game, line);
        // free original line
        free(line);
    }
}