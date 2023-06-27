/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:51:04 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/02/15 22:28:46 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_img *f)
{
	int		iterations;
	double	temp;

	iterations = 0;
	while (iterations < MAX_ITERATIONS)
	{
		temp = ((2 * f->z_r * f->z_i) + f->ci);
		f->z_r = ((f->z_r * f->z_r) - (f->z_i * f->z_i) + f->cr);
		f->z_i = temp;
		if ((f->z_r * f->z_r) + (f->z_i * f->z_i) > 4.0)
		{
			set_color(iterations, f);
			break ;
		}
		else
			my_mlx_pixel_put(f, f->x, f->y, 0x000000);
		iterations++;
	}
}

void	render_julia(t_img *f)
{
	mlx_clear_window(f->init, f->win_id);
	f->y = 0;
	while (f->y < H)
	{
		f->x = 0;
		while (f->x < W)
		{
			f->z_r = f->ce_r + f->r_min + (double)f->x * (f->r_max - f->r_min) \
				/ W * f->zoom;
			f->z_i = f->ce_i + f->i_max + (double)f->y * (f->i_min - f->i_max) \
				/ H * f->zoom;
			julia(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->init, f->win_id, f->img_id, 0, 0);
}
