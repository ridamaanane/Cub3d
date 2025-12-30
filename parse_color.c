/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <ridamaanane@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:04:18 by rmaanane          #+#    #+#             */
/*   Updated: 2025/12/30 18:04:19 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0); // empty string is not a number
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

int	parse_color(t_game *game, char *line, char *path, int fd)
{
	char	**arr;
	int		i;
	char	*clean;

	int r, g, b;
	clean = clean_line(path);
	arr = ft_split(clean, ',');
	free(clean);
	if (!arr || ft_arrlen(arr) != 3)
	{
		if (arr)
			free_array(arr);
		free(line);
		exit_error(game, "Error\nInvalid color format", fd);
	}
	i = 0;
	while (i < 3)
	{
		if (!is_number(arr[i]))
		{
			free_array(arr);
			free(line);
			exit_error(game, "Error\nInvalid color", fd);
		}
		i++;
	}
	r = ft_atoi(arr[0]);
	g = ft_atoi(arr[1]);
	b = ft_atoi(arr[2]);
	free_array(arr);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_array(arr);
		free(line);
		exit_error(game, "Error\nColor out of range", fd);
	}
	return ((r << 16) | (g << 8) | b);
}
