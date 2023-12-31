/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:07:45 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/07 03:29:28 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	check_space(char **split_file)
{
	int	i;
	int	j;

	i = 0;
	while (split_file[i])
	{
		j = 0;
		while (split_file[i][j])
		{
			if (!ft_isspace(split_file[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	ft_free_split(split_file);
	return (1);
}

void	check_empty(t_parse *parse)
{
	char	*line;

	parse->str = ft_calloc(1, 1);
	parse->fd_empty = open(parse->argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(parse->fd_empty);
		if (!line)
			break ;
		parse->str = ft_strjoin(parse->str, line);
		free(line);
	}
	parse->split_file = ft_split(parse->str, '\n');
	if (!parse->split_file || check_space(parse->split_file))
	{
		ft_putstr_fd("Error:\nEmpty file\n", 2);
		close(parse->fd_empty);
		exit(1);
	}
	free(parse->str);
	close(parse->fd_empty);
}
