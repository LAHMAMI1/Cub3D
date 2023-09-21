#ifndef STRUCTS_H
# define STRUCTS_H

#include <math.h>
#include <mlx.h>

typedef struct s_intesection_params {

  double x_intercept;
  double y_intercept;
  double x_step;
  double y_step;
} t_intesc_params;

typedef struct s_data {
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_data;

typedef struct s_point {
  int x;
  int y;
  int color;
} t_point;

typedef struct s_player {
  double x;
  double y;
  int px;
  int py;
  double dx;
  double dy;
  double dw;
  double speed;
  double retation_angle;
  double retation_speed;
  int color;
} t_player;

typedef struct s_variables {
  int dx;
  int dy;
  int sx;
  int sy;
  int error;
  int e2;
} t_vars;

typedef struct s_ray_params {
  int fov_angle;
  int rays_namber;
  int pix_per_colom;

} t_ray_params;

typedef struct s_ray {
  double ray_angle;
  double ray_hit_wall_x;
  double ray_hit_wall_y;
  double distance;
  int ray_facing_up;
  int ray_facing_down;
  int ray_facing_left;
  int ray_facing_right;
} t_ray;

typedef struct s_cub3D {

  void *ptr_mlx;
  void *mlx_win;
  int height;
  int width;
  int **points;
  t_player player;
  t_data data;
  t_ray_params ray_params;
  // t_ray ray;
} t_cub3D;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	t_point	player;
	char 	player_direction;
	int floor_color;
	int ceiling_color;
} t_map;



typedef struct s_parse
{
	int fd;
	char *argv;
	int fd_empty;
	char *str;
	char **split_file;
	char **split_identifier;
	char **split_map;
	char *path;
} t_parse;

#endif