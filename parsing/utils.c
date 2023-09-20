#include "../includes/parsing.h"

int	not_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	if (ft_strchr("NSWEFC", line[i]))
		return (0);
	return (1);
}

void read_map(int fd, t_parse *parse, char *line)
{
	parse->str = ft_calloc(1, 1);
	if (line)
	{
		parse->str = ft_strjoin(parse->str, line);
		free(line);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			parse->str = ft_strjoin(parse->str, line);
			free(line);
		}
		parse->split_map = ft_split(parse->str, '\n');
		free(parse->str);
	}
	else
	{
		ft_putstr_fd("Error:\nthere is no map\n", 1);
		exit(1);
	}
}

void	read_file(t_parse *parse)
{
	char	*line;

	parse->str = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(parse->fd);
		if (!line || not_map(line))
			break ;
		parse->str = ft_strjoin(parse->str, line);
		free(line);
	}
	parse->split_identifier = ft_split(parse->str, '\n');
	free(parse->str);
	read_map(parse->fd, parse, line);
}
