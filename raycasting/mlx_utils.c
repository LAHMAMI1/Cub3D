
#include "../includes/cub3D.h"



int	my_mlx_pixel_put(t_cub3D *cub3D, int x, int y, int color)
{
	char	*dst;

	dst = cub3D->data.addr + (y * cub3D->data.line_length + x * (cub3D->data.bits_per_pixel / 8));

	if ((x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT))
		return (-1);
	*(unsigned int*)dst = color;
	return 0;
}

