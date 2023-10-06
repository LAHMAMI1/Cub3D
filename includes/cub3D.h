/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:29:47 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 12:50:48 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "keys.h"
# include "parsing.h"
# include "structs.h"
# include <X11/X.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# define HEIGHT 740
# define WIDTH 1024

# define VECTOR 64
# define DEGREE 0.0174533

void	init_data(t_cub3D *cub3D);
void	draw_2d_map(t_cub3D cub3D);
void	hooks_handler(t_cub3D *cub3D);
int		my_mlx_pixel_put(t_cub3D *cub3D, int x, int y, int color);
void	draw_square(t_point point, int len, t_cub3D *cub3D, int draw_borders);
void	draw_player(t_cub3D *cub3D);
void	draw_line(t_cub3D cub3D, t_point pt_0, t_point pt_1);
void	draw_player_direction(t_cub3D *cub3D);
void	draw_all_rays(t_cub3D *cub3D);
t_point	check_horizontal_intersection(t_cub3D *cub3D, double ra);
t_point	check_vertical_intersection(t_cub3D *cub3D, double ra);
void	draw_walls(t_cub3D *cub3D);
double	distance_between_points(double x1, double y1, double x2, double y2);
void	draw_rectangle(t_cub3D *cub3D, t_point point, int height, int width);
void	draw_circle(t_cub3D *cub3D, int center_x, int center_y, int radius,
			int color);
int		*ceiling_floor_buffering(t_cub3D *cub3D);
t_data	set_texturs(t_cub3D *cub3D, double ra, int flag);
void	draw_texturs(t_cub3D *cub3D, int *buffer);
void	textures_buffering(t_cub3D *cub3D, int *buffer, int i);
void	draw_player_direction(t_cub3D *cub3D);
void	check_h_v_intersection(t_cub3D *cub3D);
void	calcul_ray_data(t_cub3D *cub3D, int *texture_x, int *texture_y);
void	free_map(t_cub3D *cub3D);
void	close_window(t_cub3D *cub3D);
double	norm_angle(double angle);
double	distance_between_points(double x1, double y1, double x2, double y2);
int		square_is_wall(t_cub3D *cub3D, double i, double j);
void	update_move_speed(t_cub3D *cub3D, double *move_speed, double *angle);
void	update_player(t_cub3D *cub3D);
void	draw_ray(t_cub3D *cub3D, t_ray ray);
void	calcul_ray_params(t_cub3D *cub3D, t_ray *ray, double ray_angle);
void	calcul_ray_data(t_cub3D *cub3D, int *texture_x, int *texture_y);
void	draw_walls(t_cub3D *cub3D);
void	draw_all_rays(t_cub3D *cub3D);

#endif