/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:01:15 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/02/15 20:39:31 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_keys(int key, t_img *f)
{
	if (key == 53)
	{
		mlx_destroy_image(f->init, f->img_id);
		mlx_destroy_window(f->init, f->win_id);
		exit(0);
	}
	return (0);
}

int	close_win(t_img *fractol)
{
	mlx_destroy_image(fractol->init, fractol->img_id);
	mlx_destroy_window(fractol->init, fractol->win_id);
	exit(0);
}

void	zoom(t_img *f, double zoom, int x, int y)
{
	f->old_i = f->ce_i + f->i_max + y * (f->i_min - f->i_max) / H * f->zoom;
	f->old_r = f->ce_r + f->r_min + x * (f->r_max - f->r_min) / W * f->zoom;
	f->zoom = f->zoom * zoom;
	f->new_i = f->ce_i + f->i_max + y * (f->i_min - f->i_max) / H * f->zoom;
	f->new_r = f->ce_r + f->r_min + x * (f->r_max - f->r_min) / W * f->zoom;
	f->ce_i += f->old_i - f->new_i;
	f->ce_r += f->old_r - f->new_r;
}

void	move_to_center(t_img *f, int x, int y)
{
	f->old_i = f->ce_i + f->i_max + y * (f->i_min - f->i_max) \
		/ H * f->zoom;
	f->old_r = f->ce_r + f->r_min + x * (f->r_max - f->r_min) \
		/ W * f->zoom;
	f->new_i = f->ce_i + f->i_max + H / 2 * (f->i_min - f->i_max) \
		/ H * f->zoom;
	f->new_r = f->ce_r + f->r_min + W / 2 * (f->r_max - f->r_min) \
		/ W * f->zoom;
	f->ce_i += f->old_i - f->new_i;
	f->ce_r += f->old_r - f->new_r;
}

int	zoom_wheel(int key, int x, int y, t_img *f)
{
	if (key == 1)
		move_to_center(f, x, y);
	if (key == 2)
		set_layout(f);
	if (key == 4)
		zoom(f, 0.9, x, y);
	if (key == 5)
		zoom(f, 1.1, x, y);
	call_fractol(f);
	return (0);
}
