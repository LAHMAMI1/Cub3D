/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:07:32 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/05 23:07:33 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	composed_map(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (!ft_strchr("01NSEW 	", line[x]))
			return (1);
		x++;
	}
	return (0);
}

int	check_player(t_parse *parse, int y, char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (ft_strchr("NSEW", line[x]))
		{
			if (parse->p > 0)
			{
				ft_putstr_fd("Error:\nThere is more than one player\n", 2);
				exit(1);
			}
			parse->p++;
			parse->px = x;
			parse->py = y;
			parse->p_d = line[x];
		}
		x++;
	}
	return (0);
}

int	no_line(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->str[i])
	{
		if (parse->str[ft_strlen(parse->str) - 1] == '\n'
			|| (parse->str[i] == '\n' && parse->str[i + 1] == '\n'))
		{
			free(parse->str);
			return (1);
		}
		i++;
	}
	free(parse->str);
	return (0);
}

int	no_line1(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

void	check_map(t_parse *parse)
{
	int	y;

	y = 0;
	parse->p = 0;
	while (parse->split_map[y])
	{
		if (composed_map(parse->split_map[y]) || no_line1(parse->split_map[y]))
		{
			ft_putstr_fd("Error:\nInvalid caractere\n", 2);
			exit(1);
		}
		check_player(parse, y, parse->split_map[y]);
		y++;
	}
	if (no_line(parse) || parse->p == 0 || wall_map(parse))
	{
		ft_putstr_fd("Error:\nInvalid map\n", 2);
		exit(1);
	}
}
