#include "../includes/parsing.h"

int max_char_length(char **map) {
	int i;
	int max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (max < ft_strlen(map[i]))
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

int **char_to_int(char **map)
{
    int **int_map;
    int i;
	int j;

	int_map = malloc(sizeof(int *) * (count_line(map) + 1));
	i = 0;
    while (map[i])
	{
        int_map[i] = malloc(sizeof(int) * (max_char_length(map) + 1));
        j = 0;
        while (map[i][j])
		{
            if (map[i][j] == ' ' || map[i][j] == '\t')
                int_map[i][j] = 0;
			else
                int_map[i][j] = map[i][j] - '0';
            j++;
        }
        int_map[i][j] = -1;
        i++;
    }
    int_map[i] = NULL;
    return int_map;
}

void init_s_map(t_map *map, t_parse *parse)
{
	
	map->height = count_line(parse->split_map);
	map->width = max_char_length(parse->split_map);
	map->map = char_to_int(parse->split_map);
	map->player.x = parse->px;
	map->player.y = parse->py;
	map->player_direction = parse->p_d;
	map->floor_color = parse->f_color;
	map->ceiling_color = parse->c_color;
	free(parse->split_map);
	free(parse->split_file);
	free(parse->split_identifier);
	free(parse->split_color);
	// free(parse->no);
	// free(parse->so);
	// free(parse->we);
	// free(parse->ea);
	free(parse);
}

void print_arg_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%d", map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("map height: %d\n", map->height);
	printf("map width: %d\n", map->width);
	printf("player x: %d\n", map->player.x);
	printf("player y: %d\n", map->player.y);
	printf("player direction: %c\n", map->player_direction);
	printf("floor color: %d\n", map->floor_color);
	printf("ceiling color: %d\n", map->ceiling_color);
}
