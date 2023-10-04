

#include "includes/cub3D.h"
#include "libft/libft.h"
// #include "minilibx-linux/mlx.h"
#include <stdio.h>
void init_texturs(t_cub3D *cub3D)
{
  cub3D->texture_SO.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/SO.xpm", &cub3D->texture_SO.width,&cub3D->texture_SO.height);
  cub3D->texture_SO.addr =  mlx_get_data_addr(cub3D->texture_SO.img, &cub3D->texture_SO.bits_per_pixel, &cub3D->texture_SO.line_length, &cub3D->texture_SO.endian);
  cub3D->texture_NO.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/NO.xpm", &cub3D->texture_NO.width,&cub3D->texture_NO.height);
  cub3D->texture_NO.addr =  mlx_get_data_addr(cub3D->texture_NO.img, &cub3D->texture_NO.bits_per_pixel, &cub3D->texture_NO.line_length, &cub3D->texture_NO.endian);
  cub3D->texture_WE.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/WE.xpm", &cub3D->texture_WE.width,&cub3D->texture_WE.height);
  cub3D->texture_WE.addr =  mlx_get_data_addr(cub3D->texture_WE.img, &cub3D->texture_WE.bits_per_pixel, &cub3D->texture_WE.line_length, &cub3D->texture_WE.endian);
  cub3D->texture_EA.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, "./textures/EA.xpm", &cub3D->texture_EA.width,&cub3D->texture_EA.height);
  cub3D->texture_EA.addr =  mlx_get_data_addr(cub3D->texture_EA.img, &cub3D->texture_EA.bits_per_pixel, &cub3D->texture_EA.line_length, &cub3D->texture_EA.endian);
}
int main(int argc, char *argv[]) {


  t_cub3D cub3D;
  t_parse *parse;
  t_map *map;

//parsing the game
  parse = malloc(sizeof(t_parse));
  check_all(parse, argc, argv);

//init the map
  map = malloc(sizeof(t_map));
  init_s_map(map, parse);
  print_arg_map(map);

  init_data(&cub3D);
  
  cub3D.ptr_mlx = mlx_init();
  cub3D.mlx_win = mlx_new_window(cub3D.ptr_mlx, WIDTH,HEIGHT, "cub3d");
  cub3D.data.img =
      mlx_new_image(cub3D.ptr_mlx, WIDTH,HEIGHT);
  cub3D.data.addr = mlx_get_data_addr(cub3D.data.img, &cub3D.data.bits_per_pixel,
                                &cub3D.data.line_length, &cub3D.data.endian);
  init_texturs(&cub3D);
  hooks_handler(&cub3D);
  mlx_loop(cub3D.ptr_mlx);
  return 0;
}
