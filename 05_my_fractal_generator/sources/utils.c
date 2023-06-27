/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:31:59 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/02/15 21:52:29 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *data, int coluna, int linha, int color)
{
	char	*dst;

	dst = data->pixels + (linha * data->line_len + coluna * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	set_color(int iterations, t_img *f)
{
	my_mlx_pixel_put(f, f->x, f->y, (0x00F0F8FF * (iterations)));
}

void	put_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}
