

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
int *textures_buffering()
{
  int *buffer;
  buffer = malloc(sizeof(int) * (WIDTH * HEIGHT));
  int i = 0;
  int j = 0;
  //need to change Vector to width and height of the texture
  while( i < VECTOR)
  {
    j = 0;
    while(j < VECTOR)
    {
      if(i%8 && j % 8)
        buffer[i * VECTOR + j] =0xA76F6F;
      else
        buffer[i * VECTOR + j] =  0xEAB2A0;
      j++;
    }
    i++;
  }
  return buffer;
}
int * ceiling_floor_buffering()
{
  int *buffer;
  buffer = malloc(sizeof(int) * (WIDTH * HEIGHT));
  int i = 0;
  while (i < (WIDTH * HEIGHT) / 2)
    buffer[i++] = 0xDAFFFB;
  while (i < WIDTH * HEIGHT)
    buffer[i++] = 0xEAC696;
  return buffer;
}
void set_texturs(t_cub3D *cub3D, double ra ,int flag)
{
  cub3D->texture_SO.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/SO.xpm", &cub3D->texture_SO.width,&cub3D->texture_SO.height);
  cub3D->texture_SO.addr =  mlx_get_data_addr(cub3D->texture_SO.img, &cub3D->texture_SO.bits_per_pixel, &cub3D->texture_SO.line_length, &cub3D->texture_SO.endian);
  cub3D->texture_NO.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/NO.xpm", &cub3D->texture_NO.width,&cub3D->texture_NO.height);
  cub3D->texture_NO.addr =  mlx_get_data_addr(cub3D->texture_NO.img, &cub3D->texture_NO.bits_per_pixel, &cub3D->texture_NO.line_length, &cub3D->texture_NO.endian);
  cub3D->texture_WE.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/WE.xpm", &cub3D->texture_WE.width,&cub3D->texture_WE.height);
  cub3D->texture_WE.addr =  mlx_get_data_addr(cub3D->texture_WE.img, &cub3D->texture_WE.bits_per_pixel, &cub3D->texture_WE.line_length, &cub3D->texture_WE.endian);
  cub3D->texture_EA.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/EA.xpm", &cub3D->texture_EA.width,&cub3D->texture_EA.height);
  cub3D->texture_EA.addr =  mlx_get_data_addr(cub3D->texture_EA.img, &cub3D->texture_EA.bits_per_pixel, &cub3D->texture_EA.line_length, &cub3D->texture_EA.endian);
  
  if(flag == 1)
  {
    if(ra > 0 && ra < M_PI)
      cub3D->texture = cub3D->texture_SO;
    else
      cub3D->texture = cub3D->texture_NO;

  }else
  {
    if(ra > (0.5 * M_PI) && ra < (1.5 * M_PI))
      cub3D->texture = cub3D->texture_WE;
    else
      cub3D->texture = cub3D->texture_EA;
  }
}
void draw_rays_2D(t_cub3D *cub3D) {
  double ra;
  t_point h_inter;
  t_point v_inter;
  t_point inter;
  double h_distance;
  double v_distance;
  double final_distance;
  int *buffer;
  int *texture_buffer;
  int i;
  h_distance = INT_MAX;
  v_distance = INT_MAX;
  ra = cub3D->player.retation_angle - DEGREE * 30;
  //-------------------------------------------------------//
  // int width;
  // int height;
  // char *data_addr;
  // void *img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/SO.xpm", &width,&height);
  // data_addr =  mlx_get_data_addr(img, &cub3D->data.bits_per_pixel, &cub3D->data.line_length, &cub3D->data.endian);
  //-------------------------------------------------------//
  // cub3D->texture.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/SO.xpm", &cub3D->texture.width,&cub3D->texture.height);
  // cub3D->texture.addr =  mlx_get_data_addr(cub3D->texture.img, &cub3D->texture.bits_per_pixel, &cub3D->texture.line_length, &cub3D->texture.endian);



  ra = norm_angle(ra);
  buffer = ceiling_floor_buffering();
  texture_buffer = textures_buffering();  
  i = 0;
  while (i < WIDTH) {
    h_inter = check_horizontal_intersection(cub3D, ra);
    h_distance = distance_between_points(cub3D->player.px, cub3D->player.py,
                                         h_inter.x, h_inter.y);

    v_inter = check_vertical_intersection(cub3D, ra);
    v_distance = distance_between_points(cub3D->player.px, cub3D->player.py,
                                         v_inter.x, v_inter.y);
    if (h_distance < v_distance){
      inter = h_inter;
      final_distance = h_distance;
    }
    else{
      inter = v_inter;
      final_distance = v_distance;
    }
    //---------------3D------------------//
    double line_h;
    double new_angle;
    int top_pixel;
    int bottom_pixel;
    int texture_x;
    int texture_y;
    int color;
    int j ;
    new_angle = cub3D->player.retation_angle - ra;
    final_distance *= cos(new_angle);
    line_h = (64 * WIDTH) / final_distance;
    top_pixel = ((double)HEIGHT / 2) - (line_h / 2);
    bottom_pixel = ((double)HEIGHT / 2) + (line_h / 2);
    if(top_pixel < 0)
      top_pixel = 0;
    if(bottom_pixel > HEIGHT)
      bottom_pixel = HEIGHT;
     //-----------------------------------------------------//
    if(h_distance < v_distance)
    { set_texturs(cub3D, ra, 1);
      texture_x = (int)h_inter.x % 64;
    }
    else
    { set_texturs(cub3D, ra, 0);
      texture_x = (int)v_inter.y % 64;
    }

    j = top_pixel;
    while(j < bottom_pixel)
    {
      int distance_from_top = j + (line_h / 2) - (HEIGHT / 2);
      //need to change 64 to the width of the texture
       int texture_y = distance_from_top * (cub3D->texture.height / line_h);
       buffer[j * WIDTH + i] = *(int *)(cub3D->texture.addr + (texture_y * cub3D->texture.line_length )+ texture_x * (cub3D->texture.bits_per_pixel / 8));
       j++;
    }

    //------------------------------------------------------------------//
    i++;
    ra += (60.0 / WIDTH) * DEGREE;
    ra = norm_angle(ra);
  }
  i = 0;
  while (i < WIDTH * HEIGHT)
  {
    ((int *)cub3D->data.addr)[i] = buffer[i];
    i++;
  }
  free(texture_buffer);
  free(buffer);
  

 
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
    // while (i < (HEIGHT * WIDTH) / 2)
    //   ((int *)cub3D->data.addr)[i++] = 0xCAEDFF;
    // while (i < HEIGHT * WIDTH)
    //   ((int *)cub3D->data.addr)[i++] = 0xC08261;
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
