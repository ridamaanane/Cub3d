#include "parsing.h"

int	is_map_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			continue;
		}
		if (is_valid_map_char(line[i]))
			return (1);
		i++;
	}
	return (0);
}

void check_allowed_characters(t_game *game)
{
	int (i), (j);

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_valid_map_char(game->map[i][j]) && game->map[i][j] != '\n')
			{
				printf("Error\nInvalid character in map\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void store_map_line(t_game *game, char *line)
{
	char *cleaned_line;

	cleaned_line = clean_line(line);
	game->map = resize_map(game->map, game->map_height); //add the space for new line
	game->map[game->map_height] = cleaned_line;  //game->map_height(index)
	game->map_height++;
}

void parse_map(t_game *game, int fd)
{
	char *line;

	game->map_started = 0; //map has not started yet
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!game->map_started)
		{
			if (is_empty_line(line))
				continue;
			else if (is_identifier(line))
				parse_identifier(game, line);
			else if (is_map_line(line))
			{
				game->map_started = 1;
				store_map_line(game, line);
			}
			else
			{
				printf("Error\nInvalid line in file\n");
				exit(1);
			}
		}
		else
		{
			if (is_map_line(line))
				store_map_line(game, line);
			else if (is_empty_line(line))
				break;
			else
			{
				printf("Error\nInvalid line after map started\n");
				exit(1);
			}
		}
	}
	check_allowed_characters(game);
	check_the_borders(game);
	check_side_borders(game);
	find_player_pos(game);
}

