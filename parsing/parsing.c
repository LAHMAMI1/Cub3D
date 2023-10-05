#include "../includes/cub3D.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	init_player(t_cub3D *cub3D, int i, int j)
{
	cub3D->player.x = cub3D->map.player.y;
	cub3D->player.y = cub3D->map.player.x;
	cub3D->player.px = (cub3D->player.y * VECTOR) + ((double)VECTOR / 2);
	cub3D->player.py = (cub3D->player.x * VECTOR) + ((double)VECTOR / 2);
	cub3D->player.color = 0x64CCC5;
	if (cub3D->map.player_direction == 'N')
		cub3D->player.retation_angle = M_PI / 2;
	if (cub3D->map.player_direction == 'S')
		cub3D->player.retation_angle = 3 * (M_PI / 2);
	if (cub3D->map.player_direction == 'W')
		cub3D->player.retation_angle = M_PI;
	if (cub3D->map.player_direction == 'E')
		cub3D->player.retation_angle = 0;
	cub3D->player.retation_speed = 2 * (M_PI / 180);
	cub3D->player.speed = 0.7;
}

void	init_ray_params(t_cub3D *cub3D)
{
	cub3D->ray_params.fov_angle = 60 * (M_PI / 180);
	cub3D->ray_params.pix_per_colom = 5;
	cub3D->ray_params.rays_namber
		= (cub3D->map.width * VECTOR) / cub3D->ray_params.pix_per_colom;
}

void	init_data(t_cub3D *cub3D)
{
	ft_memset(&cub3D->player, 0, sizeof(t_player));
	init_player(cub3D, cub3D->map.player.y, cub3D->map.player.x);
	init_ray_params(cub3D);
}
