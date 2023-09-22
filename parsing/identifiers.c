#include "../includes/parsing.h"

char	*check_path(t_parse *parse, char *line)
{
	int	i;

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
		ft_putstr_fd("Error:\nMulti args instead of path", 2);
		exit(1);
	}
	if (open(parse->path, O_RDONLY) == -1 || ft_strncmp(parse->path
			+ (ft_strlen(parse->path) - 4), ".xpm", 4))
	{
		ft_putstr_fd("Error:\nNot valid path", 2);
		exit(1);
	}
	return (parse->path);
}

void	check_no(t_parse *parse, char *line)
{
	parse->no = malloc(sizeof(char) * ft_strlen(line) + 1);
	parse->no = check_path(parse, line);
	parse->j = 0;
	parse->check_dup += 1;
}

void	check_so(t_parse *parse, char *line)
{
	parse->so = malloc(sizeof(char) * ft_strlen(line) + 1);
	parse->so = check_path(parse, line);
	parse->j = 0;
	parse->check_dup += 1;
}

void	check_we(t_parse *parse, char *line)
{
	parse->we = malloc(sizeof(char) * ft_strlen(line) + 1);
	parse->we = check_path(parse, line);
	parse->j = 0;
	parse->check_dup += 1;
}

void	check_ea(t_parse *parse, char *line)
{
	parse->ea = malloc(sizeof(char) * ft_strlen(line) + 1);
	parse->ea = check_path(parse, line);
	parse->j = 0;
	parse->check_dup += 1;
}
