/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:14:43 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/07 16:37:55 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../Get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "structs.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

int		not_map(char *line);
void	read_file(t_parse *parse);
void	read_map(int fd, t_parse *parse, char *line);

void	check_all(t_parse *parse, int argc, char *argv[]);
void	check_args(int argc, char *argv[], t_parse *parse);
void	check_empty(t_parse *parse);
int		check_space(char **split_file);
void	check_informations(t_parse *parse);
int		check_identifier(char *f, char *ab, t_parse *parse);
void	check_multi_args(t_parse *parse, char *line);

char	*check_path(t_parse *parse, char *line);
void	check_nswe(t_parse *parse, char *line, char **id);

void	check_len(t_parse *parse);
void	check_color(t_parse *parse, char *line);
void	int_to_hex(t_parse *parse, char *line, int *hex);

void	check_map(t_parse *parse);
int		composed_map(char *line);

int		check_player(t_parse *parse, int y, char *line);
int		no_line(t_parse *parse);
int		count_line(char **split_map);

int		wall_map(t_parse *parse);
char	**map_dup(t_parse *parse, int width, int height, char **dup);
char	*line_set(int width);
int		check_four(int x, int y, char **dup_map);
int		check_wall(char **dup_map, int x, int y);

int		max_char_length(char **map);
int		**char_to_int(char **map, int height, int width);
void	init_s_map(t_cub *cub3D, t_parse *parse);
#endif
