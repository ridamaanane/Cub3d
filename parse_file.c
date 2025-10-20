#include "parsing.h"


int is_number(char *str)
{
    int i = 0;
    if (!str || str[0] == '\0')
        return 0; // empty string is not a number
    while (str[i])
    {
        if (!isdigit(str[i]))
            return 0; // found non digit character
        i++;
    }
    return 1;
}

int parse_color(char *str)
{
    char *ptr;
    int (r), (g), (b);

    // 1 first number (Red)
    ptr = ft_strchr(str, ',');
    if (!ptr)
    {
        printf("Error\nInvalid color\n");
        exit(1);
    }
    *ptr = '\0';
    if (!is_number(str))
    {
        printf("Error\nInvalid color\n");
        exit(1);
    }
    r = ft_atoi(str);
    str = ptr + 1; // move pointer to start of second number

    // 2️ second number (Green)
    ptr = ft_strchr(str, ',');
    if (!ptr)
    {
        printf("Error\nInvalid color\n");
        exit(1);
    }
    *ptr = '\0';
    if (!is_number(str))
    {
        printf("Error\nInvalid color\n");
        exit(1);
    }
    g = ft_atoi(str);
    str = ptr + 1; // move pointer to start of third number

    // 3️ third number (Blue)
    if (!is_number(str))
    {
        printf("Error\nInvalid color\n");
        exit(1);
    }
    b = ft_atoi(str);

    // 4️ check range 0–255
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    {
        printf("Error\nColor out of range\n");
        exit(1);
    }

    // 5️ combine into single int 0xRRGGBB
    return (r << 16) | (g << 8) | b;
}



void parse_line (char *line, t_game *game)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        game->tex.no = ft_strdup(line + 3);
    else if (strncmp(line, "SO ", 3) == 0)
        game->tex.so = strdup(line + 3);
    else if (strncmp(line, "WE ", 3) == 0)
        game->tex.we = strdup(line + 3);
    else if (strncmp(line, "EA ", 3) == 0)
        game->tex.ea = strdup(line + 3);
    else
    {
        if (strncmp(line, "F ", 2) == 0)
            parse_color(line + 2, &game->colors.floor);
        else if (strncmp(line, "C ", 2) == 0)
            parse_color(line + 2, &game->colors.ceiling);
    }
}

void parse_file(t_game *game, char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nCould not open file\n");
        exit(1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (is_texture_line(line))
            parse_texture(line, game);
        else if (is_color_line(line))
            parse_color_line(line, game);
        else if (line_not_empty(line))
        {
            // when we reach the first map line
            parse_map(game, fd, line);
            break; // stop reading here, parse_map reads rest
        }
        free(line); // free line after using it
    }
    close(fd);
}