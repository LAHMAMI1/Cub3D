/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:15:35 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 15:03:35 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <stdio.h>

void	draw_square(t_point point, int len, t_cub3D *cub3D, int draw_borders)
{
	int	i;
	int	j;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (draw_borders && (i == len - 1 || j == len - 1))
				my_mlx_pixel_put(cub3D, i + point.x, j + point.y, 0x000000);
			else
				my_mlx_pixel_put(cub3D, i + point.x, j + point.y, point.color);
			i++;
		}
		j++;
	}
}

void	draw_rectangle(t_cub3D *cub3D, t_point point, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			my_mlx_pixel_put(cub3D, i + point.x, j + point.y, point.color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_cub3D *cub3D)
{
	t_point	point;

	point.y = (cub3D->player.x * VECTOR) + ((double)VECTOR / 2) - 8;
	point.x = (cub3D->player.y * VECTOR) + ((double)VECTOR / 2) - 8;
	point.color = cub3D->player.color;
	(void)point;
	draw_walls(cub3D);
}

void	draw_2d_map(t_cub3D cub3D)
{
	int			i;
	int			j;
	t_point		point;

	i = 0;
	while (i < cub3D.map.height)
	{
		j = 0;
		while (j < cub3D.map.width)
		{
			point.x = j * VECTOR;
			point.y = i * VECTOR;
			point.color = 0x053B50;
			if (!cub3D.map.map[i][j])
				point.color = 0xEEEEEE;
			draw_square(point, VECTOR, &cub3D, 1);
			j++;
		}
		i++;
	}
}

void	draw_player_direction(t_cub3D *cub3D)
{
	t_point	pt_1;
	t_point	pt_0;

	pt_0.y = cub3D->player.py;
	pt_0.x = cub3D->player.px;
	pt_0.color = cub3D->player.color;
	pt_1.y = pt_0.y + sin(cub3D->player.retation_angle) * VECTOR;
	pt_1.x = pt_0.x + cos(cub3D->player.retation_angle) * VECTOR;
	pt_1.color = cub3D->player.color;
	draw_line(*cub3D, pt_0, pt_1);
}
