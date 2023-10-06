/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:08:27 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 15:52:21 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

int	key_up(int keycode, t_cub *cub3D)
{
	if (keycode == KEY_W || keycode == KEY_S)
		cub3D->player.dy = 0;
	if (keycode == KEY_D || keycode == KEY_A)
		cub3D->player.dw = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		cub3D->player.dx = 0;
	return (0);
}

int	key_down(int keycode, t_cub *cub3D)
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

void	draw_new_move(t_cub *cub3D)
{
	update_player_bonnus(cub3D);
	draw_player(cub3D);
	mlx_clear_window(cub3D->ptr_mlx, cub3D->mlx_win);
	mlx_put_image_to_window(cub3D->ptr_mlx, cub3D->mlx_win, cub3D->data.img, 0,
		0);
}

int	mouse_move(int x, int y, t_cub *cub3D)
{
	(void)y;
	cub3D->player.dx = (x - WIDTH / 2) * 0.1;
	mlx_mouse_move(cub3D->ptr_mlx, cub3D->mlx_win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

void	hooks_handler(t_cub *cub3D)
{
	mlx_loop_hook(cub3D->ptr_mlx, (void *)draw_new_move, cub3D);
	mlx_hook(cub3D->mlx_win, KeyPress, KeyPressMask, key_down, cub3D);
	mlx_hook(cub3D->mlx_win, KeyRelease, KeyReleaseMask, key_up, cub3D);
	mlx_hook(cub3D->mlx_win, MotionNotify, PointerMotionMask, mouse_move,
		cub3D);
	mlx_hook(cub3D->mlx_win, DestroyNotify, StructureNotifyMask,
		(void *)close_window, cub3D);
}
