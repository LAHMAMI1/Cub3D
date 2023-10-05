

#include "../includes/cub3D.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

void	free_map(t_cub3D *cub3D)
{
	int	i;

	i = 0;
	while (i < cub3D->map.height)
	{
		free(cub3D->map.map[i]);
		i++;
	}
	free(cub3D->map.map);
}
void	close_window(t_cub3D *cub3D)
{
	mlx_destroy_window(cub3D->ptr_mlx, cub3D->mlx_win);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->data.img);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->texture_SO.img);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->texture_NO.img);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->texture_WE.img);
	mlx_destroy_image(cub3D->ptr_mlx, cub3D->texture_EA.img);
	free_map(cub3D);
	exit(0);
}

int	key_up(int keycode, t_cub3D *cub3D)
{
	if (keycode == KEY_W || keycode == KEY_S)
		cub3D->player.dy = 0;
	if (keycode == KEY_D || keycode == KEY_A)
		cub3D->player.dw = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		cub3D->player.dx = 0;
	return (0);
}

int	square_is_wall(t_cub3D *cub3D, double i, double j)
{
	double	step;

	step = 8 / (double)VECTOR;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	i += step;
	j += step;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	j -= step * 2;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	i -= step * 2;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	j += step * 2;
	if (cub3D->map.map[(int)i][(int)j] == 1)
		return (1);
	return (0);
}

double	norm_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
void	update_move_speed(t_cub3D *cub3D, double *move_speed, double *angle)
{
	if (cub3D->player.dy)
	{
		*move_speed = cub3D->player.dy * 0.05;
		*angle = cub3D->player.retation_angle;
	}
	else if (cub3D->player.dw)
	{
		*move_speed = cub3D->player.dw * 0.05;
		*angle = cub3D->player.retation_angle + (3 * M_PI / 2);
	}
}
void	update_player(t_cub3D *cub3D)
{
	double	move_speed;
	double	i;
	double	j;
	double	angle;

	cub3D->player.retation_angle +=
		cub3D->player.dx * cub3D->player.retation_speed;
	cub3D->player.retation_angle = norm_angle(cub3D->player.retation_angle);
	update_move_speed(cub3D, &move_speed, &angle);
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

int	key_down(int keycode, t_cub3D *cub3D)
{
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
		close_window(cub3D);
	return (0);
}

void	draw_ray(t_cub3D *cub3D, t_ray ray)
{
	t_point	pt_1;
	t_point	pt_0;

	pt_0.y = cub3D->player.py;
	pt_0.x = cub3D->player.px;
	pt_0.color = 0x952323;
	pt_1.y = pt_0.y + sin(ray.ray_angle) * VECTOR;
	pt_1.x = pt_0.x + cos(ray.ray_angle) * VECTOR;
	pt_1.color = 0x952323;
	draw_line(*cub3D, pt_0, pt_1);
}

void	calcul_ray_params(t_cub3D *cub3D, t_ray *ray, double ray_angle)
{
	ray->ray_angle = norm_angle(ray_angle);
	ray->ray_facing_down = (ray->ray_angle > 0 && ray->ray_angle < M_PI);
	ray->ray_facing_up = !ray->ray_facing_down;
	ray->ray_facing_right =
		(ray->ray_angle < (0.5 * M_PI) || ray->ray_angle > (1.5 * M_PI));
	ray->ray_facing_left = !ray->ray_facing_right;
}

int	*ceiling_floor_buffering(t_cub3D *cub3D)
{
	int	*buffer;
	int	i;

	buffer = malloc(sizeof(int) * (WIDTH * HEIGHT));
	i = 0;
	while (i < (WIDTH * HEIGHT) / 2)
		buffer[i++] = cub3D->map.ceiling_color;
	while (i < WIDTH * HEIGHT)
		buffer[i++] = cub3D->map.floor_color;
	return (buffer);
}
t_data	set_texturs(t_cub3D *cub3D, double ra, int flag)
{
	if (flag == 1)
	{
		if (ra > 0 && ra < M_PI)
			return (cub3D->texture_SO);
		else
			return (cub3D->texture_NO);
	}
	else
	{
		if (ra > (0.5 * M_PI) && ra < (1.5 * M_PI))
			return (cub3D->texture_WE);
		else
			return (cub3D->texture_EA);
	}
}
void	calcul_ray_data(t_cub3D *cub3D, int *texture_x, int *texture_y)
{
	cub3D->ray_data.new_angle = cub3D->player.retation_angle
		- cub3D->ray_data.ra;
	cub3D->ray_data.final_distance *= cos(cub3D->ray_data.new_angle);
	cub3D->ray_data.line_h = (64 * WIDTH) / cub3D->ray_data.final_distance;
	cub3D->ray_data.top_pixel = ((double)HEIGHT / 2) - (cub3D->ray_data.line_h
			/ 2);
	cub3D->ray_data.bottom_pixel = ((double)HEIGHT / 2)
		+ (cub3D->ray_data.line_h / 2);
	if (cub3D->ray_data.top_pixel < 0)
		cub3D->ray_data.top_pixel = 0;
	if (cub3D->ray_data.bottom_pixel > HEIGHT)
		cub3D->ray_data.bottom_pixel = HEIGHT;
	if (cub3D->ray_data.ray_hit_h)
	{
		cub3D->ray_data.texture = set_texturs(cub3D, cub3D->ray_data.ra, 1);
		*texture_x = (int)cub3D->ray_data.inter_point.x % VECTOR;
	}
	else
	{
		cub3D->ray_data.texture = set_texturs(cub3D, cub3D->ray_data.ra, 0);
		*texture_x = (int)cub3D->ray_data.inter_point.y % VECTOR;
	}
}

void	check_h_v_intersection(t_cub3D *cub3D)
{
	t_point	h_inter;
	t_point	v_inter;
	double	h_distance;
	double	v_distance;

	h_distance = INT_MAX;
	v_distance = INT_MAX;
	h_inter = check_horizontal_intersection(cub3D, cub3D->ray_data.ra);
	h_distance = distance_between_points(cub3D->player.px, cub3D->player.py,
			h_inter.x, h_inter.y);
	v_inter = check_vertical_intersection(cub3D, cub3D->ray_data.ra);
	v_distance = distance_between_points(cub3D->player.px, cub3D->player.py,
			v_inter.x, v_inter.y);
	if (h_distance < v_distance)
	{
		cub3D->ray_data.inter_point = h_inter;
		cub3D->ray_data.final_distance = h_distance;
		cub3D->ray_data.ray_hit_h = 1;
	}
	else
	{
		cub3D->ray_data.inter_point = v_inter;
		cub3D->ray_data.final_distance = v_distance;
		cub3D->ray_data.ray_hit_h = 0;
	}
}
void	draw_3D(t_cub3D *cub3D, int *buffer)
{
	int	i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		((int *)cub3D->data.addr)[i] = buffer[i];
		i++;
	}
}

