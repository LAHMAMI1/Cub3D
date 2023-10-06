/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:28:55 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 15:57:33 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	*ceiling_floor_buffering(t_cub *cub3D)
{
	int	*buffer;
	int	i;

	buffer = malloc(sizeof(int) * (WIDTH * HEIGHT));
	i = 0;
	while (i < (WIDTH * HEIGHT) / 2)
		buffer[i++] = cub3D->map.ceiling_color;
	while (i < WIDTH * HEIGHT)
		buffer[i++] = cub3D->map.floor_color;
	return (buffer);
}

t_data	set_texturs(t_cub *cub3D, double ra, int flag)
{
	if (flag == 1)
	{
		if (ra > 0 && ra < M_PI)
			return (cub3D->texture_so);
		else
			return (cub3D->texture_no);
	}
	else
	{
		if (ra > (0.5 * M_PI) && ra < (1.5 * M_PI))
			return (cub3D->texture_we);
		else
			return (cub3D->texture_ea);
	}
}

void	draw_texturs(t_cub *cub3D, int *buffer)
{
	int	i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		((int *)cub3D->data.addr)[i] = buffer[i];
		i++;
	}
}

void	textures_buffering(t_cub *cub3D, int *buffer, int i)
{
	int	texture_x;
	int	texture_y;
	int	j;
	int	distance_from_top;

	check_h_v_intersection(cub3D);
	calcul_ray_data(cub3D, &texture_x);
	j = cub3D->ray_data.top_pixel;
	while (j < cub3D->ray_data.bottom_pixel)
	{
		distance_from_top = j + (cub3D->ray_data.line_h / 2) - (HEIGHT / 2);
		texture_y = distance_from_top * (cub3D->ray_data.texture.height
				/ cub3D->ray_data.line_h);
		buffer[j * WIDTH + i] = *(int *)(cub3D->ray_data.texture.addr
				+ (texture_y * cub3D->ray_data.texture.line_length) + texture_x
				* (cub3D->ray_data.texture.bits_per_pixel / 8));
		j++;
	}
}
