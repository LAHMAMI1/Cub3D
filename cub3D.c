/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:35:42 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 21:51:45 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"
#include "libft/libft.h"
#include <stdio.h>

void	init_texturs_so_no(t_cub *cub3D)
{
	cub3D->texture_so.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, cub3D->map.s,
			&cub3D->texture_so.width, &cub3D->texture_so.height);
	if (!cub3D->texture_so.img)
	{
		printf("cant load SO texture\n");
		free_map(cub3D);
		exit(1);
	}
	cub3D->texture_so.addr = mlx_get_data_addr(cub3D->texture_so.img,
			&cub3D->texture_so.bits_per_pixel,
			&cub3D->texture_so.line_length,
			&cub3D->texture_so.endian);
	cub3D->texture_no.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, cub3D->map.n,
			&cub3D->texture_no.width, &cub3D->texture_no.height);
	if (!cub3D->texture_no.img)
	{
		printf("cant load NO texture\n");
		free_map(cub3D);
		exit(1);
	}
	cub3D->texture_no.addr = mlx_get_data_addr(cub3D->texture_no.img,
			&cub3D->texture_no.bits_per_pixel,
			&cub3D->texture_no.line_length,
			&cub3D->texture_no.endian);
}

void	init_texturs_we_ea(t_cub *cub3D)
{
	cub3D->texture_we.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, cub3D->map.w,
			&cub3D->texture_we.width, &cub3D->texture_we.height);
	if (!cub3D->texture_we.img)
	{
		printf("cant load WE texture\n");
		free_map(cub3D);
		exit(1);
	}
	cub3D->texture_we.addr = mlx_get_data_addr(cub3D->texture_we.img,
			&cub3D->texture_we.bits_per_pixel,
			&cub3D->texture_we.line_length,
			&cub3D->texture_we.endian);
	cub3D->texture_ea.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, cub3D->map.e,
			&cub3D->texture_ea.width, &cub3D->texture_ea.height);
	if (!cub3D->texture_ea.img)
	{
		printf("cant load EA texture\n");
		free_map(cub3D);
		exit(1);
	}
	cub3D->texture_ea.addr = mlx_get_data_addr(cub3D->texture_ea.img,
			&cub3D->texture_ea.bits_per_pixel,
			&cub3D->texture_ea.line_length,
			&cub3D->texture_ea.endian);
}

void	init_texturs(t_cub *cub3D)
{
	init_texturs_so_no(cub3D);
	init_texturs_we_ea(cub3D);
}

int	main(int argc, char *argv[])
{
	t_cub	cub;
	t_parse	*parse;

	parse = malloc(sizeof(t_parse));
	check_all(parse, argc, argv);
	init_s_map(&cub, parse);
	init_data(&cub);
	cub.ptr_mlx = mlx_init();
	init_texturs(&cub);
	cub.mlx_win = mlx_new_window(cub.ptr_mlx, WIDTH, HEIGHT, "cub3d");
	cub.data.img
		= mlx_new_image(cub.ptr_mlx, WIDTH, HEIGHT);
	cub.data.addr = mlx_get_data_addr(cub.data.img,
			&cub.data.bits_per_pixel,
			&cub.data.line_length,
			&cub.data.endian);
	hooks_handler(&cub);
	mlx_loop(cub.ptr_mlx);
	return (0);
}
