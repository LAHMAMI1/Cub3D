/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:07:40 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/07 03:31:01 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	check_len(t_parse *parse)
{
	int	i;
	int	count;
	int	check;

	count = 0;
	check = 0;
	i = 0;
	while (parse->arg_id[i])
	{
		if (parse->arg_id[i] == ',')
			count++;
		i++;
	}
	i = 0;
	while (parse->split_color[i])
	{
		if (ft_strlen(parse->split_color[i]) > 3)
			check += 1;
		i++;
	}
	if (i != 3 || count != 2 || check > 0)
	{
		ft_putstr_fd("Error:\nNot valid color\n", 2);
		exit(1);
	}
}

void	check_color(t_parse *parse, char *line)
{
	int	i;
	int	j;

	check_multi_args(parse, line);
	parse->split_color = ft_split(parse->arg_id, ',');
	check_len(parse);
	i = 0;
	while (parse->split_color[i])
	{
		j = 0;
		while (parse->split_color[i][j])
		{
			if (!ft_isdigit(parse->split_color[i][j])
				|| !(ft_atoi(parse->split_color[i]) >= 0
					&& ft_atoi(parse->split_color[i]) <= 255))
			{
				ft_putstr_fd("Error:\nNot valid color\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	int_to_hex(t_parse *parse, char *line, int *hex)
{
	int	r;
	int	g;
	int	b;

	check_color(parse, line);
	r = ft_atoi(parse->split_color[0]);
	g = ft_atoi(parse->split_color[1]);
	b = ft_atoi(parse->split_color[2]);
	ft_free_split(parse->split_color);
	free(parse->arg_id);
	*hex = (r << 16) | (g << 8) | b;
	parse->j = 0;
}
