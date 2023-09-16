

#include "../includes/cub3D.h"
#include <stdio.h>

void draw_square(t_point point, int len, t_cub3D *cub3D, int draw_borders) {
  int i;
  int j;

  j = 0;
  while (j < len) {
    i = 0;
    while (i < len) {
      if (draw_borders && (i == len - 1 || j == len - 1))
        my_mlx_pixel_put(cub3D, i + point.x, j + point.y, 0x000000);
      else
        my_mlx_pixel_put(cub3D, i + point.x, j + point.y, point.color);
      i++;
    }
    j++;
  }
}

void draw_rectangle(t_cub3D *cub3D, t_point point, int height, int width) {
  int i;
  int j;
	i=0;
  while (i < width) {
    j = 0;
    while (j < height) {

      my_mlx_pixel_put(cub3D, i + point.x, j + point.y, point.color);
      j++;
    }
    i++;
  }
}
// this fucntion hj::
void draw_player(t_cub3D *cub3D) {
  t_point point;
  point.y = (cub3D->player.x * VECTOR) + ((double)VECTOR / 2) - 8;
  point.x = (cub3D->player.y * VECTOR) + ((double)VECTOR / 2) - 8;
  point.color = cub3D->player.color;
  draw_rays_2D(cub3D);
  // draw_square(point, 16, cub3D, 0);
  // draw_player_direction(cub3D);
}

void draw_2d_map(t_cub3D cub3D) {
  int i;
  int j;
  t_point point;
  t_player player;
  i = 0;
  while (i < cub3D.height) {
    j = 0;
    while (j < cub3D.width) {

      point.x = j * VECTOR;
      point.y = i * VECTOR;
      point.color = 0x053B50;
      if (!cub3D.points[i][j])
        point.color = 0xEEEEEE;
      draw_square(point, VECTOR, &cub3D, 1);
      j++;
    }
    i++;
  }
}
