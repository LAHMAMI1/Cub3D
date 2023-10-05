/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:07:43 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/05 23:07:44 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	check_around(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == 'S' || map[y][x] == 'N'
		|| map[y][x] == 'W' || map[y][x] == 'E')
	{
		if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ' || map[y + 1][x] == ' '
			|| map[y - 1][x] == ' ' || map[y][x + 1] == '\t' || map[y][x
			- 1] == '\t' || map[y + 1][x] == '\t' || map[y - 1][x] == '\t'
			|| !map[y][x + 1] || !map[y][x - 1] || !map[y + 1][x] || !map[y
			- 1][x])
			return (1);
	}
	return (0);
}

int	first_line(t_parse *parse)
{
	int	x;

	x = 0;
	while (ft_isspace(parse->split_map[0][x]))
		x++;
	while (parse->split_map[0][x])
	{
		if (!ft_strchr("1 	", parse->split_map[0][x]))
			return (1);
		x++;
	}
	return (0);
}

int	check_wall(t_parse *parse)
{
	int		y;
	int		x;
	char	*tmp;

	y = 0;
	while (parse->split_map[y])
	{
		tmp = ft_strtrim(parse->split_map[y], " ");
		x = 0;
		while (tmp[x])
		{
			if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1'
				|| check_around(parse->split_map, y, x))
			{
				free(tmp);
				return (1);
			}
			x++;
		}
		free(tmp);
		y++;
	}
	return (0);
}

int	wall_map(t_parse *parse)
{
	if (first_line(parse))
		return (1);
	if (check_wall(parse))
		return (1);
	return (0);
}
