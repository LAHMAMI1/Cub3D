/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:07:43 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/07 16:35:01 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*line_set(int width)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * (width + 3));
	i = 0;
	while (i < width + 2)
	{
		new_line[i] = 'X';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	**map_dup(t_parse *parse, int width, int height, char **dup)
{
	int	i;
	int	j;

	dup = malloc(sizeof(char *) * (height + 3));
	dup[0] = line_set(width);
	i = 1;
	while (i < height + 1)
	{
		dup[i] = malloc(sizeof(char) * (width + 3));
		j = 0;
		while (j < width + 2)
		{
			if (j && j <= (int)ft_strlen(parse->split_map[i - 1])
				&& ft_strchr("10NSWE", parse->split_map[i - 1][j - 1]))
				dup[i][j] = parse->split_map[i - 1][j - 1];
			else
				dup[i][j] = 'X';
			j++;
		}
		dup[i][j] = '\0';
		i++;
	}
	dup[i] = line_set(width);
	dup[i + 1] = NULL;
	return (dup);
}

int	check_four(int x, int y, char **dup_map)
{
	if (dup_map[y][x] != 'X' && dup_map[y][x] != '1')
		return (1);
	return (0);
}

int	check_wall(char **dup_map, int x, int y)
{
	while (dup_map[y])
	{
		x = 0;
		while (dup_map[y][x])
		{
			if (dup_map[y][x] == 'X')
			{
				if ((dup_map[y][x + 1] && check_four(x + 1, y, dup_map))
					|| (dup_map[y + 1] && check_four(x, y + 1, dup_map)))
				{
					ft_free_split(dup_map);
					return (1);
				}
				else if ((x != 0 && check_four(x - 1, y, dup_map)) || (y != 0
						&& check_four(x, y - 1, dup_map)))
				{
					ft_free_split(dup_map);
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	wall_map(t_parse *parse)
{
	char	**dup_map;
	int		y;
	int		x;
	int		height;
	int		width;

	height = count_line(parse->split_map);
	width = max_char_length(parse->split_map);
	dup_map = NULL;
	dup_map = map_dup(parse, width, height, dup_map);
	x = 0;
	y = 0;
	if (check_wall(dup_map, x, y))
		return (1);
	ft_free_split(dup_map);
	return (0);
}
