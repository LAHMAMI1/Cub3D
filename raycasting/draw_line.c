

#include "../includes/cub3D.h"

static t_vars	vars_init(t_point pt0, t_point pt1)
{
	t_vars	var;

	var.dx = abs(pt1.x - pt0.x);
	var.sx = (pt0.x < pt1.x) * 2 - 1;
	var.dy = -abs(pt1.y - pt0.y);
	var.sy = (pt0.y < pt1.y) * 2 - 1;
	var.error = var.dx + var.dy;
	return (var);
}

void	draw_line(t_cub3D cub3D, t_point pt_0, t_point pt_1)
{
	t_vars	var;

	var = vars_init(pt_0, pt_1);
	while (1)
	{
		my_mlx_pixel_put(&cub3D, pt_0.x, pt_0.y, pt_0.color);
		if (pt_0.x == pt_1.x && pt_0.y == pt_1.y)
			break ;
		var.e2 = 2 * var.error;
		if (var.e2 >= var.dy && pt_0.x == pt_1.x)
			break ;
		if (var.e2 >= var.dy)
			var.error = var.error + var.dy;
		if (var.e2 >= var.dy)
			pt_0.x = pt_0.x + var.sx;
		if (var.e2 <= var.dx && pt_0.y == pt_1.y)
			break ;
		if (var.e2 <= var.dx)
			var.error = var.error + var.dx;
		if (var.e2 <= var.dx)
			pt_0.y = pt_0.y + var.sy;
	}
}
