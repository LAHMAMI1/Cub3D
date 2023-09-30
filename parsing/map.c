#include "../includes/parsing.h"

int	composed_map(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (!ft_strchr("01NSEW 	", line[x]))
			return (1);
		x++;
	}
	return (0);
}

int check_player(t_parse *parse, int y, char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (ft_strchr("NSEW", line[x]))
		{
			if (parse->p > 0)
			{
				ft_putstr_fd("Error:\nThere is more than one player\n", 2);
				exit(1);
			}
			parse->p++;
			parse->px = x;
			parse->py = y;
			parse->p_d = line[x];
		}
		x++;
	}
	return (0);
}

int	no_line(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->str[i])
	{
		if (parse->str[i] == '\n' && parse->str[i + 1] == '\n')
		{
			free(parse->str);
			return (1);
		}
		i++;
	}
	free(parse->str);
	return (0);
}

int count_line(char **split_map)
{
	int i;

	i = 0;
	while (split_map[i])
		i++;
	return (i);
}

void	check_map(t_parse *parse)
{
	int y;

	y = 0;
	parse->p = 0;
	while (parse->split_map[y])
	{
		if (composed_map(parse->split_map[y]))
		{
			ft_putstr_fd("Error:\nInvalid caractere\n", 2);
			exit(1);
		}
		check_player(parse, y, parse->split_map[y]);
		y++;
	}
	if (no_line(parse))
	{
		ft_putstr_fd("Error:\nthere's a new line\n", 2);
		exit(1);
	}
	if (parse->p == 0)
	{
		ft_putstr_fd("Error:\nThere is no player\n", 2);
		exit(1);
	}
	if (wall_map(parse))
	{
		ft_putstr_fd("Error:\nMap is not surrounded by walls\n", 2);
		exit(1);	
	}
}

