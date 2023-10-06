/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:35:42 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/06 15:42:25 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"
#include "libft/libft.h"
#include <stdio.h>

void	init_texturs_so_no(t_cub3D *cub3D)
{
	cub3D->texture_SO.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, cub3D->map.s,
			&cub3D->texture_SO.width, &cub3D->texture_SO.height);
	if (!cub3D->texture_SO.img)
	{
		printf("cant load SO texture\n");
		free_map(cub3D);
		exit(1);
	}
	cub3D->texture_SO.addr = mlx_get_data_addr(cub3D->texture_SO.img,
			&cub3D->texture_SO.bits_per_pixel,
			&cub3D->texture_SO.line_length,
			&cub3D->texture_SO.endian);
	cub3D->texture_NO.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, cub3D->map.n,
			&cub3D->texture_NO.width, &cub3D->texture_NO.height);
	if (!cub3D->texture_NO.img)
	{
		printf("cant load NO texture\n");
		free_map(cub3D);
		exit(1);
	}
	cub3D->texture_NO.addr = mlx_get_data_addr(cub3D->texture_NO.img,
			&cub3D->texture_NO.bits_per_pixel,
			&cub3D->texture_NO.line_length,
			&cub3D->texture_NO.endian);
}

void	init_texturs_we_ea(t_cub3D *cub3D)
{
	cub3D->texture_WE.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, cub3D->map.w,
			&cub3D->texture_WE.width, &cub3D->texture_WE.height);
	if (!cub3D->texture_WE.img)
	{
		printf("cant load WE texture\n");
		free_map(cub3D);
		exit(1);
	}
	cub3D->texture_WE.addr = mlx_get_data_addr(cub3D->texture_WE.img,
			&cub3D->texture_WE.bits_per_pixel,
			&cub3D->texture_WE.line_length,
			&cub3D->texture_WE.endian);
	cub3D->texture_EA.img = mlx_xpm_file_to_image(cub3D->ptr_mlx, cub3D->map.e,
			&cub3D->texture_EA.width, &cub3D->texture_EA.height);
	if (!cub3D->texture_EA.img)
	{
		printf("cant load EA texture\n");
		free_map(cub3D);
		exit(1);
	}
	cub3D->texture_EA.addr = mlx_get_data_addr(cub3D->texture_EA.img,
			&cub3D->texture_EA.bits_per_pixel,
			&cub3D->texture_EA.line_length,
			&cub3D->texture_EA.endian);
}

void	init_texturs(t_cub3D *cub3D)
{
	init_texturs_so_no(cub3D);
	init_texturs_we_ea(cub3D);
}

int	main(int argc, char *argv[])
{
	t_cub3D	cub;
	t_parse	*parse;

	parse = malloc(sizeof(t_parse));
	check_all(parse, argc, argv);
	init_s_map(&cub, parse);
	print_arg_map(&cub);
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
