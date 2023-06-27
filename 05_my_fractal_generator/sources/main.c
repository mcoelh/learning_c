/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:58:08 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/02/15 22:55:51 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	start_process(t_img *f)
{
	f->init = mlx_init();
	f->win_id = mlx_new_window(f->init, W, H, "Fractol");
	f->img_id = mlx_new_image(f->init, W, H);
	f->pixels = mlx_get_data_addr(f->img_id, &f->bpp, &f->line_len, &f->endian);
}

int	check_julia(char *argv, t_img *f)
{
	if (ft_strncmp(argv, "julia1", 7) == 0)
	{
		f->ci = 0.156;
		f->cr = -0.8;
		return (1);
	}
	if (ft_strncmp(argv, "julia2", 7) == 0)
	{
		f->ci = 0.6;
		f->cr = -0.4;
		return (1);
	}
	if (ft_strncmp(argv, "julia3", 7) == 0)
	{
		f->ci = 0.01;
		f->cr = 0.285;
		return (1);
	}
	return (0);
}

int	check_args(char *argv, int argc, t_img *f)
{
	if (argc != 2)
	{
		ft_printf("Error!! Use ./fractol julia1 OR ./fractol julia2 OR" \
			" ./fractol julia3 OR ./fractol mandelbrot\n");
		exit(0);
	}
	put_lower(argv);
	if (ft_strncmp(argv, "mandelbrot", 11) == 0)
		return (1);
	else if (check_julia(argv, f) != 0)
		return (2);
	else
	{
		ft_printf("Error!! Use ./fractol julia1 OR ./fractol julia2 OR" \
			" ./fractol julia3 OR ./fractol mandelbrot\n");
		exit (0);
	}
	exit (0);
}

int	call_fractol(t_img *f)
{
	if (f->path == 2)
		render_julia(f);
	if (f->path == 1)
		render_mandelbrot(f);
	return (1);
}

int	main(int argc, char **argv)
{
	t_img	img;

	start_process(&img);
	img.path = check_args(argv[1], argc, &img);
	set_layout(&img);
	call_fractol(&img);
	mlx_key_hook(img.win_id, &check_keys, &img);
	mlx_hook(img.win_id, 17, 0, &close_win, &img);
	mlx_mouse_hook(img.win_id, &zoom_wheel, &img);
	mlx_loop(img.init);
	return (0);
}
