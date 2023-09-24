#include "../includes/parsing.h"

int	check_identifier(char *f, char *ab, t_parse *parse)
{
	int i;

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
			return (1);
		}
		else
		{
			ft_putstr_fd("Error:\nMissing path or RGB", 2);
			exit(1);
		}
	}
	return (0);
}

void check_all(t_parse *parse)
{
	int i;
	

	check_empty(parse);
	read_file(parse);
	parse->check_dup = 0;
	i = 0;
	while (parse->split_identifier[i])
	{
		if (check_identifier(parse->split_identifier[i], "NO ", parse))
			check_nswe(parse, parse->split_identifier[i] + parse->j, &parse->no);
		else if (check_identifier(parse->split_identifier[i], "SO ", parse))
			check_nswe(parse, parse->split_identifier[i] + parse->j, &parse->so);
		else if (check_identifier(parse->split_identifier[i], "WE ", parse))
			check_nswe(parse, parse->split_identifier[i] + parse->j, &parse->we);
		else if (check_identifier(parse->split_identifier[i], "EA ", parse))
			check_nswe(parse, parse->split_identifier[i] + parse->j, &parse->ea);
		else if (check_identifier(parse->split_identifier[i], "F ", parse))
			int_to_hex(parse, parse->split_identifier[i] + parse->j, &parse->f_color);
		else if (check_identifier(parse->split_identifier[i], "C ", parse))
			int_to_hex(parse, parse->split_identifier[i] + parse->j, &parse->c_color);
		i++;
	}
	if (parse->check_dup > 6)
	{
		ft_putstr_fd("Error:\nDuplicate identifier", 2);
		exit(1);
	}
	else if (parse->check_dup < 6)
	{
		ft_putstr_fd("Error:\nWrong entries", 2);
		exit(1);
	}
	check_map(parse);
}