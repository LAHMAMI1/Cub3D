

#include "../includes/cub3D.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void init_player(t_cub3D *cub3D, int i, int j) {
  cub3D->player.x = i;
  cub3D->player.y = j;
  cub3D->player.px = (j * VECTOR) + ((double)VECTOR / 2);
  cub3D->player.py = (i * VECTOR) + ((double)VECTOR / 2);
  cub3D->player.color = 0x64CCC5;
  cub3D->player.retation_angle = M_PI / 2;
  cub3D->player.retation_speed = 2 * (M_PI / 180);
  cub3D->player.speed = 0.7;
}

void init_ray_params(t_cub3D *cub3D) {
  cub3D->ray_params.fov_angle = 60 * (M_PI / 180);
  cub3D->ray_params.pix_per_colom = 5;
  cub3D->ray_params.rays_namber =
      (cub3D->width * VECTOR) / cub3D->ray_params.pix_per_colom;
}

void init_data(t_cub3D *cub3D) {
  int i;
  int j;
  int initialMatrix[10][20] = {
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
      {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 1, 0, 2, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
  i = -1;
  cub3D->width = 20;
  cub3D->height = 10;
  cub3D->points = (int **)malloc(sizeof(int *) * cub3D->height);
  ft_memset(&cub3D->player, 0, sizeof(t_player));
  while (++i < cub3D->height)
    cub3D->points[i] = malloc(sizeof(int *) * cub3D->width);
  i = -1;
  while (++i < cub3D->height) {
    j = -1;
    while (++j < cub3D->width) {

      if (initialMatrix[i][j] != 1 && initialMatrix[i][j] != 0) {
        cub3D->points[i][j] = 0;
        init_player(cub3D, i, j);
        continue;
      }
      cub3D->points[i][j] = initialMatrix[i][j];
    }
  }
  init_ray_params(cub3D);
}
