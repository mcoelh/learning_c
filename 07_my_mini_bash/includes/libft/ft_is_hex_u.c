/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_hex_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:56:42 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/18 16:13:30 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n);
static void	ft_is_hex_upper(unsigned int n, int fd);

int	ft_is_hex_u(va_list arg, int fd)
{
	unsigned int	i;
	int				len;

	len = 0;
	i = va_arg(arg, unsigned int);
	if (i == 0)
		write (fd, "0", 1);
	else
		ft_is_hex_upper(i, fd);
	len = len + ft_count(i);
	return (len);
}

static int	ft_count(unsigned int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

static void	ft_is_hex_upper(unsigned int n, int fd)
{
	unsigned int	r;

	if (n >= 16)
	{
		ft_is_hex_upper(n / 16, fd);
	}
	r = n % 16;
	if (r <= 9)
		ft_print_char(r + '0', fd);
	if (r > 9 && r <= 15)
		ft_print_char(r + '7', fd);
}
