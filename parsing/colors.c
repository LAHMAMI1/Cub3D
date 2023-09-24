#include "../includes/parsing.h"

void	check_len(t_parse *parse)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (parse->arg_id[i])
	{
		if (parse->arg_id[i] == ',')
			count++;
		i++;
	}
	i = 0;
	while (parse->split_color[i])
		i++;
	if (i != 3 || count != 2)
	{
		ft_putstr_fd("Error:\nNot valid color", 2);
		exit(1);
	}
}

void	check_color(t_parse *parse, char *line)
{
	int	i;
	int	j;

	check_multi_args(parse, line);
	parse->split_color = ft_split(parse->arg_id, ',');
	check_len(parse);
	i = 0;
	while (parse->split_color[i])
	{
		j = 0;
		while (parse->split_color[i][j])
		{
			if (!ft_isdigit(parse->split_color[i][j])
				|| !(ft_atoi(parse->split_color[i]) >= 0
					&& ft_atoi(parse->split_color[i]) <= 255))
			{
				ft_putstr_fd("Error:\nNot valid color", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	int_to_hex(t_parse *parse, char *line, int *hex)
{
	check_color(parse, line);
	int r = ft_atoi(parse->split_color[0]);
	int g = ft_atoi(parse->split_color[1]);
	int b = ft_atoi(parse->split_color[2]);
	*hex = (r << 16) | (g << 8) | b;
	parse->j = 0;
	parse->check_dup += 1;
}