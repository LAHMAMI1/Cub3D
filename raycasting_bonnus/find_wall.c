/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:14:02 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 12:44:58 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <math.h>
#include <stdio.h>

void	init_horizontal_params(t_cub3D *cub3D, t_intesc_params *first_inter,
		double ra)
{
	double	my_tan;

	my_tan = -1 / tan(ra);
	if (ra > M_PI)
	{
		first_inter->y_intercept = (((int)cub3D->player.py >> 6) << 6) - 0.0001;
		first_inter->y_step = -64;
	}
	if (ra < M_PI)
	{
		first_inter->y_intercept = (((int)cub3D->player.py >> 6) << 6) + 64;
		first_inter->y_step = 64;
	}
	if (ra == 0 || ra == M_PI)
	{
		first_inter->x_intercept = cub3D->player.px;
		first_inter->y_intercept = cub3D->player.py;
	}
	first_inter->x_intercept = (cub3D->player.py - first_inter->y_intercept)
		* my_tan + cub3D->player.px;
	first_inter->x_step = -first_inter->y_step * my_tan;
}

t_point	check_horizontal_intersection(t_cub3D *cub3D, double ra)
{
	t_intesc_params	first_inter;
	t_point			h_inter;

	init_horizontal_params(cub3D, &first_inter, ra);
	while ((int)(first_inter.x_intercept / 64) >= 0 &&
			(int)(first_inter.x_intercept / 64) < cub3D->map.width &&
			(int)(first_inter.y_intercept / 64) >= 0 &&
			(int)(first_inter.y_intercept / 64) < cub3D->map.height)
	{
		if (cub3D->map.map[(int)(first_inter.y_intercept / 64)]
							[(int)(first_inter.x_intercept / 64)] == 1)
		{
			break ;
		}
		else
		{
			first_inter.x_intercept += first_inter.x_step;
			first_inter.y_intercept += first_inter.y_step;
		}
	}
	h_inter.x = first_inter.x_intercept;
	h_inter.y = first_inter.y_intercept;
	h_inter.color = 0x00FF00;
	return (h_inter);
}

void	init_vetical_params(t_cub3D *cub3D, t_intesc_params *first_inter,
		double ra)
{
	double	my_tan;

	my_tan = -tan(ra);
	if (ra > M_PI_2 && ra < (3 * M_PI_2))
	{
		first_inter->x_intercept = (((int)cub3D->player.px >> 6) << 6) - 0.0001;
		first_inter->x_step = -64;
	}
	if (ra < M_PI_2 || ra > (3 * M_PI_2))
	{
		first_inter->x_intercept = (((int)cub3D->player.px >> 6) << 6) + 64;
		first_inter->x_step = 64;
	}
	if (ra == M_PI_2 || ra == (M_PI_2 * 3))
	{
		first_inter->x_intercept = cub3D->player.px;
		first_inter->y_intercept = cub3D->player.py;
	}
	first_inter->y_intercept = (cub3D->player.px - first_inter->x_intercept)
		* my_tan + cub3D->player.py;
	first_inter->y_step = -first_inter->x_step * my_tan;
}

t_point	check_vertical_intersection(t_cub3D *cub3D, double ra)
{
	t_intesc_params	first_inter;
	t_point			v_inter;

	init_vetical_params(cub3D, &first_inter, ra);
	while ((int)(first_inter.x_intercept / VECTOR) >= 0 &&
			(int)(first_inter.x_intercept / VECTOR) < cub3D->map.width &&
			(int)(first_inter.y_intercept / VECTOR) >= 0 &&
			(int)(first_inter.y_intercept / VECTOR) < cub3D->map.height)
	{
		if (cub3D->map.map[(int)(first_inter.y_intercept / 64)]
							[(int)(first_inter.x_intercept / 64)] == 1)
		{
			break ;
		}
		else
		{
			first_inter.x_intercept += first_inter.x_step;
			first_inter.y_intercept += first_inter.y_step;
		}
	}
	v_inter.x = first_inter.x_intercept;
	v_inter.y = first_inter.y_intercept;
	v_inter.color = 0x00FF00;
	return (v_inter);
}

void	check_h_v_intersection(t_cub3D *cub3D)
{
	t_point	h_inter;
	t_point	v_inter;
	double	h_distance;
	double	v_distance;

	h_distance = INT_MAX;
	v_distance = INT_MAX;
	h_inter = check_horizontal_intersection(cub3D, cub3D->ray_data.ra);
	h_distance = distance_between_points(cub3D->player.px, cub3D->player.py,
			h_inter.x, h_inter.y);
	v_inter = check_vertical_intersection(cub3D, cub3D->ray_data.ra);
	v_distance = distance_between_points(cub3D->player.px, cub3D->player.py,
			v_inter.x, v_inter.y);
	if (h_distance < v_distance)
	{
		cub3D->ray_data.inter_point = h_inter;
		cub3D->ray_data.final_distance = h_distance;
		cub3D->ray_data.ray_hit_h = 1;
	}
	else
	{
		cub3D->ray_data.inter_point = v_inter;
		cub3D->ray_data.final_distance = v_distance;
		cub3D->ray_data.ray_hit_h = 0;
	}
}
