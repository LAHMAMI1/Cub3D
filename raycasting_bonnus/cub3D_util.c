/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:41:13 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 12:52:55 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_map(t_cub3D *cub3D)
{
	int	i;

	i = 0;
	while (i < cub3D->map.height)
	{
		free(cub3D->map.map[i]);
		i++;
	}
	free(cub3D->map.map);
}

void	close_window(t_cub3D *cub3D)
{
	mlx_destroy_window(cub3D->ptr_mlx, cub3D->mlx_win);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->data.img);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->texture_SO.img);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->texture_NO.img);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->texture_WE.img);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->texture_EA.img);
	free_map(cub3D);
	exit(0);
}

double	norm_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
