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
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C')
		return (0);
	return (1);
}

char	**read_file(int fd, t_parse *parse)
{
	char	*line;

	parse->str = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || not_map(line))
			break ;
		parse->str = ft_strjoin(parse->str, line);
		free(line);
	}
	
	parse->split_file = ft_split(parse->str, '\n');
	return (parse->split_file);
}
