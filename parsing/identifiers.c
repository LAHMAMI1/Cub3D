#include "../includes/parsing.h"

void	check_multi_args(t_parse *parse, char *line)
{
	int	i;

	i = 0;
	parse->arg_id = malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[i] && !ft_isspace(line[i]))
	{
		parse->arg_id[i] = line[i];
		i++;
	}
	parse->arg_id[i] = '\0';
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
	{
		ft_putstr_fd("Error:\nMulti args instead of one", 2);
		exit(1);
	}
}

char	*check_path(t_parse *parse, char *line)
{
	check_multi_args(parse, line);
	if (open(parse->arg_id, O_RDONLY) == -1 || ft_strncmp(parse->arg_id
			+ (ft_strlen(parse->arg_id) - 4), ".xpm", 4))
	{
		ft_putstr_fd("Error:\nNot valid path", 2);
		exit(1);
	}
	return (parse->arg_id);
}

void	check_nswe(t_parse *parse, char *line, char **id)
{
	if(*id)
		free(*id);
	*id = check_path(parse, line);
	parse->j = 0;
	if (*id == parse->nswe[0])
		parse->count[0]++;
	else if (*id == parse->nswe[1])
		parse->count[1]++;
	else if (*id == parse->nswe[2])
		parse->count[2]++;
	else if (*id == parse->nswe[3])
		parse->count[3]++;
}
