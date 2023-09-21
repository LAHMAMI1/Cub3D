#include "../includes/parsing.h"

int check_path(t_parse *parse, char *line)
{
	int i;

	i = 0;
	parse->path = malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[i] && !ft_isspace(line[i]))
	{
		parse->path[i] = line[i];
		i++;
	}
	parse->path[i] = '\0';
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
	{
		ft_putstr_fd("Error:\nIdentifier has 2 args insted of path", 2);
		exit(1);
	}
	if (open(parse->path, O_RDONLY) == -1)
	{
		ft_putstr_fd("Error:\nPath is not valid", 2);
		exit(1);
	}
	return (1);
}

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
		if (check_path(parse, f + i) && ft_strlen(ab) == 3)
			return (1);
		if (check_rgb(f + i) && ft_strlen(ab) == 2)
			return (1);
	}
	return (0);
}

void check_all(t_parse *parse)
{
	int i;
	int check_dup;

	check_empty(parse);
	read_file(parse);
	check_dup = 0;
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
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "SO ", parse))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "WE ", parse))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "EA ", parse))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "F ", parse))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "C ", parse))
			check_dup += 1;
		i++;
	}
	if (check_dup > 6)
	{
		ft_putstr_fd("Error:\nDuplicate identifier", 2);
		exit(1);
	}
	else if (check_dup < 6)
	{
		ft_putstr_fd("Error:\nWrong entries", 2);
		exit(1);
	}
}