void	textures_buffering(t_cub3D *cub3D, int *buffer, int i)
{
	int	texture_x;
	int	texture_y;
	int	j;
	int	distance_from_top;

	check_h_v_intersection(cub3D);
	calcul_ray_data(cub3D, &texture_x, &texture_y);
	j = cub3D->ray_data.top_pixel;
	while (j < cub3D->ray_data.bottom_pixel)
	{
		distance_from_top = j + (cub3D->ray_data.line_h / 2) - (HEIGHT / 2);
		texture_y = distance_from_top * (cub3D->ray_data.texture.height
				/ cub3D->ray_data.line_h);
		buffer[j * WIDTH + i] = *(int *)(cub3D->ray_data.texture.addr
				+ (texture_y * cub3D->ray_data.texture.line_length) + texture_x
				* (cub3D->ray_data.texture.bits_per_pixel / 8));
		j++;
	}
}
void	draw_rays_2D(t_cub3D *cub3D)
{
	int	*buffer;
	int	i;

	cub3D->ray_data.ra = cub3D->player.retation_angle - DEGREE * 30;
	cub3D->ray_data.ra = norm_angle(cub3D->ray_data.ra);
	buffer = ceiling_floor_buffering(cub3D);
	i = 0;
	while (i < WIDTH)
	{
		textures_buffering(cub3D, buffer, i);
		i++;
		cub3D->ray_data.ra += (60.0 / WIDTH) * DEGREE;
		cub3D->ray_data.ra = norm_angle(cub3D->ray_data.ra);
	}
	draw_3D(cub3D, buffer);
	free(buffer);
}
void	draw_all_rays(t_cub3D *cub3D)
{
	int		i;
	t_ray	ray;
	double	ray_angle;
	t_point	horizontal_inter;
	t_point	vertical_inter;

	ray_angle =
		cub3D->player.retation_angle - ((double)cub3D->ray_params.fov_angle
				/ 2);
	i = 0;
	while (i < cub3D->ray_params.rays_namber)
	{
		ray_angle +=
			(double)cub3D->ray_params.fov_angle / cub3D->ray_params.rays_namber;
		if (i == cub3D->ray_params.rays_namber / 2)
		{
			calcul_ray_params(cub3D, &ray, ray_angle);
			draw_line(*cub3D, (t_point){cub3D->player.py, cub3D->player.px,
					0xAE445A}, (t_point){vertical_inter.x, vertical_inter.y,
					0x00FF00});
		}
		i++;
	}
}

void	draw_player_direction(t_cub3D *cub3D)
{
	t_point	pt_1;
	t_point	pt_0;

	pt_0.y = cub3D->player.py;
	pt_0.x = cub3D->player.px;
	pt_0.color = cub3D->player.color;
	pt_1.y = pt_0.y + sin(cub3D->player.retation_angle) * VECTOR;
	pt_1.x = pt_0.x + cos(cub3D->player.retation_angle) * VECTOR;
	pt_1.color = cub3D->player.color;
	draw_line(*cub3D, pt_0, pt_1);
}

void	draw_new_move(t_cub3D *cub3D)
{
	update_player(cub3D);
	draw_player(cub3D);
	mlx_clear_window(cub3D->ptr_mlx, cub3D->mlx_win);
	mlx_put_image_to_window(cub3D->ptr_mlx, cub3D->mlx_win, cub3D->data.img, 0,
			0);
}

int	mouse_move(int x, int y, t_cub3D *cub3D)
{
	(void)y;
	cub3D->player.dx = (x - WIDTH / 2) * 0.1;
	mlx_mouse_move(cub3D->ptr_mlx, cub3D->mlx_win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
void	hooks_handler(t_cub3D *cub3D)
{
	mlx_loop_hook(cub3D->ptr_mlx, (void *)draw_new_move, cub3D);
	mlx_hook(cub3D->mlx_win, KeyPress, KeyPressMask, key_down, cub3D);
	mlx_hook(cub3D->mlx_win, KeyRelease, KeyReleaseMask, key_up, cub3D);
	mlx_hook(cub3D->mlx_win, MotionNotify, PointerMotionMask, mouse_move,
			cub3D);
	mlx_hook(cub3D->mlx_win, DestroyNotify, StructureNotifyMask,
			(void *)close_window, cub3D);
}
