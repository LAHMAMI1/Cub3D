

#include "includes/cub3D.h"
#include "libft/libft.h"
// #include "minilibx-linux/mlx.h"
#include <stdio.h>

int main(int argc, char *argv[]) {


  t_cub3D cub3D;
  t_parse parse;
//   int i;
//   i = 0;
  check_args(argc, argv, &parse);
  check_all(&parse);

  printf("parse->no = %s\n", parse.no);
  printf("parse->so = %s\n", parse.so);
  printf("parse->we = %s\n", parse.we);
  printf("parse->ea = %s\n", parse.ea);
  init_data(&cub3D);
  cub3D.ptr_mlx = mlx_init();
  cub3D.mlx_win = mlx_new_window(cub3D.ptr_mlx, WIDTH,HEIGHT, "cub3d");
  cub3D.data.img =
      mlx_new_image(cub3D.ptr_mlx, WIDTH,HEIGHT);
  cub3D.data.addr = mlx_get_data_addr(cub3D.data.img, &cub3D.data.bits_per_pixel,
                                &cub3D.data.line_length, &cub3D.data.endian);
  hooks_handler(&cub3D);
  mlx_loop(cub3D.ptr_mlx);
  return 0;
}
