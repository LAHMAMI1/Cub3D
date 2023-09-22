#include "../includes/parsing.h"

int check_rgb(char *line)
{
	int i;

	i = 0;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
	{
		ft_putstr_fd("Error:\nIdentifier has 2 args insted of path", 2);
		exit(1);
	}
	return (1);
}

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
		// if (check_path(parse, f + i) && ft_strlen(ab) == 3)
		// 	return (1);
		// if (check_rgb(f + i) && ft_strlen(ab) == 2)
		// 	return (1);
		if (f[i])
		{
			parse->j = i;
			return (1);
		}
		else
		{
			ft_putstr_fd("Error:\nMissing path", 2);
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
	// i=0;
	// while (parse->split_identifier[i])
	// {
	// 	printf("%s\n", parse->split_identifier[i]);
	// 	i++;
	// }
	i = 0;
	while (parse->split_identifier[i])
	{
		if (check_identifier(parse->split_identifier[i], "NO ", parse))
			check_no(parse, parse->split_identifier[i] + parse->j);
		else if (check_identifier(parse->split_identifier[i], "SO ", parse))
			check_so(parse, parse->split_identifier[i] + parse->j);
		else if (check_identifier(parse->split_identifier[i], "WE ", parse))
			check_we(parse, parse->split_identifier[i] + parse->j);
		else if (check_identifier(parse->split_identifier[i], "EA ", parse))
			check_ea(parse, parse->split_identifier[i] + parse->j);
		else if (check_identifier(parse->split_identifier[i], "F ", parse))
			parse->check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "C ", parse))
			parse->check_dup += 1;
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
}