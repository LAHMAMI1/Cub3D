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

void check_all(t_parse *parse)
{
	// int i;
	// int j;

	parse->split_file = read_file(parse->fd, parse);
	if (!parse->split_file || check_empty(parse->split_file))
	{
		ft_putstr_fd("Error:\nEmpty file", 2);
		exit(1);
	}
	// i = 0;
	// while (parse->split_file[i])
	// {
	// 	j = 0;
	// 	while (parse->split_file[i][j])
	// 	{
	// 		if (ft_isspace(parse->split_file[i][j]))
	// 			j++;
	// 		if (parse->)
	// 		{
				
	// 		}
			
	// 	}
		
		
	// }
	
}