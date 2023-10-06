/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:07:07 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/06 16:01:05 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	max_char_length(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (max < (int)ft_strlen(map[i]))
			max = (int)ft_strlen(map[i]);
		i++;
	}
	return (max);
}

int	count_line(char **split_map)
{
	int	i;

	i = 0;
	while (split_map[i])
		i++;
	return (i);
}

int	**char_to_int(char **map, int height, int width)
{
	int	**int_map;
	int	i;
	int	j;

	int_map = malloc(sizeof(int *) * (height + 1));
	i = 0;
	while (map[i])
	{
		int_map[i] = ft_calloc(width + 1, sizeof(int));
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				int_map[i][j] = 0;
			else
				int_map[i][j] = (unsigned char)(map[i][j] - '0');
			j++;
		}
		int_map[i][j] = 0;
		i++;
	}
	int_map[i] = NULL;
	return (int_map);
}

void	init_s_map(t_cub *cub3D, t_parse *parse)
{
	cub3D->map.height = count_line(parse->split_map);
	cub3D->map.width = max_char_length(parse->split_map);
	cub3D->map.map = char_to_int(parse->split_map, cub3D->map.height,
			cub3D->map.width);
	cub3D->map.player.x = parse->px;
	cub3D->map.player.y = parse->py;
	cub3D->map.player_direction = parse->p_d;
	cub3D->map.floor_color = parse->f_color;
	cub3D->map.ceiling_color = parse->c_color;
	cub3D->map.n = parse->nswe[0];
	cub3D->map.s = parse->nswe[1];
	cub3D->map.w = parse->nswe[2];
	cub3D->map.e = parse->nswe[3];
}
