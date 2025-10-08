#include "parsing.h"


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

void check_file_extension(char *filename)
{
    int len;

    len = ft_strlen(filename);
    if (len < 4 || ft_strcmp(filename + len - 4, ".cub") != 0)
    {
        printf("Error\nInvalid file extension. Must be .cub\n");
        exit(1);
    }
}