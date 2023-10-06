/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:46:10 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 12:56:00 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	square_is_wall(t_cub3D *cub3D, double i, double j)
{
	double	step;

	step = 8 / (double)VECTOR;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	i += step;
	j += step;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	j -= step * 2;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	i -= step * 2;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	j += step * 2;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	return (0);
}

void	update_move_speed(t_cub3D *cub3D, double *move_speed, double *angle)
{
	if (cub3D->player.dy)
	{
		*move_speed = cub3D->player.dy * 0.05;
		*angle = cub3D->player.retation_angle;
	}
	else if (cub3D->player.dw)
	{
		*move_speed = cub3D->player.dw * 0.05;
		*angle = cub3D->player.retation_angle + (3 * M_PI / 2);
	}
}

void	update_player(t_cub3D *cub3D)
{
	double	move_speed;
	double	i;
	double	j;
	double	angle;

	cub3D->player.retation_angle
		+= cub3D->player.dx * cub3D->player.retation_speed;
	cub3D->player.retation_angle = norm_angle(cub3D->player.retation_angle);
	update_move_speed(cub3D, &move_speed, &angle);
	i = cub3D->player.x + sin(angle) * move_speed;
	j = cub3D->player.y;
	if (!square_is_wall(cub3D, i + 0.5, j + 0.5))
		cub3D->player.x = i;
	i = cub3D->player.x;
	j = cub3D->player.y + cos(angle) * move_speed;
	if (!square_is_wall(cub3D, i + 0.5, j + 0.5))
		cub3D->player.y = j;
	cub3D->player.px = (j * VECTOR) + (double)VECTOR / 2;
	cub3D->player.py = (i * VECTOR) + (double)VECTOR / 2;
}
