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
		if (!is_valid_map_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void check_allowed_characters(t_game *game)
{
	int (i), (j);

	i = 0;
	if (!game->map)
		exit_error("Error\nEmpty Map");
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_valid_map_char(game->map[i][j]) && game->map[i][j] != '\n')
				exit_error("Error\nInvalid character in map");
			j++;
		}
		i++;
	}
}

void store_map_line(t_game *game, char *line)
{
	char *cleaned_line;

	cleaned_line = clean_line(line);
	free(line);
	game->map = resize_map(game->map, game->map_height); //add the space for new line
	game->map[game->map_height] = cleaned_line;  //game->map_height(index)
	game->map_height++;
	free(cleaned_line);
}

void init_struct(t_game *game)
{
	game->tex.identifiers_count = 0;
	game->colors.color_count = 0;
	game->tex.got_no = 0;
	game->tex.got_so = 0;
	game->tex.got_we = 0;
	game->tex.got_ea = 0;
	game->colors.got_floor = 0;
	game->colors.got_ceiling = 0;
	game->map_started = 0;
}

void parse_map(t_game *game, int fd)
{
	char *line;

	init_struct(game);
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
				exit_error("Error\nInvalid identifier or map line");
		}
		else
		{
			if (is_map_line(line))
				store_map_line(game, line);
			else if (is_empty_line(line))
				break;
			else
				exit_error("Error\nInvalid line after map started");
		}
	}
	if (game->tex.identifiers_count != 4 || game->colors.color_count != 2)
		exit_error("Error\nInvalid number of identifiers (need 4 textures (NO, SO, EA, WE) and 2 colors (F , C))");
	check_path_textures(game);
	check_allowed_characters(game);
	check_the_borders(game);
	check_side_borders(game);
	find_player_pos(game);
}

