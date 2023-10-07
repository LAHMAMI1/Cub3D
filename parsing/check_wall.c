/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:07:43 by olahmami          #+#    #+#             */
/*   Updated: 2023/10/07 03:34:18 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char *line_set(int width)
{
    char *new_line;
    int i;

    new_line = malloc(sizeof(char) * (width + 3));
    i = 0;
    while (i < width + 2)
    {
        new_line[i] = 'X';
        i++;
    }
    new_line[i] = '\0';
    return (new_line);
}

char **map_dup(t_parse *parse)
{
    int height;
    int width;
    char **dup;
    int i;
    int j;

    height = count_line(parse->split_map);
    width = max_char_length(parse->split_map);
    dup = malloc(sizeof(char *) * (height + 3));
    dup[0] = line_set(width);
    i = 1;
    while (i < height + 1)
    {
        dup[i] = malloc(sizeof(char) * (width + 3));
        j = 0;
        while (j < width + 2)
        {
            if(j && j <= (int)ft_strlen(parse->split_map[i-1]) && ft_strchr("10NSWE", parse->split_map[i - 1][j - 1]))
                dup[i][j] = parse->split_map[i - 1][j -1];
            else
                dup[i][j] = 'X';
            j++;
        }
         
        dup[i][j] = '\0';
        i++;
    }
    dup[i] = line_set(width);
    dup[i + 1] = NULL;
    return (dup);
}

int check_four(int x, int y, char **dup_map)
{
    if (dup_map[y][x] != 'X' && dup_map[y][x] != '1')
            return (1);
    return (0);
}

int	wall_map(t_parse *parse)
{
	char **dup_map;
    int y;
    int x;

    dup_map = map_dup(parse);
    y = 0;
    while (dup_map[y])
    {
        x = 0;
        while (dup_map[y][x])
        {
            if (dup_map[y][x] == 'X')
            {
                if ((dup_map[y][x + 1] && check_four(x + 1, y, dup_map))
                     || (dup_map[y + 1] && check_four(x, y + 1, dup_map)))
					 {
						ft_free_split(dup_map);
                    return (1);
					 }
                else if ((x != 0 && check_four(x - 1, y, dup_map))
                    || (y != 0 && check_four(x, y - 1, dup_map)))
					{
						ft_free_split(dup_map);
                    return (1);
					}
            }
            x++;
        }
        y++;
    }
	ft_free_split(dup_map);
	return (0);
}
