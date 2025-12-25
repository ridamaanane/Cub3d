#include "parsing.h"

int	is_empty_line(char *line)
{
	int	i;
    
    i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_identifier(char *line)
{
	if (!line)
		return (0);
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	if (!ft_strncmp(line, "SO ", 3))
		return (1);
	if (!ft_strncmp(line, "WE ", 3))
		return (1);
	if (!ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2))
		return (1);
	if (!ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

int	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

void parse_identifier(t_game *game, char *line)
{
	int i;
	char *path;

	i = 0;
	if (!ft_strncmp(line, "NO", 2))
		i = 2;
	else if (!ft_strncmp(line, "SO", 2))
		i = 2;
	else if (!ft_strncmp(line, "WE", 2))
		i = 2;
	else if (!ft_strncmp(line, "EA", 2))
		i = 2;
	else if (!ft_strncmp(line, "F", 1))
		i = 1;
	else if (!ft_strncmp(line, "C", 1))
		i = 1;
	while (line[i] == ' ')
		i++;
	path = ft_strdup(line + i);

	if (!ft_strncmp(line, "NO", 2))
		game->tex.no = path;
	else if (!ft_strncmp(line, "SO", 2))
		game->tex.so = path;
	else if (!ft_strncmp(line, "WE", 2))
		game->tex.we = path;
	else if (!ft_strncmp(line, "EA", 2))
		game->tex.ea = path;
	else if (!ft_strncmp(line, "F", 1))
		game->colors.floor = parse_color(path);
	else if (!ft_strncmp(line, "C", 1))
		game->colors.ceiling = parse_color(path);
}