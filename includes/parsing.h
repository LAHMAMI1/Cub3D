#ifndef PARSING_H
# define PARSING_H

#include "../libft/libft.h"
#include "../Get_next_line/get_next_line.h"
#include "structs.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	check_args(int argc, char *argv[], t_parse *parse);
char	**read_file(int fd, t_parse *parse);

#endif