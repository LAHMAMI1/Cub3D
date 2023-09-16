#include "../includes/parsing.h"

void	check_args(int argc, char *argv[], t_parse *parse)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error:\nInvalid number of args\nTry ./cub3D 'map_name.cub'", 2);
		exit(1);
	}
	else if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4))
	{
		ft_putstr_fd("Error:\nInvalid file name\nTry ./cub3D 'map_name.cub'", 2);
		exit(1);
	}
	parse->fd = open(argv[1], O_RDONLY | __O_DIRECTORY);
	if (parse->fd > 0)
	{
		ft_putstr_fd("Error:\nIt's a directory", 2);
		close(parse->fd);
		exit(1);
	}
	parse->fd = open(argv[1], O_RDONLY);
	if (parse->fd < 0)
	{
		ft_putstr_fd("Error:\nMap file does not exist", 2);
		exit(1);
	}
}
