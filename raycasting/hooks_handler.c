

#include "../includes/cub3D.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

int key_up(int keycode, t_cub3D *cub3D) {
  if (keycode == KEY_W || keycode == KEY_S)
    cub3D->player.dy = 0;
  if (keycode == KEY_D || keycode == KEY_A)
    cub3D->player.dw = 0;
  if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
    cub3D->player.dx = 0;
  return 0;
}

int square_is_wall(t_cub3D *cub3D, double i, double j) {
  double step;

  step = 8 / (double)VECTOR;
  if (cub3D->points[(int)i][(int)j] == 1)
    return 1;
  i += step;
  j += step;
  if (cub3D->points[(int)i][(int)j] == 1)
    return 1;
  j -= step * 2;
  if (cub3D->points[(int)i][(int)j] == 1)
    return 1;
  i -= step * 2;
  if (cub3D->points[(int)i][(int)j] == 1)
    return 1;
  j += step * 2;
  if (cub3D->points[(int)i][(int)j] == 1)
    return 1;
  return 0;
}

double norm_angle(double angle) {
  if (angle < 0)
    angle += 2 * M_PI;
  if (angle > 2 * M_PI)
    angle -= 2 * M_PI;
  return angle;
}

void update_player(t_cub3D *cub3D) {
  double move_speed;
  double i;
  double j;
  double angle;

  cub3D->player.retation_angle +=
      cub3D->player.dx * cub3D->player.retation_speed;
  cub3D->player.retation_angle = norm_angle(cub3D->player.retation_angle);
  if (cub3D->player.dy) {

    move_speed = cub3D->player.dy * 0.05;
    angle = cub3D->player.retation_angle;
  } else if (cub3D->player.dw) {

    move_speed = cub3D->player.dw * 0.05;
    angle = cub3D->player.retation_angle + (3 * M_PI / 2);
  }
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

int key_down(int keycode, t_cub3D *cub3D) {
  if (keycode == KEY_W)
    cub3D->player.dy = cub3D->player.speed * 1;
  if (keycode == KEY_S)
    cub3D->player.dy = cub3D->player.speed * -1;
  if (keycode == KEY_A)
    cub3D->player.dw = cub3D->player.speed * 1;
  if (keycode == KEY_D)
    cub3D->player.dw = cub3D->player.speed * -1;
  if (keycode == KEY_LEFT)
    cub3D->player.dx = cub3D->player.speed * 1;
  if (keycode == KEY_RIGHT)
    cub3D->player.dx = cub3D->player.speed * -1;
  if (keycode == KEY_ESC)
    exit(0);
  return 0;
}

void draw_ray(t_cub3D *cub3D, t_ray ray) {

  t_point pt_1;
  t_point pt_0;
  pt_0.y = cub3D->player.py;
  pt_0.x = cub3D->player.px;
  pt_0.color = 0x952323;
  pt_1.y = pt_0.y + sin(ray.ray_angle) * VECTOR;
  pt_1.x = pt_0.x + cos(ray.ray_angle) * VECTOR;
  pt_1.color = 0x952323;
  draw_line(*cub3D, pt_0, pt_1);
}

void calcul_ray_params(t_cub3D *cub3D, t_ray *ray, double ray_angle) {

  ray->ray_angle = norm_angle(ray_angle);
  ray->ray_facing_down = (ray->ray_angle > 0 && ray->ray_angle < M_PI);
  ray->ray_facing_up = !ray->ray_facing_down;
  ray->ray_facing_right =
      (ray->ray_angle < (0.5 * M_PI) || ray->ray_angle > (1.5 * M_PI));
  ray->ray_facing_left = !ray->ray_facing_right;
}

void draw_rays_2D(t_cub3D *cub3D) {
  double ra;
  t_point h_inter;
  t_point v_inter;
  double h_distance;
  double v_distance;
  double final_distance;
  int i;
  h_distance = INT_MAX;
  v_distance = INT_MAX;
  ra = cub3D->player.retation_angle - DEGREE * 30;
  ra = norm_angle(ra);
  i = 0;
  while (i < WIDTH) {
    // printf("ra = %f\n", ra);
    h_inter = check_horizontal_intersection(cub3D, ra);
    h_distance = distance_between_points(cub3D->player.px, cub3D->player.py,
                                         h_inter.x, h_inter.y);

    v_inter = check_vertical_intersection(cub3D, ra);
    v_distance = distance_between_points(cub3D->player.px, cub3D->player.py,
                                         v_inter.x, v_inter.y);
    if (h_distance < v_distance) {
      // draw_line(*cub3D, (t_point){cub3D->player.px, cub3D->player.py, 0xEAB2A0},
      //           (t_point){h_inter.x, h_inter.y, 0x00FF00});
      final_distance = h_distance;

    } else {
      // draw_line(*cub3D, (t_point){cub3D->player.px, cub3D->player.py, 0xEAB2A0},
      //           (t_point){v_inter.x, v_inter.y, 0x00FF00});
      final_distance = v_distance;
    }
    //---------------3D------------------//
    double line_h;
    double new_angle;
    new_angle = cub3D->player.retation_angle - ra;
    final_distance *= cos(new_angle);
    line_h = (64 * WIDTH) / final_distance;
    if (line_h > HEIGHT)
      line_h = HEIGHT;
    if (h_distance < v_distance) {
      draw_rectangle(
          cub3D,
          (t_point){i, ((double)HEIGHT / 2) - (line_h / 2), 0xEADBC8},
          line_h, 2);
    } else {

      draw_rectangle(
          cub3D,
          (t_point){i, ((double)HEIGHT / 2) - (line_h / 2), 0xDAC0A3},
          line_h, 2);
    }
    //------------------------------------------------------------------//
    i++;
    ra += (60.0 / WIDTH) * DEGREE;
    ra = norm_angle(ra);
  }
}
void draw_all_rays(t_cub3D *cub3D) {
  int i;
  t_ray ray;
  double ray_angle;
  t_point horizontal_inter;
  t_point vertical_inter;

  ray_angle =
      cub3D->player.retation_angle - ((double)cub3D->ray_params.fov_angle / 2);
  i = 0;

  while (i < cub3D->ray_params.rays_namber) {
    ray_angle +=
        (double)cub3D->ray_params.fov_angle / cub3D->ray_params.rays_namber;
    if (i == cub3D->ray_params.rays_namber / 2) {

      calcul_ray_params(cub3D, &ray, ray_angle);
      draw_line(*cub3D, (t_point){cub3D->player.py, cub3D->player.px, 0xAE445A},
                (t_point){vertical_inter.x, vertical_inter.y, 0x00FF00});
    }
    i++;
  }
}

void draw_player_direction(t_cub3D *cub3D) {

  t_point pt_1;
  t_point pt_0;

  pt_0.y = cub3D->player.py;
  pt_0.x = cub3D->player.px;
  pt_0.color = cub3D->player.color;
  pt_1.y = pt_0.y + sin(cub3D->player.retation_angle) * VECTOR;
  pt_1.x = pt_0.x + cos(cub3D->player.retation_angle) * VECTOR;
  pt_1.color = cub3D->player.color;
  draw_line(*cub3D, pt_0, pt_1);
}

void draw_new_move(t_cub3D *cub3D) {

  static int var;
  if (var > 1) {
    int i = 0;
    while (i < (HEIGHT * WIDTH) / 2)
      ((int *)cub3D->data.addr)[i++] = 0xCAEDFF;
    while (i < HEIGHT * WIDTH)
      ((int *)cub3D->data.addr)[i++] = 0xC08261;
    // draw_2d_map(*cub3D);
    update_player(cub3D);
    draw_player(cub3D);
    // draw_circle(cub3D, 70, 670, 60, 0x000000);
    // draw_circle(cub3D, 70, 670, 53, 0x000000);
    mlx_put_image_to_window(cub3D->ptr_mlx, cub3D->mlx_win, cub3D->data.img, 0,
                            0);
    var = 0;
  }
  var++;
}

void hooks_handler(t_cub3D *cub3D) {
  mlx_loop_hook(cub3D->ptr_mlx, (void *)draw_new_move, cub3D);
  mlx_hook(cub3D->mlx_win, KeyPress, KeyPressMask, key_down, cub3D);
  mlx_hook(cub3D->mlx_win, KeyRelease, KeyReleaseMask, key_up, cub3D);
}
