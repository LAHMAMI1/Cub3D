/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:49:19 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/07 16:51:13 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_ray(t_cub *cub3D, t_ray ray)
{
	t_point	pt_1;
	t_point	pt_0;

	pt_0.y = cub3D->player.py;
	pt_0.x = cub3D->player.px;
	pt_0.color = 0x952323;
	pt_1.y = pt_0.y + sin(ray.ray_angle) * VECTOR;
	pt_1.x = pt_0.x + cos(ray.ray_angle) * VECTOR;
	pt_1.color = 0x952323;
	draw_line(*cub3D, pt_0, pt_1);
}

void	calcul_ray_params(t_ray *ray, double ray_angle)
{
	ray->ray_angle = norm_angle(ray_angle);
	ray->ray_facing_down = (ray->ray_angle > 0 && ray->ray_angle < M_PI);
	ray->ray_facing_up = !ray->ray_facing_down;
	ray->ray_facing_right
		= (ray->ray_angle < (0.5 * M_PI) || ray->ray_angle > (1.5 * M_PI));
	ray->ray_facing_left = !ray->ray_facing_right;
}

void	calcul_ray_data(t_cub *cub3D, int *texture_x)
{
	cub3D->ray_data.new_angle = cub3D->player.retation_angle
		- cub3D->ray_data.ra;
	cub3D->ray_data.final_distance *= cos(cub3D->ray_data.new_angle);
	cub3D->ray_data.line_h = (VECTOR * WIDTH) / cub3D->ray_data.final_distance;
	cub3D->ray_data.top_pixel = ((double)HEIGHT / 2) - (cub3D->ray_data.line_h
			/ 2);
	cub3D->ray_data.bottom_pixel = ((double)HEIGHT / 2)
		+ (cub3D->ray_data.line_h / 2);
	if (cub3D->ray_data.top_pixel < 0)
		cub3D->ray_data.top_pixel = 0;
	if (cub3D->ray_data.bottom_pixel > HEIGHT)
		cub3D->ray_data.bottom_pixel = HEIGHT;
	if (cub3D->ray_data.ray_hit_h)
	{
		cub3D->ray_data.texture = set_texturs(cub3D, cub3D->ray_data.ra, 1);
		*texture_x = (int)cub3D->ray_data.inter_point.x % VECTOR;
	}
	else
	{
		cub3D->ray_data.texture = set_texturs(cub3D, cub3D->ray_data.ra, 0);
		*texture_x = (int)cub3D->ray_data.inter_point.y % VECTOR;
	}
}

void	draw_walls(t_cub *cub3D)
{
	int	*buffer;
	int	i;

	cub3D->ray_data.ra = cub3D->player.retation_angle - DEGREE * 30;
	cub3D->ray_data.ra = norm_angle(cub3D->ray_data.ra);
	buffer = ceiling_floor_buffering(cub3D);
	i = 0;
	while (i < WIDTH)
	{
		textures_buffering(cub3D, buffer, i);
		i++;
		cub3D->ray_data.ra += (60.0 / WIDTH) * DEGREE;
		cub3D->ray_data.ra = norm_angle(cub3D->ray_data.ra);
	}
	draw_texturs(cub3D, buffer);
	free(buffer);
}
