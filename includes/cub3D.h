#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "structs.h"
#include <X11/X.h>
#include "keys.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "parsing.h"
#define HEIGHT 740
#define WIDTH 1024

// #define HEIGHT 1024
// #define WIDTH 2048
#define VECTOR 64
#define DEGREE 0.0174533 

void init_data(t_cub3D *cub3D);
void draw_2d_map(t_cub3D cub3D);
void hooks_handler(t_cub3D *cub3D);
int my_mlx_pixel_put(t_cub3D *cub3D, int x, int y, int color);
void draw_square(t_point point, int len, t_cub3D *cub3D, int draw_borders);
void draw_player(t_cub3D *cub3D);
void draw_line(t_cub3D cub3D, t_point pt_0, t_point pt_1);
void draw_player_direction(t_cub3D *cub3D);
void draw_all_rays(t_cub3D *cub3D);
t_point check_horizontal_intersection(t_cub3D *cub3D, double ra);
t_point check_vertical_intersection(t_cub3D *cub3D, double ra);
void draw_rays_2D(t_cub3D *cub3D);
double distance_between_points(double x1, double y1, double x2, double y2);
void draw_rectangle(t_cub3D *cub3D, t_point point, int height, int width);
void draw_circle(t_cub3D *cub3D, int center_x, int center_y, int radius, int color);

#endif