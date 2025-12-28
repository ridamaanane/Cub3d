#include "parsing.h"

int main()
{
    char *line;

    int fd = open("test_map.cub", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
    line = get_next_line(fd);
    free(line);
    return 0;
}