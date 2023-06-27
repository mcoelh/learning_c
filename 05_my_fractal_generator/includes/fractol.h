/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:38:01 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/02/15 22:52:46 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../includes/mlx/mlx.h"
# include "../includes/libft/libft.h"
# include "../includes/libft/ft_printf.h"
# define W 600
# define H 600
# define MAX_ITERATIONS 100

typedef struct s_img
{
	void	*init;
	void	*win_id;
	void	*img_id;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
	int		x;
	int		y;
	double	cr;
	double	ci;
	double	z_r;
	double	z_i;
	double	r_max;
	double	r_min;
	double	i_max;
	double	i_min;
	double	zoom;
	double	ce_r;
	double	ce_i;
	double	old_i;
	double	new_i;
	double	old_r;
	double	new_r;
	int		path;
}				t_img;

void	set_layout(t_img *f);
void	render_mandelbrot(t_img *f);
void	mandelbrot(t_img *f);
void	set_color(int iterations, t_img *f);
void	my_mlx_pixel_put(t_img *data, int coluna, int linha, int color);
void	render_julia(t_img *f);
void	julia(t_img *f);
int		check_keys(int key, t_img *f);
int		close_win(t_img *f);
void	set_julia(t_img *f);
int		zoom_wheel(int key, int x, int y, t_img *f);
int		call_fractol(t_img *f);
void	put_lower(char *str);
#endif