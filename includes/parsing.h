#ifndef PARSING_H
# define PARSING_H

#include "../libft/libft.h"
#include "../Get_next_line/get_next_line.h"
#include "structs.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	not_map(char *line);
void	read_file(t_parse *parse);
void	read_map(int fd, t_parse *parse, char *line);

void check_all(t_parse *parse);
void	check_args(int argc, char *argv[], t_parse *parse);
void	check_empty(t_parse *parse);
int check_space(char **split_file);
int check_identifier(char *f, char *ab, t_parse *parse);
void check_multi_args(t_parse *parse, char *line);

char *check_path(t_parse *parse, char *line);
void check_nswe(t_parse *parse, char *line, char **id);

void check_len(t_parse *parse);
void check_color(t_parse *parse, char *line);
void int_to_hex(t_parse *parse, char *line, int *hex);

void check_map(t_parse *parse);
int	composed_map(char *line);

int check_player(t_parse *parse, int y, char *line);
int	no_line(t_parse *parse);
int count_line(char **split_map);

int	wall_map(t_parse *parse);
int	first_line(t_parse *parse);
int	last_line(t_parse *parse, int y, int x);
int	check_around(char **map, int y, int x);

int max_char_length(char **map);
int **char_to_int(char **map);
void init_s_map(t_map *map, t_parse *parse);
void print_arg_map(t_map *map);
#endif