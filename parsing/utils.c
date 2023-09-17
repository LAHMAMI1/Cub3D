#include "../includes/parsing.h"

char	**read_file(int fd, t_parse *parse)
{
	char	*line;

	parse->str = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse->str = ft_strjoin(parse->str, line);
		free(line);
	}
	parse->split_file = ft_split(parse->str, '\n');
	return (parse->split_file);
}

