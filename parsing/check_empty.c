#include "../includes/parsing.h"

int check_space(char **split_identifier)
{
	int i;
	int j;

	i = 0;
	while (split_identifier[i])
	{
		j = 0;
		while (split_identifier[i][j])
		{
			if (!ft_isspace(split_identifier[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void check_empty(t_parse *parse)
{
	char	*line;

	parse->str = ft_calloc(1, 1);
	parse->fd_empty = open(parse->argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(parse->fd_empty);
		if (!line)
			break ;
		parse->str = ft_strjoin(parse->str, line);
		free(line);
	}
	parse->split_file = ft_split(parse->str, '\n');
	if (!parse->split_file || check_space(parse->split_file))
	{
		ft_putstr_fd("Error:\nEmpty file", 2);
		close(parse->fd_empty);
		exit(1);
	}
	free(parse->str);
	close(parse->fd_empty);
}