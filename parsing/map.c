#include "../includes/parsing.h"

int	composed_map(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (!ft_strchr("01N", line[x]))
			return (1);
		x++;
	}
	return (0);
}

void	check_map(t_parse *parse)
{
	int y;
	// int x;

	y = 0;
	// x = 0;
	while (parse->split_map[y])
	{
		if (composed_map(parse->split_map[y]))
		{
			ft_putstr_fd("Error:\nMap is not composed of 0, 1, N, S, E, W\n", 2);
			exit(1);
		}
		// x = 0;
		// while (parse->split_map[y][x])
		// {
		// 	if (parse->split_map[y][x] == 'N' || parse->split_map[y][x] == 'S'
		// 		||
		// 		parse->split_map[y][x] == 'W' || parse->split_map[y][x] == 'E')
		// 	{
		// 		parse->player++;
		// 		parse->player_pos_x = y;
		// 		parse->player_pos_y = x;
		// 	}
		// 	x++;
		// }
		y++;
	}
	// if (parse->player != 1)
	// {
	// 	ft_putstr_fd("Error:\nThere is no player or more than one player\n", 2);
	// 	exit(1);
	// }
}