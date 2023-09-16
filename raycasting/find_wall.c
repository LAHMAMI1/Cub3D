#include "../includes/cub3D.h"
#include <math.h>
#include <stdio.h>

// int point_is_wall(t_cub3D *cub3D, int x, int y) {
//   int i;
//   int j;
//   i = (int)(x / (double)VECTOR);
//   j = (int)(y / (double)VECTOR);
//   // printf("i = %d | j = %d \n", i, j);
//   return cub3D->points[j][i];
// }


double distance_between_points(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void init_horizontal_params(t_cub3D *cub3D, t_intesc_params *first_inter,
                            double ra) {

  double my_tan;

  my_tan = -1 / tan(ra);
  if (ra > M_PI) {
    first_inter->y_intercept = (((int)cub3D->player.py >> 6) << 6) - 0.0001;
    first_inter->y_step = -64;
  }
  if (ra < M_PI) {
    first_inter->y_intercept = (((int)cub3D->player.py >> 6) << 6) + 64;
    first_inter->y_step = 64;
  }
  if (ra == 0 || ra == M_PI) {
    first_inter->x_intercept = cub3D->player.px;
    first_inter->y_intercept = cub3D->player.py;
  }
  first_inter->x_intercept =
      (cub3D->player.py - first_inter->y_intercept) * my_tan + cub3D->player.px;
  first_inter->x_step = -first_inter->y_step * my_tan;
}

t_point check_horizontal_intersection(t_cub3D *cub3D, double ra) {

  t_intesc_params first_inter;
  t_point h_inter;

  init_horizontal_params(cub3D, &first_inter, ra);
  while ((int)(first_inter.x_intercept / 64) >= 0 &&
         (int)(first_inter.x_intercept / 64) < cub3D->width &&
         (int)(first_inter.y_intercept / 64) >= 0 &&
         (int)(first_inter.y_intercept / 64) < cub3D->height) {
    if (cub3D->points[(int)(first_inter.y_intercept / 64)]
                     [(int)(first_inter.x_intercept / 64)] == 1) {
      break;
    } else {
      first_inter.x_intercept += first_inter.x_step;
      first_inter.y_intercept += first_inter.y_step;
    }
  }
  h_inter.x = first_inter.x_intercept;
  h_inter.y = first_inter.y_intercept;
  h_inter.color = 0x00FF00;
  return h_inter;
}

void init_vetical_params(t_cub3D *cub3D, t_intesc_params *first_inter,
                         double ra) {

  double my_tan;

  my_tan = -tan(ra);
  if (ra > M_PI_2 && ra < (3 * M_PI_2)) {
    first_inter->x_intercept = (((int)cub3D->player.px >> 6) << 6) - 0.0001;
    first_inter->x_step = -64;
  }
  if (ra < M_PI_2 || ra > (3 * M_PI_2)) {
    first_inter->x_intercept = (((int)cub3D->player.px >> 6) << 6) + 64;
    first_inter->x_step = 64;
  }
  if (ra == M_PI_2 || ra == (M_PI_2* 3)) {
    first_inter->x_intercept = cub3D->player.px;
    first_inter->y_intercept = cub3D->player.py;
  }
  first_inter->y_intercept =
      (cub3D->player.px - first_inter->x_intercept) * my_tan + cub3D->player.py;
  first_inter->y_step = -first_inter->x_step * my_tan;
}

t_point check_vertical_intersection(t_cub3D *cub3D, double ra) {
  t_intesc_params first_inter;
  t_point v_inter;

  init_vetical_params(cub3D, &first_inter, ra);
  while ((int)(first_inter.x_intercept / 64) >= 0 &&
         (int)(first_inter.x_intercept / 64) < cub3D->width &&
         (int)(first_inter.y_intercept / 64) >= 0 &&
         (int)(first_inter.y_intercept / 64) < cub3D->height) {
    if (cub3D->points[(int)(first_inter.y_intercept / 64)]
                     [(int)(first_inter.x_intercept / 64)] == 1) {
      break;
    } else {
      first_inter.x_intercept += first_inter.x_step;
      first_inter.y_intercept += first_inter.y_step;
    }
  }
  v_inter.x = first_inter.x_intercept;
  v_inter.y = first_inter.y_intercept;
  v_inter.color = 0x00FF00;
  return v_inter;
}
