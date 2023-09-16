#include "../includes/parsing.h"

void check_all(t_parse *parse)
{
	int i;

	i = 0;
	while (parse->split_file[i])
	{
		if (parse->split_file[i][0] == 'N' && parse->split_file[i][1] == 'O')
			check_texture(parse, parse->split_file[i], 0);
		else if (parse->split_file[i][0] == 'S' && parse->split_file[i][1] == 'O')
			check_texture(parse, parse->split_file[i], 1);
		else if (parse->split_file[i][0] == 'W' && parse->split_file[i][1] == 'E')
			check_texture(parse, parse->split_file[i], 2);
		else if (parse->split_file[i][0] == 'E' && parse->split_file[i][1] == 'A')
			check_texture(parse, parse->split_file[i], 3);
		else if (parse->split_file[i][0] == 'F')
			check_color(parse, parse->split_file[i], 0);
		else if (parse->split_file[i][0] == 'C')
			check_color(parse, parse->split_file[i], 1);
		
	}
	
}