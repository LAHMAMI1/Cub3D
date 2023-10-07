/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:42:55 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/07 16:02:48 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <math.h>
# include <mlx.h>

typedef struct s_intesection_params
{
	double			x_intercept;
	double			y_intercept;
	double			x_step;
	double			y_step;
}					t_intesc_params;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
}					t_data;

typedef struct s_point
{
	int				x;
	int				y;
	int				color;
}					t_point;

typedef struct s_player
{
	double			x;
	double			y;
	int				px;
	int				py;
	double			dx;
	double			dy;
	double			dw;
	double			speed;
	double			retation_angle;
	double			retation_speed;
	int				color;
}					t_player;

typedef struct s_variables
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				error;
	int				e2;
}					t_vars;

typedef struct s_ray_params
{
	int				fov_angle;
	int				rays_namber;
	int				pix_per_colom;

}					t_ray_params;

typedef struct s_ray
{
	double			ray_angle;
	double			ray_hit_wall_x;
	double			ray_hit_wall_y;
	double			distance;
	int				ray_facing_up;
	int				ray_facing_down;
	int				ray_facing_left;
	int				ray_facing_right;
}					t_ray;

typedef struct s_map
{
	int				width;
	int				height;
	int				**map;
	t_point			player;
	char			player_direction;
	int				floor_color;
	int				ceiling_color;
	char			*n;
	char			*s;
	char			*w;
	char			*e;
}					t_map;

typedef struct s_parse
{
	int				fd;
	char			*argv;
	int				fd_empty;
	char			*str;
	char			**split_file;
	char			**split_identifier;
	char			**split_map;
	char			*arg_id;
	int				j;
	char			**nswe;
	char			**split_color;
	int				f_color;
	int				c_color;
	int				p;
	int				px;
	int				py;
	char			p_d;
	int				*count;
	int				error;
}					t_parse;
typedef struct s_ray_data
{
	double			new_angle;
	double			final_distance;
	double			line_h;
	double			ra;
	int				top_pixel;
	int				bottom_pixel;
	int				ray_hit_h;
	t_point			inter_point;
	t_data			texture;
}					t_ray_data;
typedef struct s_cub
{
	void			*ptr_mlx;
	void			*mlx_win;
	int				height;
	int				width;
	int				**points;
	t_player		player;
	t_player		mouse;
	t_data			data;
	t_data			texture_no;
	t_data			texture_so;
	t_data			texture_we;
	t_data			texture_ea;
	t_data			texture;
	t_ray_params	ray_params;
	t_map			map;
	t_ray_data		ray_data;
}					t_cub;
#endif