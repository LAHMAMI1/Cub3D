#include "../includes/parsing.h"

int check_empty(char **split_file)
{
	int i;
	int j;

	i = 0;
	while (split_file[i])
	{
		j = 0;
		while (split_file[i][j])
		{
			if (!ft_isspace(split_file[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// void check_path(t_parse *parse)
// {
// 	int fd;


// }

int	check_identifier(char *f, char *ab)
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
		//nswitch ctrncmp b check path
		if (!ft_strncmp(f + i, "./", 2) && ft_strlen(ab) == 3)
			return (1);
		if ((f[i] >= '0' && f[i] <= '9') && ft_strlen(ab) == 2)
			return (1);
	}
	return (0);
}

void check_all(t_parse *parse)
{
	int i;
	int check_dup;

	parse->split_file = read_file(parse->fd, parse);
	check_dup = 0;
	// i=0;
	// while (parse->split_file[i])
	// {
	// 	printf("%s\n", parse->split_file[i]);
	// 	i++;
	// }
	if (!parse->split_file || check_empty(parse->split_file))
	{
		ft_putstr_fd("Error:\nEmpty file", 2);
		exit(1);
	}
	i = 0;
	while (parse->split_file[i])
	{
		if (check_identifier(parse->split_file[i], "NO "))
			check_dup += 1;
		else if (check_identifier(parse->split_file[i], "SO "))
			check_dup += 1;
		else if (check_identifier(parse->split_file[i], "WE "))
			check_dup += 1;
		else if (check_identifier(parse->split_file[i], "EA "))
			check_dup += 1;
		else if (check_identifier(parse->split_file[i], "F "))
			check_dup += 1;
		else if (check_identifier(parse->split_file[i], "C "))
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