#include "parsing.h"

int is_number(char *str)
{
    int i = 0;
    if (!str || str[0] == '\0')
        return 0; // empty string is not a number
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

int ft_arrlen(char **arr)
{
    int i;
    
    i = 0;
    if (!arr)
        return 0;
    while (arr[i])
        i++;
    return (i);
}

int parse_color(t_game *game, char *path)
{
    char **arr;
    int r, g, b;
    int i;

    char *clean = clean_line(path);
    arr = ft_split(clean, ',');
    free(clean);
    if (!arr || ft_arrlen(arr) != 3)
        exit_error(game, "Error\nInvalid color format");
    i = 0;
    while (i < 3)
    {
        if (!is_number(arr[i]))
            exit_error(game, "Error\nInvalid color");
        i++;
    }
    r = ft_atoi(arr[0]);
    g = ft_atoi(arr[1]);
    b = ft_atoi(arr[2]);
    free_array(arr);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        exit_error(game, "Error\nColor out of range");
    return (r << 16) | (g << 8) | b;
}
