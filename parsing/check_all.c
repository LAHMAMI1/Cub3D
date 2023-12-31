/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:07:51 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/07 16:10:11 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	check_identifier(char *f, char *ab, t_parse *parse)
{
	int	i;

	i = 0;
	while (f[i] && ft_isspace(f[i]))
		i++;
	if (!ft_strncmp(f + i, ab, ft_strlen(ab)))
	{
		i += ft_strlen(ab);
		while (f[i] && ft_isspace(f[i]))
			i++;
		if (f[i])
		{
			parse->j = i;
			return (1);
		}
		else
		{
			ft_putstr_fd("Error:\nWrong entries\n", 2);
			exit(1);
		}
	}
	return (0);
}

void	check_info_norm(t_parse *p, int i)
{
	if (check_identifier(p->split_identifier[i], "NO ", p))
		check_nswe(p, p->split_identifier[i] + p->j, &p->nswe[0]);
	else if (check_identifier(p->split_identifier[i], "SO ", p))
		check_nswe(p, p->split_identifier[i] + p->j, &p->nswe[1]);
	else if (check_identifier(p->split_identifier[i], "WE ", p))
		check_nswe(p, p->split_identifier[i] + p->j, &p->nswe[2]);
	else if (check_identifier(p->split_identifier[i], "EA ", p))
		check_nswe(p, p->split_identifier[i] + p->j, &p->nswe[3]);
	else if (check_identifier(p->split_identifier[i], "F ", p))
	{
		int_to_hex(p, p->split_identifier[i] + p->j, &p->f_color);
		p->count[4]++;
	}
	else if (check_identifier(p->split_identifier[i], "C ", p))
	{
		int_to_hex(p, p->split_identifier[i] + p->j, &p->c_color);
		p->count[5]++;
	}
	else
		p->error += 1;
}

void	check_informations(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->split_identifier[i])
	{
		check_info_norm(parse, i);
		i++;
	}
}

void	check_all(t_parse *parse, int argc, char *argv[])
{
	check_args(argc, argv, parse);
	check_empty(parse);
	read_file(parse);
	parse->count = ft_calloc(6, sizeof(int));
	parse->nswe = ft_calloc(4, sizeof(char *));
	parse->error = 0;
	check_informations(parse);
	if (parse->count[0] != 1 || parse->count[1] != 1 || parse->count[2] != 1
		|| parse->count[3] != 1 || parse->count[4] != 1 || parse->count[5] != 1
		|| parse->error != 0)
	{
		ft_putstr_fd("Error:\nWrong entries\n", 2);
		exit(1);
	}
	check_map(parse);
}
