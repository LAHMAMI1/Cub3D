#include "../includes/parsing.h"

int	check_identifier(char *f, char *ab, t_parse *parse)
{
	int	i;

	i = 0;
	while (f[i] && ft_isspace(f[i]))
		i++;
	if (!ft_strncmp(f + i, ab, ft_strlen(ab)))
	{
		i += ft_strlen(ab);
		while (f[i] && ft_isspace(f[i]))
			i++;
		if (f[i])
		{
			parse->j = i;
			parse->count += 1;
			return (1);
		}
		else
		{
			ft_putstr_fd("Error:\nWrong entries 2", 2);
			exit(1);
		}
	}
	return (0);
}

void	check_informations(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->split_identifier[i])
	{
		if (check_identifier(parse->split_identifier[i], "NO ", parse))
			check_nswe(parse, parse->split_identifier[i] + parse->j,
				&parse->nswe[0]);
		else if (check_identifier(parse->split_identifier[i], "SO ", parse))
			check_nswe(parse, parse->split_identifier[i] + parse->j,
				&parse->nswe[1]);
		else if (check_identifier(parse->split_identifier[i], "WE ", parse))
			check_nswe(parse, parse->split_identifier[i] + parse->j,
				&parse->nswe[2]);
		else if (check_identifier(parse->split_identifier[i], "EA ", parse))
			check_nswe(parse, parse->split_identifier[i] + parse->j,
				&parse->nswe[3]);
		else if (check_identifier(parse->split_identifier[i], "F ", parse))
			int_to_hex(parse, parse->split_identifier[i] + parse->j,
				&parse->f_color);
		else if (check_identifier(parse->split_identifier[i], "C ", parse))
			int_to_hex(parse, parse->split_identifier[i] + parse->j,
				&parse->c_color);
		i++;
	}
}

void	check_all(t_parse *parse, int argc, char *argv[])
{
	check_args(argc, argv, parse);
	check_empty(parse);
	read_file(parse);
	parse->count = 0;
	parse->nswe = ft_calloc(4, sizeof(char *));
	check_informations(parse);
	if (parse->count != 6)
	{
		ft_putstr_fd("Error:\nWrong entries 1", 2);
		exit(1);
	}
	check_map(parse);
}
