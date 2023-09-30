#include "../includes/parsing.h"

int	check_around(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == 'S' || map[y][x] == 'N'
		|| map[y][x] == 'W' || map[y][x] == 'E')
	{
		if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ' || map[y + 1][x] == ' '
			|| map[y - 1][x] == ' ' || map[y][x + 1] == '\t' || map[y][x
			- 1] == '\t' || map[y + 1][x] == '\t' || map[y - 1][x] == '\t'
			|| map[y][x + 1] == '\0' || map[y][x - 1] == '\0' || map[y
			+ 1][x] == '\0' || map[y - 1][x] == '\0')
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

int	last_line(t_parse *parse, int y, int x)
{
	if (y == (count_line(parse->split_map) - 1))
	{
		x = 0;
		while (parse->split_map[y][x])
		{
			while (ft_isspace(parse->split_map[y][x]))
				x++;
			if (!ft_strchr("1 	", parse->split_map[y][x]))
				return (1);
			x++;
		}
	}
	return (0);
}

int	wall_map(t_parse *parse)
{
	int	y;
	int	x;
	int	i;

	if(first_line(parse))
		return (1);
	y = 0;
	while (parse->split_map[y])
	{
		x = 0;
		while (ft_isspace(parse->split_map[y][x]))
			x++;
		i = x;
		while (parse->split_map[y][x])
		{
			if (parse->split_map[y][i] != '1'
				|| parse->split_map[y][ft_strlen(parse->split_map[y])
				- 1] != '1')
				return (1);
			if (check_around(parse->split_map, y, x))
				return (1);
			x++;
		}
		if(last_line(parse, y, x))
			return (1);
		y++;
	}
	return (0);
}
