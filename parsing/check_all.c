#include "../includes/parsing.h"

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
		if (check_identifier(parse->split_identifier[i], "NO "))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "SO "))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "WE "))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "EA "))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "F "))
			check_dup += 1;
		else if (check_identifier(parse->split_identifier[i], "C "))
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