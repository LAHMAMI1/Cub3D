#ifndef PARSING_H
# define PARSING_H

#include "../libft/libft.h"
#include "../Get_next_line/get_next_line.h"
#include "structs.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	**read_file(int fd, t_parse *parse);

void check_all(t_parse *parse);
void	check_args(int argc, char *argv[], t_parse *parse);
int check_empty(char **split_file);
int check_identifier(char *f, char *ab);

#endif